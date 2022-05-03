#define _WINSOCK_DEPRECIATED_NO_WARNINGS
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(int argc, char* argv[])

{
	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
	char* message, server_reploy[50000];
	int recv_size;
	//Inintialize Winsock
	printf("Initalizing Winsock...");
	if WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		{
		printf("\nFailed. Error Code : %d", WSAGetLastError());
		return 1;
		}
	printf(Initalized..."");
	//Create socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("\nCould not create socket : % d", WSAGetLastError());
	}
	printf("\nSocket Created.\n");
	server.sin_addr.s_addr = inet_addr("137.152.22.189");
	server.sin_family = AF_INET;
	server.sin_port = htons(80);
	//Connect to remote server
	if connect(s, (struct sockaddr*)&server, sizeof(server)) < 0)
		{
		puts("Connect error");
		return 1;
}
	puts("Connected");

	//Send data
	message = "GET / HTTP/1.1\r\nHost: gcu.edu\r\n\r\n";
	if (send(s, message, strlen(message), 0) < 0)
	{
		puts("\nSend Failed");
		return 1'
	}
	puts("Data Send\n ");
	// Recieve Reploy
	if ((recv_size = recv(s, server_reply, 50000, 0)) == SOCKET_ERROR)
	{
		puts("\nRnevc failed");
	}
	puts("Reply Recieved\n");

	//Null Term - proper string
	server_reply[recv_size] = '\0';
	puts(server_reply);

	return 0

}

