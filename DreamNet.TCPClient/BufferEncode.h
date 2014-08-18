#pragma once

/**
* @file  BufferEncode.h
* @brief Classe auxiliar para codificar um buffer binario
*
* @copyright DreanNet 2011 - 2014, EESC - USP.
*
*/

#include "Buffer.h"
#include "Encoding.h"

/*******************************************************************
*   ESTRUTURA DA CLASSE
*******************************************************************/

class BufferEncode : public Buffer
{
public:

	/**
	* Construtor da classe
	*/
	BufferEncode(void);

	/**
	* Construtor da classe
	* @param buffer - Conte�do para o buffer
	*/
	BufferEncode(char buffer[]);

	/**
	* Seta o pr�ximo double
	* @param dValue - double que ser� convertido para bin�rio e alocado no buffer
	*/
	void ToDouble(double dValue);

	/**
	* Seta o pr�ximo float
	* @param fValue - float que ser� convertido para bin�rio e alocado no buffer
	*/
	void ToFloat(float fValue);

	/**
	* Seta o pr�ximo int
	* @param iValue - int que ser� convertido para bin�rio e alocado no buffer
	*/
	void ToInt(int iValue);

	/**
	* Limpa o buffer e zera m_iPosition
	*/
	void Clear(void);

private:
	int m_iPosition;			/**< m_iPosition - posi��o (indice) do buffer */
};

