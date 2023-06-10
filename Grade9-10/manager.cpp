#include <string>
#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
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

    // Слушаем команды от пользователя.
    while (true) {
        std::string command;
        if (!(std::cin >> command)) {
            break;
        }

        if (command == "close_server") {
            std::cout << "[MANAGER] Closing server ..." << std::endl;
            std::string close_server_msg(1, 0);
            writeByteToBuffer(close_server_msg, 0, 4);
            sendto(sockfd, close_server_msg.data(), close_server_msg.size(), MSG_CONFIRM,
                   (const struct sockaddr *) &serv_addr, sizeof(serv_addr));
            break;
        } else if (command == "disconnect_client") {
            uint32_t client_id;
            std::cin >> client_id;
            std::cout << "[MANAGER] Disconnecting client with id = " << client_id << std::endl;
            std::string disconnect_client_msg(sizeof(char) + sizeof(uint32_t), 0);
            writeByteToBuffer(disconnect_client_msg, 0, 5);
            writeUInt32ToBuffer(disconnect_client_msg, 1, client_id);
            sendto(sockfd, disconnect_client_msg.data(), disconnect_client_msg.size(), MSG_CONFIRM,
                   (const struct sockaddr *) &serv_addr, sizeof(serv_addr));
            continue;
        }

        std::cout << "[MANAGER] Command not exists!";
    }

    return 0;
}