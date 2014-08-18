/**
* @file  NetworkServices.cpp
* @brief Implementa��o do wrapper para as fun��es de send e recv do SOCKET
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "NetworkServices.h"

/*******************************************************************
*   IMPLEMENTA��O DA CLASSE
*******************************************************************/

/**
*	@brief	Fun��o send encapsulada
*	@param	socket - socket para comunica��o
*	@param	message - mensagem a ser enviada
*	@param	messageSize - tamanho da mensagem a ser enviada
*	@return informa��es do envio da mensagem
*/
int NetworkServices::SendMessage(SOCKET socket, char *message, int messageSize)
{
	return send(socket, message, messageSize, 0);
}

/**
*	@brief	Fun��o recv encapsulada
*	@param	socket - socket para comunica��o
*	@param	buffer - buffer recebido
*	@param	bufferSize - tamaho do buffer recebido
*	@return informa��es do buffer recebido
*/
int NetworkServices::ReceiveMessage(SOCKET socket, char *buffer, int bufferSize)
{
	return recv(socket, buffer, bufferSize, 0);
}