#include "TCPClient.h"

bool TCPClient::running;

/**
* Construtor que configura um objeto da classe TCPClient para conectar-se em um servidor
*
*/
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

	client_service.sin_family = AF_INET;
	client_service.sin_port = htons(SERVER_PORT);                    //Set the port
	client_service.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);      //Set the address we want to connect to

	//----------------------
	// Cria um socket para conexão com o servidor
	remote_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (remote_socket == INVALID_SOCKET) {
		DebugLog("socket failed with error: %ld\r\n", WSAGetLastError());
		WSACleanup();
		exit(NETWORK_ERROR);
	}
}

/**
* Destrutor da classe TCPClient
*
*/
TCPClient::~TCPClient(){
	DebugLog("Destoring TCPClient...\r\n");
	running = false;
	if (remote_socket)
		closesocket(remote_socket);
	WSACleanup();
}

/**
*	Método para encerrar o cliente
*
*/
void TCPClient::Close(){
	running = false;
}

/**
*	Método para tentar conectar no servidor
*
*/
int TCPClient::Connect(){
	iResult = connect(remote_socket, (SOCKADDR*)&client_service, sizeof(client_service));

	if (iResult == SOCKET_ERROR) {
		DebugLog("connect failed with error: %d\r\n", WSAGetLastError());
		closesocket(remote_socket);
		WSACleanup();
		return NETWORK_ERROR;
	}

	DebugLog("Client connected.\r\n");

	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TCPClient::Session, (LPVOID)remote_socket, 0, NULL);
	return NETWORK_OK;
}

/**
*	Sessão aberta para comunicação com o jogo
*
*/
DWORD WINAPI TCPClient::Session(LPVOID param){
	DebugLog("Start session.\r\n");
	SOCKET socket = (SOCKET)param;
	char recvbuf[BUFFER_SIZE];
	char sendbuf[BUFFER_SIZE];
	int iResult;
	running = true;

	do {
		// limpa os buffers
		memset(&recvbuf, 0, BUFFER_SIZE);
		memset(&sendbuf, 0, BUFFER_SIZE);

		// envia a mensagem para o servidor
		iResult = send(socket, sendbuf, BUFFER_SIZE, 0);
		if (iResult == SOCKET_ERROR){
			DebugLog("Failed to send message\r\n");
			running = false;
		}
		else {
			DebugLog("send() is OK.\n");
			DebugLog("Sended data is: \"%s\"\r\n", sendbuf);
			DebugLog("Bytes Sent: %ld.\n", iResult);
		}

		// recebe a mensagem do servidor
		iResult = recv(socket, recvbuf, BUFFER_SIZE, 0);
		if (iResult == SOCKET_ERROR){
			DebugLog("Failed to receive messsage.\r\n", WSAGetLastError());
			running = false;
		}
		else {
			DebugLog("ecv() is OK.\n");
			DebugLog("Received data is: \"%s\"\r\n", recvbuf);
			DebugLog("Bytes received: %ld.\r\n", iResult);
		}

		Sleep(SLEEP_TIME);

	} while (running && iResult > 0);

	DebugLog("Connection closed\r\n");
	running = false;
	closesocket(socket);
	WSACleanup();

	return EXIT_SUCCESS;
}