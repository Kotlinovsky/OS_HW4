#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <csignal>
#include "../common/tools/Network.hpp"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: ./monitor <server_host> <server_port>";
        return 1;
    }

    // Читаем данные из аргументов команды.
    std::string server_host = argv[1];
    int server_port = std::stoi(argv[2]);

    // Опишем адрес сервера в структуре.
    struct sockaddr_in serv_addr{0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(server_host.data());
    serv_addr.sin_port = htons(server_port);

    // Выделим сокет для соединения с сервером.
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error during socket opening!";
        return 1;
    }

    while (true) {
        std::string req_state_msg(1, 0);
        std::string state_resp_msg(4 * sizeof(uint32_t), 0);
        writeByteToBuffer(req_state_msg, 0, 3);
        sendto(sockfd, req_state_msg.data(), req_state_msg.size(), MSG_CONFIRM, (const struct sockaddr *) &serv_addr,
               sizeof(serv_addr));

        if (recvfrom(sockfd, state_resp_msg.data(), state_resp_msg.size(), MSG_WAITALL, nullptr, nullptr) <= 0) {
            std::cerr << "Error during message receiving!";
            break;
        }

        uint32_t single_rooms_busied = readUInt32FromBuffer(state_resp_msg, 0);
        uint32_t single_rooms_total = readUInt32FromBuffer(state_resp_msg, 4);
        uint32_t double_rooms_busied = readUInt32FromBuffer(state_resp_msg, 8);
        uint32_t double_rooms_total = readUInt32FromBuffer(state_resp_msg, 12);

        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Single rooms: " << single_rooms_busied << "/" << single_rooms_total << std::endl;
        std::cout << "Double rooms: " << double_rooms_busied << "/" << double_rooms_total << std::endl;
        std::cout << "Total rooms: " << single_rooms_busied + double_rooms_busied << "/"
                  << single_rooms_total + double_rooms_total << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        sleep(2);
    }

    close(sockfd);
    return 0;
}
