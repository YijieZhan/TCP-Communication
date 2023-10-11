#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 12345
#define MAX_BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_address.sin_port = htons(PORT);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Connection failed");
        close(client_socket);
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        // Send data to the server
        printf("Enter a message (or 'exit' to quit): ");
        fgets(buffer, sizeof(buffer), stdin);

        // Send the message to the server
        send(client_socket, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        // Receive and display the server's response
        ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break; // Connection closed or error
        }

        buffer[bytes_received] = '\0'; // Null-terminate the received data
        printf("Received from server: %s\n", buffer);
    }

    // Close the socket
    close(client_socket);

    printf("Client closed\n");

    return 0;
}
