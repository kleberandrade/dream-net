#include "NetworkBuffer.h"


NetworkBuffer::NetworkBuffer(const char *buffer) :
	m_parchBuffer(buffer),
	m_iPosition(0) 
{

}

NetworkBuffer::~NetworkBuffer()
{
	delete[] m_parchBuffer;
	m_parchBuffer = 0;
}

void NetworkBuffer::Clear()
{
	memset(&m_parchBuffer, 0, Size());
}

int NetworkBuffer::Size()
{
	return strlen(m_parchBuffer);
}

double NetworkBuffer::DecodeDouble()
{
	double value = ntohd(*(__int64*)m_parchBuffer);
	m_parchBuffer += sizeof(double);
	return value;
}

float NetworkBuffer::DecodeFloat()
{
	float value = ntohf(*(__int32*)m_parchBuffer);
	m_parchBuffer += sizeof(float);
	return value;
}

int NetworkBuffer::DecodeInt()
{
	int value = ntohl(*(__int32*)m_parchBuffer);
	m_parchBuffer += sizeof(int);
	return value;
}

char NetworkBuffer::DecodeChar()
{
	char value = ntohl(*(__int16*)m_parchBuffer);
	m_parchBuffer += sizeof(char);
	return value;
}

void NetworkBuffer::EncodeDouble(double &value)
{
	m_parchBuffer += htond(*(__int64 *)&value);
	m_parchBuffer += sizeof(double);
}

void NetworkBuffer::EncodeFloat(float &value)
{
	m_parchBuffer += htonf(*(__int32 *)&value);
	m_parchBuffer += sizeof(float);
}

void NetworkBuffer::EncodeInt(int &value)
{
	m_parchBuffer += htonl(*(__int32 *)&value);
	m_parchBuffer += sizeof(int);
}

void NetworkBuffer::EncodeChar(char &value)
{
	m_parchBuffer += htonl(*(__int16 *)&value);
	m_parchBuffer += sizeof(char);
}
