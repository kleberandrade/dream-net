/**
* @file  BufferDecode.cpp
* @brief Implementação da classe auxiliar para decodificar um buffer binario
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "BufferDecode.h"

/*******************************************************************
*   IMPLEMENTAÇÃO DA CLASSE BUFFERDECODE
*******************************************************************/

/**
* Construtor da classe
*/
BufferDecode::BufferDecode(void)
	: Buffer(),
	m_iPosition(0)
{
	Clear();
}

/**
* Construtor da classe
* @param buffer - Conteúdo para o buffer
*/
BufferDecode::BufferDecode(char buffer[])
	: Buffer(buffer),
	m_iPosition(0)
{

}

/**
* Pega o próximo double
* @return double - retorna o próximo double do buffer
*/
double BufferDecode::GetDouble()
{
	double value;
	memcpy(&value, &m_strBuffer[m_iPosition], sizeof(double));
	m_iPosition += sizeof(double);
	return Encoding::NetworkToHostDouble(value);
}

/**
* Pega o próximo float
* @return float - retorna o próximo float do buffer
*/
float BufferDecode::GetFloat()
{
	float value;
	memcpy(&value, &m_strBuffer[m_iPosition], sizeof(float));
	m_iPosition += sizeof(float);
	return Encoding::NetworkToHostFloat(value);
}

/**
* Pega o próximo int
* @return int - retorna o próximo int do buffer
*/
int BufferDecode::GetInt()
{
	int value;
	memcpy(&value, &m_strBuffer[m_iPosition], sizeof(int));
	m_iPosition += sizeof(int);
	return Encoding::NetworkToHostInt(value);
}

/**
* Limpa o buffer e zera m_iPosition
*/
void BufferDecode::Clear(void)
{
	Buffer::Clear();
	m_iPosition = 0;
}