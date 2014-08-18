/**
* @file  ClientNetwork.cpp
* @brief Implementação da classe Cliente TCP para conectar com um servidor e receber informações do jogo
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "ClientNetwork.h"

/*******************************************************************
*   IMPLEMENTAÇÃO DA CLASSE
*******************************************************************/

/**
* Construtor da classe
*/
ClientNetwork::ClientNetwork()
	: m_tcpClient()
{

}

/**
* Construtor da classe
* @param host - ip do servidor
* @param port - porta do servidor
*/
ClientNetwork::ClientNetwork(const char *host, int port)
	: m_tcpClient(host, port, 0)
{

}

/**
* Destrutor da classe
*/
ClientNetwork::~ClientNetwork(void)
{
	m_tcpClient.Close();
	m_tcpClient.ShutdownSocket();
	delete m_dispatcherData;
	delete m_requestData;
}

/**
* Abre a conecão com o servidor
* @return se a conexão for estabelecida (true), caso contrário (false)
*/
bool ClientNetwork::Open(void)
{
	m_tcpClient.InitializeSockets();
	m_tcpClient.Open();
	return true;
}

/**
* Verifica se a conexão esta aberta
* @return se a conexão estiver estabelecida (true), caso contrário (false)
*/
bool ClientNetwork::IsOpen(void)
{
	return m_tcpClient.IsOpen();
}

/**
* Encerra a conexão com o servidor
*/
void ClientNetwork::Close(void)
{
	m_tcpClient.Close();
}

/**
* Envia o buffer para o servidor
*/
void ClientNetwork::Send(void)
{
	m_dispatcherData->Serialize(m_Encode);
	char buffer[BUFFER_SIZE];
	memcpy(&buffer, m_Encode.GetBuffer(), BUFFER_SIZE);
	m_tcpClient.Send(buffer, BUFFER_SIZE);
}

/**
* Recebe o buffer do servidor
*/
void ClientNetwork::Receive(void)
{
	char buffer[BUFFER_SIZE];
	m_tcpClient.Receiver(buffer, BUFFER_SIZE);
	m_Decode.SetBuffer(buffer);
	m_requestData->Deserialize(m_Decode);
}