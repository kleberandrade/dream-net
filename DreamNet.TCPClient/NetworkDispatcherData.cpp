/**
* @file  NetworkDispatcherData.cpp
* @brief Implementação da classe abstrata que serializa o buffer para rede
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "NetworkDispatcherData.h"

/*******************************************************************
*   IMPLEMENTAÇÃO DA CLASSE
*******************************************************************/

/**
* Método de serialização da mensagen em binário
* @param encode - buffer utilizado para codificar a mensagem em binário
*/
void NetworkDispatcherData::Serialize(BufferEncode &encode)
{
	encode.Clear();
	OnSerialize(encode);
}