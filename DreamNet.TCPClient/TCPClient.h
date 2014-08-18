#pragma once

/**
* @file  TCPClient.h
* @brief Classe que encapsula um cliente TCP/IP
*
* @copyright DreanNet 2011 - 2014, EESC - USP.
*
*/

#include <winsock2.h>
#include <stdio.h>
#include "NetworkServices.h"

/*******************************************************************
*   DEFINES
*******************************************************************/

/** @brief ip da máquina local */
#define LOCAL_HOST	"127.0.0.1"

/** @brief porta padrão do servidor */
#define DEFAULT_PORT 13000

/*******************************************************************
*   ESTRUTURA DA CLASSE
*******************************************************************/

/**
* @brief Classe que encapsula uma conexão TCP/IP
*/
class TCPClient
{
public:

	/**
	* Construtor da classe
	*/
	TCPClient(void);

	/**
	* Construtor da classe
	* @param address - endereço IP do servidor
	* @param port - porta de conexão do servidor
	* @param nagle - habilita (0) ou desabilita (1) o algoritmo naggle de conexão
	*/
	TCPClient(const char *address, int port, char nagle = 0);
	
	/**
	* Destrutor da classe
	*/
	~TCPClient(void);

	/**
	* Fecha a conexão se ela estiver aberta
	*/
	void Close(void);


	/**
	* Encerra conexão com o servidor
	*/
	void ShutdownSocket(void);

	/**
	* Inicializa o WinSock
	* @return inicialização realizada com sucesso (true), falha ao inicializar (false)
	*/
	bool InitializeSockets(void);

	/**
	* Abre conexão com o servidor
	* @return conexão estabelecida true), caso contrário (false)
	*/
	bool Open(void);

	/**
	* Verifica se existe conexão com o servidor
	* @return conexão estabelecida true), caso contrário (false)
	*/
	bool IsOpen(void) const;
	
	/**
	* Envia uma mensagem para o servidor
	* @param message - mensagem a ser enviada para o servidor
	* @param messageSize - tamanho da mensagem a ser enviada
	* @return informações do envio da mensagem
	*/
	int Send(char *message, int messageSize);

	/**
	* Recebe um buffer (mensagem) do servidor
	* @param buffer - buffer recebido do servidor
	* @param bufferSize - tamanho do buffer recebido
	* @return informações do recebimento do buffer
	*/
	int Receiver(char *buffer, int bufferSize);
	
private:

	SOCKET m_Socket;			/**< m_Socket - socket de conexão */
	int m_iResult;				/**< m_iResult - resultados de funções */
	const char *m_sAddress;		/**< m_sAddress -endereço IP do servidor */
	int m_iPort;				/**< m_iPort - porta de conexão do servidor */
	char m_cNagle;				/**< m_cNagle - uso do algoritmo naggle */
};