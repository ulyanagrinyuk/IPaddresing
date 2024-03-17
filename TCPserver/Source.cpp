#include<iostream>
#include<WS2tcpip.h> 
#include<WinSock2.h> 

#pragma comment(lib, "WS2_32.lib")

using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	SOCKET _socket; 
	sockaddr_in addr; 

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	addr.sin_family = AF_INET;
	inet_pton(AF_INET, "0.0.0.0", &addr.sin_addr);
	addr.sin_port = htons(20000);
	bind(_socket, (SOCKADDR*)&addr, sizeof(addr));
	listen(_socket, 1);
	cout << "Server started" << endl;

	
	SOCKET accept_socket = accept(_socket, NULL, NULL);
	const int MAXSTRLEN = 255;
	char buffer[MAXSTRLEN] = {};
	int i = recv(accept_socket, buffer, MAXSTRLEN, 0);
	cout << buffer << endl;
	const char text[] = "Hello from Server!";
	send(accept_socket, text, strlen(text), 0);

	closesocket(accept_socket);
	closesocket(_socket);

	WSACleanup();
	system("PAUSE");
}