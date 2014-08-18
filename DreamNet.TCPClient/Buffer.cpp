/**
* @file  Buffer.h
* @brief Classe que representa um buffer, criando m�todos para pegar e configurar um buffer
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "Buffer.h"

/*******************************************************************
*   IMPLEMENTA��O DA CLASSE BUFFER
*******************************************************************/

/**
* Construtor da classe
*/
Buffer::Buffer()
{
	Clear();
}

/**
* Construtor da classe
* @param buffer - Conte�do para o buffer
*/
Buffer::Buffer(char buffer[])
{
	SetBuffer(buffer);
}

/**
* Limpa o buffer
*/
void Buffer::Clear(void)
{
	memset(m_strBuffer, 0, BUFFER_SIZE);
}
