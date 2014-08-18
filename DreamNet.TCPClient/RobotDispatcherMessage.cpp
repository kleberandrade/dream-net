/**
* @file  RobotDispatcherMessage.cpp
* @brief Implementa��o da classe que mantem as informa��es enviadas para o servidor
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "RobotDispatcherMessage.h"

/**
* M�todo de serializa��o das mensagens para bin�rio
* @param encode - buffer utilizado para codificar a mensagem em bin�rio
*/
void RobotDispatcherMessage::OnSerialize(BufferEncode &encode)
{
	encode.ToInt(m_iStatus);			
	encode.ToDouble(m_dPosition);
}