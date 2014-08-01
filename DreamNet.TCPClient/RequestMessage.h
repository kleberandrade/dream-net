#pragma once
#include "NetworkData.h"
#include "NetworkBuffer.h"

enum RequestControlType {
	
};

/**
*	Classe que representa a mensagem enviada do jogo (sistema) para o robô
*/
class RequestMessage : public NetworkData 
{
public:
	RequestMessage();
	~RequestMessage();

	void serialize(char *data);
	void deserialize(char *data);

	inline double GetStiffness() const
	{ 
		return m_dStiffness; 
	}

	inline double GetPosition() const
	{ 
		return m_dPosition; 
	}

	inline double GetVelocity() const
	{ 
		return m_dVelocity; 
	}

	inline double GetAcceleration() const 
	{ 
		return m_dAcceleration; 
	}

	inline unsigned int GetControlType() const 
	{ 
		return m_uiControlType; 
	}

	inline void SetStiffness(double stiffness) 
	{ 
		m_dStiffness = stiffness;
	}

	inline void SetPosition(double position) 
	{
		m_dPosition = position; 
	}

	inline void SetVelocity(double velocity) 
	{
		m_dVelocity = velocity; 
	}

	inline void SetAcceleration(double acceleration)
	{ 
		m_dAcceleration = acceleration; 
	}

	inline void SetControlType(unsigned int controlType) 
	{ 
		m_uiControlType = controlType; 
	}

private:
	double m_dStiffness;			// 64 bits - 8 bytes
	double m_dPosition;				// 64 bits - 8 bytes
	double m_dVelocity;				// 64 bits - 8 bytes
	double m_dAcceleration;			// 64 bits - 8 bytes
	unsigned int m_uiControlType;	// 32 bits - 4 bytes

protected:
	void OnDeserialize(char *data) = 0;
};

