#pragma once
#include"ServerSocket.h"

class ClientSocket :public Socket
{
public:
	void ConnectionToServer(const char ip[], int port);
};
