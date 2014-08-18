/**
* @file  NetworkServices.cpp
* @brief Implementação do wrapper para as funções de send e recv do SOCKET
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "NetworkServices.h"

/*******************************************************************
*   IMPLEMENTAÇÃO DA CLASSE
*******************************************************************/

/**
*	@brief	Função send encapsulada
*	@param	socket - socket para comunicação
*	@param	message - mensagem a ser enviada
*	@param	messageSize - tamanho da mensagem a ser enviada
*	@return informações do envio da mensagem
*/
int NetworkServices::SendMessage(SOCKET socket, char *message, int messageSize)
{
	return send(socket, message, messageSize, 0);
}

/**
*	@brief	Função recv encapsulada
*	@param	socket - socket para comunicação
*	@param	buffer - buffer recebido
*	@param	bufferSize - tamaho do buffer recebido
*	@return informações do buffer recebido
*/
int NetworkServices::ReceiveMessage(SOCKET socket, char *buffer, int bufferSize)
{
	return recv(socket, buffer, bufferSize, 0);
}