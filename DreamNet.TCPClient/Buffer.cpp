/**
* @file  Buffer.cpp
* @brief Implementa��o da Classe Buffer
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
