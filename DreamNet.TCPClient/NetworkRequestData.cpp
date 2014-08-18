/**
* @file  NetworkRequestData.cpp
* @brief Implementa��o da classe abstrata que deserializa o buffer da rede
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "NetworkRequestData.h"

/*******************************************************************
*   IMPLEMENTA��O DA CLASSE
*******************************************************************/

/**
* M�todo de deserializa��o da mensagen em bin�rio
* @param decode - buffer utilizado para decodificar a mensagem em bin�rio
*/
void NetworkRequestData::Deserialize(BufferDecode &decode)
{
	OnDeserialize(decode);
	decode.Clear();
}