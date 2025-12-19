#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char *message;
    char server_reply;
    int recv_size;

    printf("Initialising Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed. Error Code : %d\n", WSAGetLastError());
        return 1;
    }

    // Create socket
    if((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Prepare server info
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address
    server.sin_family = AF_INET;
    server.sin_port = htons(8080); // Server port

    // Connect to server
    if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connect error\n");
        closesocket(s);
        WSACleanup();
        return 1;
    }
    printf("Connected\n");

    // Send data
    message = "Hello from client";
    if (send(s, message, strlen(message), 0) < 0) {
        printf("Send failed\n");
        closesocket(s);
        WSACleanup();
        return 1;
    }

    // Receive reply
    recv_size = recv(s, server_reply, sizeof(server_reply) - 1, 0);
    if (recv_size > 0) {
        server_reply[recv_size] = '\0';
        printf("Server reply: %s\n", server_reply);
    } else if (recv_size == 0) {
        printf("Connection closed by server\n");
    } else {
        printf("recv failed\n");
    }

    closesocket(s);
    WSACleanup();
    return 0;
}
