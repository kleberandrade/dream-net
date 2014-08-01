#pragma once
#include <winsock2.h>
#include <stdio.h>
#include "NetworkServices.h"

#define LOCAL_HOST		"127.0.0.1"
#define DEFAULT_PORT	13000

class TCPClient
{
public:

	TCPClient();
	TCPClient(const char *address, int port, u_long nonBlock = false, char nagle = 1);
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
	int m_iPort;
	char m_cNagle;
	u_long m_iNonBlock;
};