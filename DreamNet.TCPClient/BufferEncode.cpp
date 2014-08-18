/**
* @file  BufferEncode.h
* @brief Classe auxiliar para codificar um buffer binario
*
* @copyright DreanNet 2011 - 2014, EESC - USP.
*
*/

#include "BufferEncode.h"


/*******************************************************************
*   IMPLEMENTA��O DA CLASSE BUFFERENCODE
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
* @param buffer - Conte�do para o buffer
*/
BufferEncode::BufferEncode(char buffer[])
	: Buffer(buffer),
	m_iPosition(0)
{

}

/**
* Seta o pr�ximo double
* @param dValue - double que ser� convertido para bin�rio e alocado no buffer
*/
void BufferEncode::ToDouble(double dValue)
{
	double value = Encoding::HostToNetworkDouble(dValue);
	memcpy(&m_strBuffer[m_iPosition], &value, sizeof(double));
	m_iPosition += sizeof(double);
}


/**
* Seta o pr�ximo float
* @param fValue - float que ser� convertido para bin�rio e alocado no buffer
*/
void BufferEncode::ToFloat(float fValue)
{
	float value = Encoding::HostToNetworkFloat(fValue);
	memcpy(&m_strBuffer[m_iPosition], &value, sizeof(float));
	m_iPosition += sizeof(float);
}

/**
* Seta o pr�ximo int
* @param iValue - int que ser� convertido para bin�rio e alocado no buffer
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