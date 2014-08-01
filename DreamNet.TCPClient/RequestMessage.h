#pragma once
#include "NetworkData.h"
#include "NetworkBuffer.h"

/**
*	Classe que representa a mensagem enviada do jogo (sistema) para o robô
*/
class RequestMessage : public NetworkData 
{
public:
	RequestMessage(void);

	inline double GetStiffness(void) const
	{ 
		return m_dStiffness; 
	}

	inline double GetPosition(void) const
	{ 
		return m_dPosition; 
	}

	inline double GetVelocity(void) const
	{ 
		return m_dVelocity; 
	}

	inline double GetAcceleration(void) const
	{ 
		return m_dAcceleration; 
	}

	inline unsigned int GetControlType(void) const
	{ 
		return m_uiControlType; 
	}

private:
	double m_dStiffness;			// 64 bits - 8 bytes
	double m_dPosition;				// 64 bits - 8 bytes
	double m_dVelocity;				// 64 bits - 8 bytes
	double m_dAcceleration;			// 64 bits - 8 bytes
	unsigned int m_uiControlType;	// 32 bits - 4 bytes

protected:
	virtual void OnDeserialize(NetworkBuffer buffer);
	virtual void OnSerialize(NetworkBuffer buffer);
};

