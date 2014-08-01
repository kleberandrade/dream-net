#pragma once
#include <string.h>

#define PACKET_SIZE 256

enum PacketTypes {
	INIT_CONNECTION = 0,
	ACTION_EVENT = 1,
};

class NetworkData
{
public:
	NetworkData(void);
	~NetworkData(void);
	void Serialize(char *data);
	void Deserialize(char *data);

	inline unsigned int GetPacketyType() const 
	{ 
		return m_uiPacketType; 
	}

	inline void SetPacketyType(unsigned int packetType)
	{
		m_uiPacketType = packetType; 
	}

protected:
	unsigned int m_uiPacketType;			// 32 bits - 4 bytes

	virtual void OnSerialize(char *data) = 0;
	virtual void OnDeserialize(char *data) = 0;
};
