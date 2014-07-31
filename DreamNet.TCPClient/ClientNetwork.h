#pragma once
#include "TCPClient.h"
#include "NetworkData.h"

#define SERVER_ADDRESS	"127.0.0.1"
#define SERVER_PORT		12322
#define SLEEP_TIME		1000

class ClientNetwork
{
public:
	ClientNetwork(void);
	~ClientNetwork(void);
	bool Open(void);

	void SendData();				// Envia os dados genéricos pela rede
	void ReceiveData();				// Recebe os dados genéricos pela rede

	///static DWORD WINAPI Update(LPVOID param);

private:
	TCPClient m_tcpClient;
	NetworkData sendData;
	NetworkData receiverData;
};

