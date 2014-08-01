#include "RequestMessage.h"

RequestMessage::RequestMessage(void)
	: NetworkData()
{

}

void RequestMessage::OnDeserialize(NetworkBuffer buffer)
{
	m_dStiffness = buffer.DecodeDouble();
	m_dPosition = buffer.DecodeDouble();
	m_dVelocity = buffer.DecodeDouble();
	m_dAcceleration = buffer.DecodeDouble();
	m_uiControlType = buffer.DecodeInt();
}

void RequestMessage::OnSerialize(NetworkBuffer buffer)
{

}