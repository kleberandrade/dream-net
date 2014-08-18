/**
* @file  Buffer.cpp
* @brief Implementação da Classe Buffer
*
*/

#include "Buffer.h"

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
