#pragma once
#include "TCPClient.h"
#include "NetworkDispatcherData.h"
#include "NetworkRequestData.h"

#define SERVER_ADDRESS	"127.0.0.1"
#define SERVER_PORT		12322
#define SLEEP_TIME		1000

class ClientNetwork
{
public:
	ClientNetwork();
	~ClientNetwork(void);

	bool Open(void);
	bool IsOpen(void);
	
private:
	TCPClient m_tcpClient;
	NetworkRequestData *m_requestData;
	NetworkDispatcherData *m_dispatcherData;
};

