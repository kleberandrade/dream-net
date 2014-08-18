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

/** @brief ip da m�quina local */
#define LOCAL_HOST	"127.0.0.1"

/** @brief porta padr�o do servidor */
#define DEFAULT_PORT 13000

/*******************************************************************
*   ESTRUTURA DA CLASSE
*******************************************************************/

/**
* @brief Classe que encapsula uma conex�o TCP/IP
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
	* @param address - endere�o IP do servidor
	* @param port - porta de conex�o do servidor
	* @param nagle - habilita (0) ou desabilita (1) o algoritmo naggle de conex�o
	*/
	TCPClient(const char *address, int port, char nagle = 0);
	
	/**
	* Destrutor da classe
	*/
	~TCPClient(void);

	/**
	* Fecha a conex�o se ela estiver aberta
	*/
	void Close(void);


	/**
	* Encerra conex�o com o servidor
	*/
	void ShutdownSocket(void);

	/**
	* Inicializa o WinSock
	* @return inicializa��o realizada com sucesso (true), falha ao inicializar (false)
	*/
	bool InitializeSockets(void);

	/**
	* Abre conex�o com o servidor
	* @return conex�o estabelecida true), caso contr�rio (false)
	*/
	bool Open(void);

	/**
	* Verifica se existe conex�o com o servidor
	* @return conex�o estabelecida true), caso contr�rio (false)
	*/
	bool IsOpen(void) const;
	
	/**
	* Envia uma mensagem para o servidor
	* @param message - mensagem a ser enviada para o servidor
	* @param messageSize - tamanho da mensagem a ser enviada
	* @return informa��es do envio da mensagem
	*/
	int Send(char *message, int messageSize);

	/**
	* Recebe um buffer (mensagem) do servidor
	* @param buffer - buffer recebido do servidor
	* @param bufferSize - tamanho do buffer recebido
	* @return informa��es do recebimento do buffer
	*/
	int Receiver(char *buffer, int bufferSize);
	
private:

	SOCKET m_Socket;			/**< m_Socket - socket de conex�o */
	int m_iResult;				/**< m_iResult - resultados de fun��es */
	const char *m_sAddress;		/**< m_sAddress -endere�o IP do servidor */
	int m_iPort;				/**< m_iPort - porta de conex�o do servidor */
	char m_cNagle;				/**< m_cNagle - uso do algoritmo naggle */
};