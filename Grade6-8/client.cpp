#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "../common/Client.hpp"
#include "../common/tools/Network.hpp"

void onTerminateProgram([[maybe_unused]] int sig) {
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cout << "Usage: ./client <id> <gender> <time> <server_host> <server_port>";
        return 1;
    }

    // Читаем данные из аргументов команды.
    uint32_t client_id = std::stoi(argv[1]);
    Client client = std::string(argv[2]) == "WOMAN" ? WOMAN : MAN;
    time_t rent_time_in_seconds = std::stol(argv[3]);
    std::string server_host = argv[4];
    int server_port = std::stoi(argv[5]);

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

    // Соединимся с сервером отеля.
    // Отправим сообщение серверу.
    std::string welcome_msg(sizeof(char) + sizeof(uint32_t) * 2, 0);
    writeByteToBuffer(welcome_msg, 0, 1);
    writeUInt32ToBuffer(welcome_msg, 1, client_id);
    writeUInt32ToBuffer(welcome_msg, 5, client);
    sendto(sockfd, welcome_msg.data(), welcome_msg.size(), MSG_CONFIRM, (const struct sockaddr *) &serv_addr,
           sizeof(serv_addr));

    // Выведем небольшое информационное сообщение с информацией о клиенте.
    std::cout << "[CLIENT] Client_id = " << client_id << "; client = " << client << "; rent_time = "
              << rent_time_in_seconds
              << std::endl << "[CLIENT] Notifying hotel ..."
              << std::endl;
    std::cout << "[CLIENT] Waiting hotel response ..." << std::endl;

    // Дождемся ответа от сервера. Он должен вернуть результат бронирования.
    std::string welcome_resp_msg(1, 0);
    if (recvfrom(sockfd, welcome_resp_msg.data(), welcome_resp_msg.size(), MSG_WAITALL, nullptr, nullptr) <= 0) {
        std::cerr << "Error during welcome message response receiving!";
        return 1;
    } else if (welcome_resp_msg[0] == 1) {
        std::cout << "[CLIENT] Out of service!" << std::endl;
        close(sockfd);
        return 0;
    } else if (welcome_resp_msg[0] != 0) {
        std::cerr << "Invalid welcome message response!";
        return 1;
    }

    // И теперь весим все время аренды.
    std::cout << "[CLIENT] Successfully rent! Waiting " << rent_time_in_seconds << "seconds ..." << std::endl;
    signal(SIGTERM, onTerminateProgram);
    sleep(rent_time_in_seconds);

    // После чего отправим сообщение на сервер о закрытии соединения.
    std::string close_msg(1, 0);
    writeByteToBuffer(close_msg, 0, 2);
    sendto(sockfd, close_msg.data(), close_msg.size(), MSG_CONFIRM, (const struct sockaddr *) &serv_addr,
           sizeof(serv_addr));

    std::cout << "[CLIENT] Rent done!" << std::endl;
    close(sockfd);
    return 0;
}
