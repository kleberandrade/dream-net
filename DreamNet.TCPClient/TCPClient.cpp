#include "TCPClient.h"

TCPClient::TCPClient(){

	client = INVALID_SOCKET;

	DebugLog("Initialising Winsock......\r\n");

	/// Específica e inicializa a versão do winsock a ser usada
	iResult = WSAStartup(0x202, &wsaData);
	if (iResult != NO_ERROR){
		DebugLog("WSAStartup function failed with error: %ld.\r\n", WSAGetLastError());
		exit(NETWORK_ERROR);
	}

	DebugLog("Initialised.\r\n");


	/// Criando um SOCKET para coneção com o servidor
	client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (client == INVALID_SOCKET) {
		DebugLog("socket function failed with error: %ld.\r\n", WSAGetLastError());
		WSACleanup();
		exit(NETWORK_ERROR);
	}

	DebugLog("Socket created.\r\n");

	/// A estrutura sockaddr_in específica a família de endereços
	/// O endereço IP e a PORTA a ser conecatada no servidor
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
	service.sin_port = htons(SERVER_PORT);

	/// Conectando no servidor
	iResult = connect(client, (SOCKADDR *)&service, sizeof(service));
	if (iResult < SOCKET_ERROR){
		closesocket(client);
		client = INVALID_SOCKET;
		DebugLog("The server is down... did not connect\r\n");
		exit(NETWORK_ERROR);
	}

	if (client == INVALID_SOCKET){
		DebugLog("Unable to connect to server!\n");
		WSACleanup();
		exit(NETWORK_ERROR);
	}

	DebugLog("Connected to server.\r\n");
}


TCPClient::~TCPClient(){
	system("PAUSE");
}
