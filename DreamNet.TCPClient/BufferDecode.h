#pragma once

/**
* @file  BufferDecode.h
* @brief Classe auxiliar para decodificar um buffer binario
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "Buffer.h"
#include "Encoding.h"

/*******************************************************************
*   ESTRUTURA DA CLASSE
*******************************************************************/

class BufferDecode : public Buffer
{
public:

	/**
	* Construtor da classe
	*/
	BufferDecode(void);

	/**
	* Construtor da classe
	* @param buffer - Conte�do para o buffer
	*/
	BufferDecode(char buffer[]);

	/**
	* Pega o pr�ximo double
	* @return double - retorna o pr�ximo double do buffer
	*/
	double GetDouble(void);

	/**
	* Pega o pr�ximo float
	* @return float - retorna o pr�ximo float do buffer
	*/
	float GetFloat(void);

	/**
	* Pega o pr�ximo int
	* @return int - retorna o pr�ximo int do buffer
	*/
	int GetInt(void);

	/**
	* Limpa o buffer e zera m_iPosition
	*/
	void Clear(void);

private:
	int m_iPosition;		/**< m_iPosition - posi��o (indice) do buffer */
};

