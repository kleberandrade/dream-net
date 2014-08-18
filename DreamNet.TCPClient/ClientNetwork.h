#pragma once

/**
* @file  ClientNetwork.h
* @brief Cliente TCP para conectar com um servidor e receber informações do jogo
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "TCPClient.h"
#include "NetworkDispatcherData.h"
#include "NetworkRequestData.h"
#include "GameRequestMessage.h"
#include "RobotDispatcherMessage.h"

/*******************************************************************
*   DEFINES
*******************************************************************/

/** @brief define que o endianness é do tipo big endian*/
// #define __BIG_ENDIAN

/** @brief define que o endianness é do tipo little endian*/
#define __LITTLE_ENDIAN

#ifdef _WCE_SECTION
#pragma comment(lib,"ws2.lib")
#else
#pragma comment (lib, "Ws2_32.lib")
#endif

/*******************************************************************
*   ESTRUTURA DA CLASSE
*******************************************************************/

/**
* @brief Cliente TCP para conectar com um servidor e receber informações do jogo
*/
class ClientNetwork
{
public:

	/**
	* Construtor da classe
	*/
	ClientNetwork();

	/**
	* Construtor da classe
	* @param host - ip do servidor
	* @param port - porta do servidor
	*/
	ClientNetwork(const char *host, int port);

	/**
	* Destrutor da classe
	*/
	~ClientNetwork(void);

	/**
	* Abre a conecão com o servidor
	* @return se a conexão for estabelecida (true), caso contrário (false)
	*/
	bool Open(void);

	/**
	* Verifica se a conexão esta aberta
	* @return se a conexão estiver estabelecida (true), caso contrário (false)
	*/
	bool IsOpen(void);

	/**
	* Encerra a conexão com o servidor
	*/
	void Close(void);

	/**
	* Envia o buffer para o servidor
	*/
	void Send(void);

	/**
	* Recebe o buffer do servidor
	*/
	void Receive(void);

	/**
	* Pega o objeto de envio para o servidor
	* @return m_dispatcherData
	*/
	inline NetworkDispatcherData *GetDispatcherData(void)
	{
		return m_dispatcherData;
	}

	/**
	* Pega o objeto de recebimento do servidor
	* @return m_requestData
	*/
	inline NetworkRequestData *GetRequestData(void)
	{
		return m_requestData;
	}

	/**
	* Configura o objeto de envio de dados
	* @param dispatcherData - tipo de objeto de dados a ser enviado para o servidor
	*/
	inline void SetDispatcher(NetworkDispatcherData *dispatcherData)
	{
		m_dispatcherData = dispatcherData;
	}

	/**
	* Configura o objeto de recebimento de dados
	* @param requestData - tipo de objeto de dados a ser recebido do servidor
	*/
	inline void SetRequest(NetworkRequestData *requestData)
	{
		m_requestData = requestData;
	}

private:
	TCPClient m_tcpClient;						/**< m_tcpClient - cliente TCP */
	BufferDecode m_Decode;						/**< m_Decode - decodificador de buffer */
	BufferEncode m_Encode;						/**< m_Encode - codificador de buffer */
	NetworkRequestData *m_requestData;			/**< m_requestData - ponteiro para mensagen de recebida do servidor */
	NetworkDispatcherData *m_dispatcherData;	/**< m_dispatcherData - ponteiro para mensagem a ser enviada para o servidor */
};	

