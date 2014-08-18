/**
* @file  Buffer.cpp
* @brief Implementação da classe que representa um buffer, criando métodos para pegar e configurar um buffer
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "Buffer.h"

/*******************************************************************
*   IMPLEMENTAÇÃO DA CLASSE
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
* @param buffer - Conteúdo para o buffer
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
