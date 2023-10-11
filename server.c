#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Binding failed");
        close(server_socket);
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Listening failed");
        close(server_socket);
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    socklen_t client_address_len = sizeof(client_address);

    // Accept incoming connections
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
    if (client_socket == -1) {
        perror("Accepting connection failed");
        close(server_socket);
        exit(1);
    }

    printf("Connection established with client\n");

    while (1) {
        // Receive data from the client
        ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break; // Connection closed or error
        }

        buffer[bytes_received] = '\0'; // Null-terminate the received data
        printf("Received: %s\n", buffer);

        // Send the received data back to the client
        send(client_socket, buffer, strlen(buffer), 0);
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    printf("Server closed\n");

    return 0;
}
