#pragma once
#include <winsock2.h>
#include <windows.h>

/**
*	Wrapper para as funções de send e recv do SOCKET
*
*/
class NetworkServices
{
public:
	/**
	*	@brief	Função send encapsulada
	*
	*	@param	socket
	*	@param	message
	*	@param	messageSize
	*
	*	@return
	*/
	static int sendMessage(SOCKET socket, char *message, int messageSize);

	/**
	*	@brief	Função recv encapsulada
	*
	*	@param	socket
	*	@param	buffer
	*	@param	bufferSize
	*
	*	@return
	*/
	static int receiveMessage(SOCKET socket, char *buffer, int messageSize);
};

