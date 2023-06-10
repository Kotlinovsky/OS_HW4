#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <map>
#include "../common/Client.hpp"
#include "../common/tools/Network.hpp"
#include "../common/Hotel.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "./server <port>";
        return 1;
    }

    // Создадим структуру с описанием выделяемого адреса для сервера.
    int port = std::stoi(argv[1]);
    struct sockaddr_in serv_addr{0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    // Выделим сокет для нашего сервера.
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error during socket opening!";
        return 1;
    }

    // Забиндим сокет для сервера.
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Error during socket binding!";
        return 1;
    }

    struct sockaddr_in client_addr{0};
    std::string client_buffer(65535, 0);
    std::string client_address_str(255, 0);
    std::map<std::pair<std::string, int>, std::tuple<uint32_t, Client, Room *>> clients;
    socklen_t client_length = sizeof(client_addr);
    ssize_t client_buffer_length;
    Hotel hotel(10, 15);

    while ((client_buffer_length = recvfrom(sockfd, client_buffer.data(), client_buffer.size(), MSG_WAITALL,
                                            (struct sockaddr *) &client_addr,
                                            &client_length)) >= 0) {
        uint8_t pkg_id = client_buffer[0];
        inet_ntop(AF_INET, (struct sockaddr_in *) &client_addr.sin_addr, client_address_str.data(), 255);
        std::cout << "[SERVER] Received packet_id = " << (int) pkg_id << ", length = " << client_buffer_length
                  << std::endl;

        // Пакет 1: аренда номера.
        if (pkg_id == 1) {
            uint32_t client_id = readUInt32FromBuffer(client_buffer, 1);
            auto client = static_cast<Client>(readUInt32FromBuffer(client_buffer, 5));
            std::cout << "[SERVER] Connected client, id = " << client_id << "; client = " << client << std::endl;

            // Выделяем комнату для клиента.
            Room *room = hotel.serviceClient(client);
            if (room == nullptr) {
                std::string close_msg(1, 0);
                writeByteToBuffer(close_msg, 0, 1);
                sendto(sockfd, close_msg.data(), close_msg.size(), MSG_CONFIRM, (const struct sockaddr *) &client_addr,
                       sizeof(client_addr));
                std::cout << "[SERVER] Out of service: client_id = " << client_id << std::endl;
                continue;
            }

            std::string rent_msg(1, 0);
            writeByteToBuffer(rent_msg, 0, 0);
            clients[std::make_pair(client_address_str, client_addr.sin_port)] = std::make_tuple(client_id, client,
                                                                                                room);
            sendto(sockfd, rent_msg.data(), rent_msg.size(), MSG_CONFIRM, (const struct sockaddr *) &client_addr,
                   sizeof(client_addr));
            std::cout << "[SERVER] Rent started: client_id = " << client_id << std::endl;
            continue;
        }

        // Пакет 2: выселение из комнаты.
        if (pkg_id == 2) {
            auto address_pair = std::make_pair(client_address_str, client_addr.sin_port);
            auto client = clients[address_pair];
            uint32_t client_id = std::get<0>(client);
            Room *room = std::get<2>(client);

            // Выводим сообщение и освобождаем комнату.
            std::cout << "[SERVER] Rent done: client_id = " << client_id << std::endl;
            clients.erase(address_pair);
            room->removeOne();
            continue;
        }

        // Пакет 3: запрос состояния отеля.
        if (pkg_id == 3) {
            std::cout << "[SERVER] Requested state info" << std::endl;
            std::pair<uint32_t, uint32_t> busied = hotel.busiedRooms();
            std::pair<uint32_t, uint32_t> total = hotel.totalRooms();
            std::string state_resp_msg(4 * sizeof(uint32_t), 0);
            writeUInt32ToBuffer(state_resp_msg, 0, busied.first);
            writeUInt32ToBuffer(state_resp_msg, 4, total.first);
            writeUInt32ToBuffer(state_resp_msg, 8, busied.second);
            writeUInt32ToBuffer(state_resp_msg, 12, total.second);
            sendto(sockfd, state_resp_msg.data(), state_resp_msg.size(), MSG_CONFIRM,
                   (const struct sockaddr *) &client_addr, sizeof(client_addr));
            continue;
        }
    }

    close(sockfd);
    return 0;
}
