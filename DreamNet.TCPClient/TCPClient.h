#pragma once
#include <winsock2.h>
#include <stdio.h>
#include "NetworkServices.h"

#define LOCAL_HOST		"127.0.0.1"
#define DEFAULT_PORT	12321

class TCPClient
{
public:

	TCPClient();
	TCPClient(const char *address, unsigned short port, u_long nonBlock = true, char nagle = 1);
	~TCPClient(void);
	void Close(void);
	void ShutdownSocket(void);
	bool InitializeSockets(void);
	bool Open(void);
	bool IsOpen(void) const;
	
	int Send(char *message, int messageSize);
	int Receiver(char *buffer, int bufferSize);
	
private:

	SOCKET m_Socket;
	int m_iResult;
	const char *m_sAddress;
	unsigned short m_usPort;
	char m_cNagle;
	u_long m_iNonBlock;
};