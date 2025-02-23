#include <iostream>
#include <thread>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>

class Client {
public:
    Client(const std::string &host, int port) {
        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocket < 0) {
            perror("Failed to create socket");
            exit(1);
        }

        sockaddr_in serverAddr {};
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = inet_addr(host.c_str());
        serverAddr.sin_port = htons(port);

        if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
            perror("Connection failed");
            exit(1);
        }
    }

    ~Client() {
        close(clientSocket);
    }

    void sendMessage(const std::string &message) {
        send(clientSocket, message.c_str(), message.size(), 0);

        char buffer[1024];
        ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead > 0) {
            std::cout << "Received from server: " << std::string(buffer, bytesRead) << std::endl;
        }
    }

private:
    int clientSocket;
};

int main() {
    Client client("127.0.0.1", 8080);
    client.sendMessage("Hello, Server!");
    return 0;
}
