#pragma once
#include <winsock2.h>
#include <string.h>

class NetworkBuffer
{
public:
	NetworkBuffer(const char *buffer);
	~NetworkBuffer();
	
	void Clear();
	int Size();

	// Decode
	double DecodeDouble();
	float DecodeFloat();
	int DecodeInt();
	char DecodeChar();

	// Encode
	void EncodeDouble(double &value);
	void EncodeFloat(float &value);
	void EncodeInt(int &value);
	void EncodeChar(char &value);

	inline const char *GetBufffer() 
	{ 
		return m_parchBuffer; 
	}

private:
	const char *m_parchBuffer;
	INT64 m_iPosition;
};

