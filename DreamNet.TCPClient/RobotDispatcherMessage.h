#pragma once

/**
* @file  RobotDispatcherMessage.h
* @brief Classe que mantem as informa��es enviadas para o servidor
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "NetworkDispatcherData.h"
#include <stdio.h>

/*******************************************************************
*   ESTRUTURA DA CLASSE
*******************************************************************/

/**
* @brief Classe que mantem as informa��es enviadas para o servidor
*/
class RobotDispatcherMessage : public NetworkDispatcherData
{
public:

	/**
	* Configura a posi��o do rob�
	* @param position - Posi��o (�ngulo) do rob�
	*/
	inline void SetPosition(double position)
	{
		m_dPosition = position;
	}

	/**
	* Configura o status do rob�
	* @param status - Status atual do rob�
	*/
	inline void SetStatus(int status)
	{
		m_iStatus = status;
	}

protected:

	/**
	* M�todo de serializa��o das mensagens para bin�rio
	* @param encode - buffer utilizado para codificar a mensagem em bin�rio
	*/
	void OnSerialize(BufferEncode &encode);

private:
	double m_dPosition;			/**< m_dPosition - posi��o (�ngulo) da junta do rob� */
	int m_iStatus;				/**< m_iStatus - status do rob� */
};

