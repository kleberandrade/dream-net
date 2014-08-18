/**
* @file  NetworkDispatcherData.cpp
* @brief Implementa��o da classe abstrata que serializa o buffer para rede
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "NetworkDispatcherData.h"

/*******************************************************************
*   IMPLEMENTA��O DA CLASSE
*******************************************************************/

/**
* M�todo de serializa��o da mensagen em bin�rio
* @param encode - buffer utilizado para codificar a mensagem em bin�rio
*/
void NetworkDispatcherData::Serialize(BufferEncode &encode)
{
	encode.Clear();
	OnSerialize(encode);
}