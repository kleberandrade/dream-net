#pragma once
#include <winsock2.h>
#include <windows.h>

/**
*	Wrapper para as fun��es de send e recv do SOCKET
*
*/
class NetworkServices
{
public:
	/**
	*	@brief	Fun��o send encapsulada
	*
	*	@param	socket
	*	@param	message
	*	@param	messageSize
	*
	*	@return
	*/
	static int sendMessage(SOCKET socket, char *message, int messageSize);

	/**
	*	@brief	Fun��o recv encapsulada
	*
	*	@param	socket
	*	@param	buffer
	*	@param	bufferSize
	*
	*	@return
	*/
	static int receiveMessage(SOCKET socket, char *buffer, int messageSize);
};

