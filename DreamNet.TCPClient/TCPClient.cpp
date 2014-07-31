#include "TCPClient.h"

TCPClient::TCPClient(char *address, unsigned short port, u_long nonBlock, char nagle){
	m_sAddress = address;
	m_usPort = port;
	m_iNonBlock = nonBlock;
	m_cNagle = nagle;
	m_Socket = 0;
}

TCPClient::~TCPClient(void){
	Close();
}

void TCPClient::Close(void){
	if (IsOpen()){
		closesocket(m_Socket);
		m_Socket = 0;
	}
}

void TCPClient::ShutdownSocket(void){
	WSACleanup();
}

bool TCPClient::IsOpen(void) const {
	return m_Socket != 0;
}

bool TCPClient::InitializeSockets(void){
	WSADATA WsaData;
	/// Específica e inicializa a versão do winsock a ser usada
	return WSAStartup(MAKEWORD(2, 2), &WsaData) != NO_ERROR;
}

bool TCPClient::Open(void){

	if (IsOpen())
		return true;

	/// Cria um socket para conexão com o servidor
	m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_Socket == INVALID_SOCKET) {
		printf("Socket failed with error: %ld\n", WSAGetLastError());
		ShutdownSocket();
		return false;
	}

	/// configura as informações do enderço
	sockaddr_in client_service;
	client_service.sin_family = AF_INET;
	client_service.sin_port = htons((unsigned short)GetPort());
	client_service.sin_addr.s_addr = inet_addr(GetAddress());
	
	/// Conecta no servidor
	m_iResult = connect(m_Socket, (SOCKADDR*)&client_service, sizeof(client_service));
	if (m_iResult == SOCKET_ERROR) {
		printf("The server is down... did not connect.\r\n");
		Close();
		return false;
	}

	// se a conexão falahar
	if (m_Socket == INVALID_SOCKET)
	{
		printf("Unable to connect to server!\r\n");
		ShutdownSocket();
		return false;
	}

	// Configura o modo the socket para não bloqueante
	m_iResult = ioctlsocket(m_Socket, FIONBIO, &m_iNonBlock);
	if (m_iResult == SOCKET_ERROR){
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

int TCPClient::Send(char *message, int messageSize){
	m_iResult = NetworkServices::receiveMessage(m_Socket, message, messageSize);
	
	if (m_iResult == SOCKET_ERROR){
		printf("Send failed with error: %d\n", WSAGetLastError());
		Close();
		ShutdownSocket();
	}

	return m_iResult;
}

int TCPClient::Receiver(char *buffer, int bufferSize){

	m_iResult = NetworkServices::receiveMessage(m_Socket, buffer, bufferSize);
	
	if (m_iResult <= 0){
		printf("Recv failed with error : %d\n", WSAGetLastError());
		Close();
		ShutdownSocket();
	}

	return m_iResult;
}