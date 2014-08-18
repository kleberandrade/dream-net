/**
* @file  GameRequestMessage.cpp
* @brief Implementação da classe que mantem as informações recebidas do servidor (Game)
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "GameRequestMessage.h"

/*******************************************************************
*   IMPLEMENTAÇÃO DA CLASSE GAMEREQUESTMESSAGE
*******************************************************************/

/**
* Método de deserialização da mensagen em binário
* @param decode - buffer utilizado para decodificar a mensagem em binário
*/
void GameRequestMessage::OnDeserialize(BufferDecode &decode)
{
	m_iControl = decode.GetInt();
	m_dPosition = decode.GetDouble();
	m_dStiffness = decode.GetDouble();
	m_dVelocity = decode.GetDouble();
	m_dAcceleration = decode.GetDouble();
}
