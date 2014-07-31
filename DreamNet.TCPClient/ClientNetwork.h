#pragma once
#include "TCPClient.h"

#define SERVER_ADDRESS	"127.0.0.1"
#define SERVER_PORT		12322

class ClientNetwork
{
public:
	ClientNetwork(void);
	~ClientNetwork(void);
	bool Open(void);

private:
	TCPClient m_tcpClient;
};

