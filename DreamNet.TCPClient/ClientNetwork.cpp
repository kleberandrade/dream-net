#include "ClientNetwork.h"

ClientNetwork::ClientNetwork()
	: m_tcpClient(SERVER_ADDRESS, SERVER_PORT)
{
	
}

ClientNetwork::~ClientNetwork(void){
	m_tcpClient.Close();
	m_tcpClient.ShutdownSocket();
}

bool ClientNetwork::Open(void){

	if (m_tcpClient.IsOpen()){
		printf("Already open connection.\r\n");
		return true;
	}

	if (!m_tcpClient.InitializeSockets()){
		printf("failed to initialize sockets.\r\n");
		return false;
	}

	if (!m_tcpClient.Open()){
		printf("failed to open connection.\r\n");
		return false;
	}

	return true;
}

bool ClientNetwork::IsOpen(void)
{
	return m_tcpClient.IsOpen();
}

void ClientNetwork::ReceiveData(){
	char packetData[PACKET_SIZE];
	m_tcpClient.Receiver(packetData, PACKET_SIZE);
	m_requestMessage.Deserialize(NetworkBuffer(packetData));
}
