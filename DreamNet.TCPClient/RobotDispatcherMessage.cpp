/**
* @file  RobotDispatcherMessage.cpp
* @brief Implementação da classe que mantem as informações enviadas para o servidor
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "RobotDispatcherMessage.h"

/**
* Método de serialização das mensagens para binário
* @param encode - buffer utilizado para codificar a mensagem em binário
*/
void RobotDispatcherMessage::OnSerialize(BufferEncode &encode)
{
	encode.ToInt(m_iStatus);			
	encode.ToDouble(m_dPosition);
}