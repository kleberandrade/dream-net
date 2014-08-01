#include "TCPClient.h"

TCPClient::TCPClient()
	: m_sAddress(LOCAL_HOST), 
	m_usPort(DEFAULT_PORT), 
	m_iNonBlock(1),
	m_cNagle(1)
{
	m_Socket = 0;
}

TCPClient::TCPClient(const char *address, unsigned short port, u_long nonBlock, char nagle)
	: m_sAddress(address), 
	m_usPort(port),
	m_iNonBlock(nonBlock), 
	m_cNagle(nagle)
{
	m_Socket = 0;
}

TCPClient::~TCPClient(void)
{
	Close();
}

void TCPClient::Close(void)
{
	if (IsOpen())
	{
		closesocket(m_Socket);
		m_Socket = 0;
	}
}

void TCPClient::ShutdownSocket(void)
{
	WSACleanup();
}

bool TCPClient::IsOpen(void) const
{
	return m_Socket != 0;
}

bool TCPClient::InitializeSockets(void)
{
	WSADATA wsaData;
	// Using MAKEWORD macro, Winsock version request 2.2
	WORD wVersionRequested = MAKEWORD(2, 2);
	int wsaerr = WSAStartup(wVersionRequested, &wsaData);;

	if (wsaerr != 0)
	{
		/* Tell the user that we could not find a usable WinSock DLL.*/
		printf("The Winsock dll not found!\n");
		return false;
	}
	else
	{
		printf("The Winsock dll found!\n");
		printf("The status: %s.\n", wsaData.szSystemStatus);
	}

	/* Confirm that the WinSock DLL supports 2.2.*/
	/* Note that if the DLL supports versions greater    */
	/* than 2.2 in addition to 2.2, it will still return */
	/* 2.2 in wVersion since that is the version we      */
	/* requested.                                        */
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		/* Tell the user that we could not find a usable WinSock DLL.*/
		printf("The dll do not support the Winsock version %u.%u!\n", LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
		ShutdownSocket();
		return false;
	}
	else
	{
		printf("The dll supports the Winsock version %u.%u!\n", LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
		printf("The highest version this dll can support: %u.%u\n", LOBYTE(wsaData.wHighVersion), HIBYTE(wsaData.wHighVersion));
	}

	return true;
}

bool TCPClient::Open(void)
{
	/// Cria um socket para conex�o com o servidor
	m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_Socket == INVALID_SOCKET) 
	{
		printf("Socket failed with error: %ld\n", WSAGetLastError());
		ShutdownSocket();
		return false;
	}

	/// configura as informa��es do ender�o
	sockaddr_in client_service;
	client_service.sin_family = AF_INET;
	client_service.sin_port = htons((unsigned short)m_usPort);
	client_service.sin_addr.s_addr = inet_addr(m_sAddress);
	
	/// Conecta no servidor
	m_iResult = connect(m_Socket, (SOCKADDR*)&client_service, sizeof(client_service));
	if (m_iResult == SOCKET_ERROR) 
	{
		printf("The server is down... did not connect.\r\n");
		Close();
		return false;
	}

	// se a conex�o falahar
	if (m_Socket == INVALID_SOCKET)
	{
		printf("Unable to connect to server!\r\n");
		ShutdownSocket();
		return false;
	}

	// Configura o modo the socket para n�o bloqueante
	m_iResult = ioctlsocket(m_Socket, FIONBIO, &m_iNonBlock);
	if (m_iResult == SOCKET_ERROR)
	{
		printf("ioctlsocket failed with error: %d\n", WSAGetLastError());
		Close();
		ShutdownSocket();
		return false;
	}

	// Desabilita o algoritmo Nagle
	setsockopt(m_Socket, IPPROTO_TCP, TCP_NODELAY, &m_cNagle, sizeof(m_cNagle));

	printf("Successfully connected.\r\n");
	return true;
}

int TCPClient::Send(char *message, int messageSize)
{
	m_iResult = NetworkServices::receiveMessage(m_Socket, message, messageSize);
	
	if (m_iResult == SOCKET_ERROR)
	{
		printf("Send failed with error: %d\n", WSAGetLastError());
		Close();
		ShutdownSocket();
	}

	return m_iResult;
}

int TCPClient::Receiver(char *buffer, int bufferSize)
{
	m_iResult = NetworkServices::receiveMessage(m_Socket, buffer, bufferSize);
	
	if (m_iResult <= 0)
	{
		printf("Recv failed with error : %d\n", WSAGetLastError());
		Close();
		ShutdownSocket();
	}

	return m_iResult;
}