#pragma once
#include "NetworkData.h"

enum RequestControlType {
	
};

/**
*	Classe que representa a mensagem enviada do jogo (sistema) para o robô
*/
class RequestMessage : public NetworkData {
public:
	RequestMessage();
	~RequestMessage();

	void serialize(char *data);
	void deserialize(char *data);

	double GetStiffness() const { return m_dStiffness; }
	double GetPosition() const { return m_dPosition; }
	double GetVelocity() const { return m_dVelocity; }
	double GetAcceleration() const { return m_dAcceleration; }
	unsigned int GetControlType() const { return m_uiControlType; }

	void SetStiffness(double stiffness) { m_dStiffness = stiffness; }
	void SetPosition(double position) { m_dPosition = position; }
	void SetVelocity(double velocity) { m_dVelocity = velocity; }
	void SetAcceleration(double acceleration) { m_dAcceleration = acceleration; }
	void SetControlType(unsigned int controlType) { m_uiControlType = controlType; }

private:
	double m_dStiffness;			// 64 bits - 8 bytes
	double m_dPosition;				// 64 bits - 8 bytes
	double m_dVelocity;				// 64 bits - 8 bytes
	double m_dAcceleration;			// 64 bits - 8 bytes
	unsigned int m_uiControlType;	// 32 bits - 4 bytes

protected:
	void OnSerialize(char *data) = 0;
	void OnDeserialize(char *data) = 0;
};

