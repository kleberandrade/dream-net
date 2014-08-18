/**
* @file  BufferEncode.h
* @brief Classe auxiliar para codificar um buffer binario
*
* @copyright DreanNet 2011 - 2014, EESC - USP.
*
*/

#include "BufferEncode.h"


/*******************************************************************
*   IMPLEMENTAÇÃO DA CLASSE BUFFERENCODE
*******************************************************************/

/**
* Construtor da classe
*/
BufferEncode::BufferEncode(void)
	: Buffer(),
	m_iPosition(0)
{
	Clear();
}

/**
* Construtor da classe
* @param buffer - Conteúdo para o buffer
*/
BufferEncode::BufferEncode(char buffer[])
	: Buffer(buffer),
	m_iPosition(0)
{

}

/**
* Seta o próximo double
* @param dValue - double que será convertido para binário e alocado no buffer
*/
void BufferEncode::ToDouble(double dValue)
{
	double value = Encoding::HostToNetworkDouble(dValue);
	memcpy(&m_strBuffer[m_iPosition], &value, sizeof(double));
	m_iPosition += sizeof(double);
}


/**
* Seta o próximo float
* @param fValue - float que será convertido para binário e alocado no buffer
*/
void BufferEncode::ToFloat(float fValue)
{
	float value = Encoding::HostToNetworkFloat(fValue);
	memcpy(&m_strBuffer[m_iPosition], &value, sizeof(float));
	m_iPosition += sizeof(float);
}

/**
* Seta o próximo int
* @param iValue - int que será convertido para binário e alocado no buffer
*/
void BufferEncode::ToInt(int iValue)
{
	int value = Encoding::HostToNetworkInt(iValue);
	memcpy(&m_strBuffer[m_iPosition], &value, sizeof(int));
	m_iPosition += sizeof(int);
}

/**
* Limpa o buffer e zera m_iPosition
*/
void BufferEncode::Clear(void)
{
	Buffer::Clear();
	m_iPosition = 0;
}