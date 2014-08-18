/**
* @file  GameRequestMessage.cpp
* @brief Implementa��o da classe que mantem as informa��es recebidas do servidor (Game)
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "GameRequestMessage.h"

/*******************************************************************
*   IMPLEMENTA��O DA CLASSE GAMEREQUESTMESSAGE
*******************************************************************/

/**
* M�todo de deserializa��o da mensagen em bin�rio
* @param decode - buffer utilizado para decodificar a mensagem em bin�rio
*/
void GameRequestMessage::OnDeserialize(BufferDecode &decode)
{
	m_iControl = decode.GetInt();
	m_dPosition = decode.GetDouble();
	m_dStiffness = decode.GetDouble();
	m_dVelocity = decode.GetDouble();
	m_dAcceleration = decode.GetDouble();
}
