#include <winsock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET s, new_socket;
    struct sockaddr_in server, client;
    int c;
    char buffer;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed. Error Code : %d\n", WSAGetLastError());
        return 1;
    }

    // Create socket
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Prepare server info
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    // Bind
    if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Bind failed : %d\n", WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return 1;
    }

    // Listen
    listen(s, 3);

    printf("Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);

    new_socket = accept(s, (struct sockaddr *)&client, &c);
    if (new_socket == INVALID_SOCKET) {
        printf("accept failed: %d\n", WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return 1;
    }

    printf("Connection accepted\n");

    // Receive data
    int recv_size = recv(new_socket, buffer, sizeof(buffer) - 1, 0);
    if(recv_size > 0) {
        buffer[recv_size] = '\0';
        printf("Received: %s\n", buffer);
    } else {
        printf("recv failed or connection closed\n");
    }

    // Send reply
    char *message = "Hello from server";
    send(new_socket, message, strlen(message), 0);

    closesocket(new_socket);
    closesocket(s);
    WSACleanup();
    return 0;
}
