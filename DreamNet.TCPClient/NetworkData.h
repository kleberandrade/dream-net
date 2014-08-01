#pragma once
#include <string.h>
#include "NetworkBuffer.h"

#define PACKET_SIZE 256

enum PacketTypes {
	INIT_CONNECTION = 0,
	ACTION_EVENT = 1,
};

class NetworkData
{
public:
	NetworkData(void);

	void Serialize(NetworkBuffer buffer);
	void Deserialize(NetworkBuffer buffer);

	inline unsigned int GetPacketyType() const 
	{ 
		return m_uiPacketType; 
	}

	inline void SetPacketyType(unsigned int packetType)
	{
		m_uiPacketType = packetType; 
	}

private:
	unsigned int m_uiPacketType;			// 32 bits - 4 bytes

protected:
	virtual void OnSerialize(NetworkBuffer buffer) = 0;
	virtual void OnDeserialize(NetworkBuffer buffer) = 0;
};
