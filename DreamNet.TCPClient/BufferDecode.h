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
	* @param buffer - Conteúdo para o buffer
	*/
	BufferDecode(char buffer[]);

	/**
	* Pega o próximo double
	* @return double - retorna o próximo double do buffer
	*/
	double GetDouble(void);

	/**
	* Pega o próximo float
	* @return float - retorna o próximo float do buffer
	*/
	float GetFloat(void);

	/**
	* Pega o próximo int
	* @return int - retorna o próximo int do buffer
	*/
	int GetInt(void);

	/**
	* Limpa o buffer e zera m_iPosition
	*/
	void Clear(void);

private:
	int m_iPosition;		/**< m_iPosition - posição (indice) do buffer */
};

