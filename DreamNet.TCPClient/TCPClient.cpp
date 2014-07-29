#include "TCPClient.h"

TCPClient::TCPClient(){

	client = INVALID_SOCKET;
	struct addrinfo *result = NULL, *ptr = NULL, hints;
	char *sendbuf = "this is a test";
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	DebugLog("Initialising Winsock......\r\n");

	/// Específica e inicializa a versão do winsock a ser usada
	iResult = WSAStartup(0x202, &wsaData);
	if (iResult != NO_ERROR){
		DebugLog("WSAStartup function failed with error: %ld.\r\n", WSAGetLastError());
		exit(NETWORK_ERROR);
	}

	DebugLog("Initialised.\r\n");

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	iResult = getaddrinfo(SERVER_ADDRESS, SERVER_PORT, &hints, &result);
	if (iResult != 0) {
		DebugLog("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		exit(NETWORK_ERROR);
	}

	// Tenta conectar-se a um endeeço, até que um seja bem sucedido
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

		// Cria um SOCKET para conectar no servidor
		client = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		if (client == INVALID_SOCKET) {
			DebugLog("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			exit(NETWORK_ERROR);
		}

		// Conecta no servidor
		iResult = connect(client, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(client);
			client = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (client == INVALID_SOCKET) {
		DebugLog("Unable to connect to server!\n");
		WSACleanup();
		exit(NETWORK_ERROR);
	}

	// Send an initial buffer
	iResult = send(client, sendbuf, (int)strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR) {
		DebugLog("send failed with error: %d\n", WSAGetLastError());
		closesocket(client);
		WSACleanup();
		exit(NETWORK_ERROR);
	}

	DebugLog("Bytes Sent: %ld\n", iResult);

	// shutdown the connection since no more data will be sent
	iResult = shutdown(client, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		DebugLog("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(client);
		WSACleanup();
		exit(NETWORK_ERROR);
	}

	// Receive until the peer closes the connection
	do {

		iResult = recv(client, recvbuf, recvbuflen, 0);
		if (iResult > 0)
			DebugLog("Bytes received: %d\n", iResult);
		else if (iResult == 0)
			DebugLog("Connection closed\n");
		else
			DebugLog("recv failed with error: %d\n", WSAGetLastError());

	} while (iResult > 0);

	// cleanup
	closesocket(client);
	WSACleanup();
}


TCPClient::~TCPClient(){
	system("PAUSE");
}
