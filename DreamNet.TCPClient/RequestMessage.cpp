#include "RequestMessage.h"

RequestMessage::RequestMessage() 
{

}


RequestMessage::~RequestMessage()
{

}

void RequestMessage::OnDeserialize(char *data)
{
	NetworkBuffer buffer = NetworkBuffer(data);
	m_dStiffness = buffer.DecodeDouble();
	m_dPosition = buffer.DecodeDouble();
	m_dVelocity = buffer.DecodeDouble();
	m_dAcceleration = buffer.DecodeDouble();
	m_uiControlType = buffer.DecodeInt();
}
