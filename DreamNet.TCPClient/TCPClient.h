#pragma once
#include <winsock2.h>
#include <stdio.h>

class TCPClient
{
public:

	TCPClient(char* address, unsigned short port, u_long nonBlock = true, char nagle = 1);
	~TCPClient(void);
	void Close(void);
	void ShutdownSocket(void);
	bool InitializeSockets(void);
	bool Open(void);
	bool IsOpen(void) const;
	
	int Send();
	int Receiver();

	char* GetAddress() const { return m_sAddress; }
	unsigned short GetPort() const { return m_usPort; };
	
private:

	SOCKET m_Socket;
	int m_iResult;
	char* m_sAddress;
	unsigned short m_usPort;
	char m_cNagle;
	u_long m_iNonBlock;
};