#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8081

int main() {
    int sock;
    struct sockaddr_in server;
    int message;

    // Socket erstellen
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Could not create socket\n";
        return 1;
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Verbindung zum Server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        std::cerr << "Connect failed\n";
        return 1;
    }

    std::cout << "Connected\n";

    // Nachricht eingeben und senden
    std::cout << "Enter a Number: ";
    std::cin >> message;
    if (send(sock, &message, sizeof(message), 0) < 0) {
        std::cerr << "Send failed\n";
        return 1;
    }

    std::cout << "Closing connection...\n";
    close(sock);

    return 0;
}
