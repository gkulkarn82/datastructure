#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

// #include<bits/stdc++.h>
// using namespace std;
#define BUFFER 1024
#define PORT 1100


std::unordered_map<std::string, std::string> umapInMem;
std::mutex mu;  


std::string request_get(const std::string& key) {
    std::lock_guard<std::mutex> lock(mu);
    auto it = umapInMem.find(key);
    if (it != umapInMem.end()) {
        return it->second;
    } else {
        return "key missing or not found";
    }
}


void request_put(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mu);
    umapInMem[key] = value;
}


void handleClient(int clntsoc) {
    char buffer[BUFFER];
    ssize_t bytesRead = recv(clntsoc, buffer, sizeof(buffer), 0);
    if (bytesRead <= 0) {
        close(clntsoc);
        return;
    }

    
    buffer[bytesRead] = '\0'; 
    std::string request(buffer);

    //form a command by reading param
    std::istringstream iss(request);
    std::string command, key, value;
    iss >> command >> key >> value;

    
    std::string response;
    if (command == "GET") 
    {
        response = request_get(key);
    } 
    else if (command == "PUT") 
    {
        request_put(key, value);
        response = "put requesr processed successfully";
    } 
    else 
    {
        response = "Invalid request. try again !!!";
    }

    
    send(clntsoc, response.c_str(), response.size(), 0);
    close(clntsoc);
}

int main() {
   

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "socket creation failed" << std::endl;
        return 1;
    }
    
    sockaddr_in srvAddr{};
    srvAddr.sin_family = AF_INET;
    srvAddr.sin_port = htons(PORT); 
    srvAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, reinterpret_cast<sockaddr*>(&srvAddr), sizeof(srvAddr)) == -1) {
        std::cerr << "socket binding failed" << std::endl;
        close(serverSocket);
        return 1;
    }


    if (listen(serverSocket, 5) == -1) {
        std::cerr << "socket listning failed" << std::endl;
        close(serverSocket);
        return 1;
    }

    std::cout << "server listening on port " << PORT << " ..." << std::endl;

    // Accept and handle incoming connections in separate threads
    while (true) {
        sockaddr_in srvAddr{};
        socklen_t clntAddrLen = sizeof(srvAddr);

        int clientSocket = accept(serverSocket, reinterpret_cast<sockaddr*>(&srvAddr), &clntAddrLen);
        if (clientSocket == -1) {
            std::cerr << "connection accept failed" << std::endl;
            continue;
        }

        // Handle the client request in a separate thread
        /*
            I could think of one improvement of preparing a ThreadPool to handle the requests
            that way we can have lead to utilising minimum resources instead of infinite one 
            leading to avoid cpu bound operations

            Other part may be using some kind of library for better handling of multiple connection

            
        */
        std::thread(handleClient, clientSocket).detach();
    }
    close(serverSocket);

    return 0;
}
