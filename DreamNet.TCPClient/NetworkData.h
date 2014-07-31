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

	virtual ~NetworkData(void);
	virtual void serialize(char *data);
	virtual void deserialize(char *data);

protected:
	unsigned int m_uiPacketType;
};





/*
struct Packet {
	void serialize(char *data) {
		//memcpy(data, this, sizeof(Packet));
	}

	void deserialize(char *data) {
		//memcpy(this, data, sizeof(Packet));
	}
};
*/