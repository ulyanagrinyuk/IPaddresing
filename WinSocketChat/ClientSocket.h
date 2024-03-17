#pragma once
#include"ServerSocket.h"

class ClientSocket :public Socket
{
public:
	ClientSocket(string username):Socket(username){}
	void ConnectionToServer(const char ip[], int port);
};
