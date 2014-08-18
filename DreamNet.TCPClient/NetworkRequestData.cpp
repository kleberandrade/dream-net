/**
* @file  NetworkRequestData.cpp
* @brief Implementação da classe abstrata que deserializa o buffer da rede
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "NetworkRequestData.h"

/*******************************************************************
*   IMPLEMENTAÇÃO DA CLASSE
*******************************************************************/

/**
* Método de deserialização da mensagen em binário
* @param decode - buffer utilizado para decodificar a mensagem em binário
*/
void NetworkRequestData::Deserialize(BufferDecode &decode)
{
	OnDeserialize(decode);
	decode.Clear();
}