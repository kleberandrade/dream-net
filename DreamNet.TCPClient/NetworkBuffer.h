#pragma once
#include <winsock2.h>
#include <string.h>

class NetworkBuffer
{
public:
	NetworkBuffer(const char *buffer);

	// Decode
	double DecodeDouble(void);
	float DecodeFloat(void);
	int DecodeInt(void);

private:
	const char *m_parchBuffer;
};

