#include "TCPClient.h"

TCPClient::TCPClient(){

	remote_socket = INVALID_SOCKET;
	running = false;

	DebugLog("Initialising Winsock......\r\n");

	//----------------------
	/// Específica e inicializa a versão do winsock a ser usada
	iResult = WSAStartup(0x202, &wsaData);
	if (iResult != NO_ERROR){
		DebugLog("WSAStartup function failed with error: %ld.\r\n", WSAGetLastError());
		exit(NETWORK_ERROR);
	}

	DebugLog("Initialised.\r\n");

	//----------------------
	// Cria um socket para conexão com o servidor
	remote_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (remote_socket == INVALID_SOCKET) {
		DebugLog("socket failed with error: %ld\r\n", WSAGetLastError());
		WSACleanup();
		exit(NETWORK_ERROR);
	}
}

TCPClient::~TCPClient(){
	system("PAUSE");
}

/**
	Fecha o socket
*/
void TCPClient::Close(){
	DebugLog("Connection closed\r\n");
	closesocket(remote_socket);
	WSACleanup();
}

/**
	Connect no servidor.
*/
int TCPClient::Connect(){
	iResult = connect(remote_socket, (SOCKADDR*)&client_service, sizeof(client_service));

	if (iResult == SOCKET_ERROR) {
		DebugLog("connect failed with error: %d\r\n", WSAGetLastError());
		closesocket(remote_socket);
		WSACleanup();
		return NETWORK_ERROR;
	}

	running = true;
	return NETWORK_OK;
}

DWORD WINAPI TCPClient::Sender(LPVOID param){
	DebugLog("Start sender thread\r\n");
	SOCKET socket = (SOCKET)param;
	char buffer[BUFFER_SIZE];
	int byteSend;

	do{
		memset(&buffer, 0, BUFFER_SIZE);
		// envia a mensagem para o servidor
		byteSend = send(socket, buffer, BUFFER_SIZE, 0);
		if (byteSend == SOCKET_ERROR){
			DebugLog("Failed to send message\r\n");
			running = false;
		}
		else {
			DebugLog("send() is OK.\n");
			DebugLog("Sended data is: \"%s\"\r\n", buffer);
			DebugLog("Bytes Sent: %ld.\n", byteSend);
		}

		Sleep(SLEEP_TIME);
	} while (running);

	return EXIT_SUCCESS;
}

DWORD WINAPI TCPClient::Receiver(LPVOID param){
	DebugLog("Start receiver thread\r\n");
	SOCKET socket = (SOCKET)param;
	char buffer[BUFFER_SIZE];
	int byteRecv;

	do{
		memset(&buffer, 0, BUFFER_SIZE);
		// recebe a mensagem do servidor
		byteRecv = recv(socket, buffer, BUFFER_SIZE, 0);
		if (byteRecv == SOCKET_ERROR){
			DebugLog("Failed to receive messsage.\r\n", WSAGetLastError());
			running = false;
		}
		else {
			DebugLog("ecv() is OK.\n");
			DebugLog("Received data is: \"%s\"\r\n", buffer);
			DebugLog("Bytes received: %ld.\r\n", byteRecv);
		}

		Sleep(SLEEP_TIME);
	} while (running);

	return EXIT_SUCCESS;
}