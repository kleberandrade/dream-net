#pragma once
#include "TCPClient.h"
#include "RequestMessage.h"

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
	void ReceiveData();		

	inline RequestMessage GetRequestMessage()
	{
		return m_requestMessage;
	}

private:
	TCPClient m_tcpClient;
	RequestMessage m_requestMessage;
};

