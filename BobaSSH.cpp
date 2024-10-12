#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <limits>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Socket creation failed.\n";
        return -1;
    }

    // Server address setup
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connection to server failed.\n";
        return -1;
    }

     std::cout << "Connected to server...";

    char buffer[BUFFER_SIZE];

    // Authentication
    std::string username, password;

    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    send(sockfd, username.c_str(), username.length(), 0);

    std::cout << "Enter password: ";
    std::getline(std::cin, password);
    send(sockfd, password.c_str(), password.length(), 0);

    memset(buffer, 0, BUFFER_SIZE);  // Clear the buffer
    recv(sockfd, buffer, BUFFER_SIZE, 0);  // Receive authentication result
    std::cout << buffer << std::endl;  // Print result

    // Command loop
    while (true) {
        std::cout << "Enter command (or 'exit' to quit): ";

        // Using a temporary string to handle command input
        std::string command;
        std::getline(std::cin, command);  // Capture command input

        std::cout << "user entered " << command << std::endl;

        // Check for exit command
        if (command == "exit") {
            // Inform server before closing the socket
             std::cout << "Disconnecting from server" << command << std::endl;
            send(sockfd, "DISCONNECT", strlen("DISCONNECT"), 0); // Sending disconnect command
            break; // Exit the loop
        }
         std::cout << "sending to server " << command << std::endl;
        // Send command to the server
        send(sockfd, command.c_str(), command.length(), 0);

        // Receive server output for the command
        memset(buffer, 0, BUFFER_SIZE);  // Clear the buffer before receiving
        ssize_t bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';  // Null-terminate the buffer
            std::cout << "Output:\n" << buffer << std::endl;
        } else {
            std::cerr << "Error receiving data from server.\n";
            break;
        }
    }

    close(sockfd);
    return 0;
}
