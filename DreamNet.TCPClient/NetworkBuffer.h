#pragma once
#include <winsock2.h>
#include <string.h>

class NetworkBuffer
{
public:
	NetworkBuffer(const char *buffer);

	// Decode
	double DecodeDouble();
	float DecodeFloat();
	int DecodeInt();

private:
	const char *m_parchBuffer;
};

