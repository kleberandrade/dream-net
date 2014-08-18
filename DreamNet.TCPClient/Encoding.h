#pragma once

/**
* @file  Encoding.h
* @brief Wrapper para as codifica��es e decodifica��es de rede
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include <winsock2.h>

/*******************************************************************
*   ESTRUTURA DA CLASSE
*******************************************************************/

/**
* @brief Wrapper para as codifica��es e decodifica��es de rede
*/
class Encoding
{
public:

	/**
	* @brief M�todo est�tico para converter int do host para rede
	* @param iValue - valor int a ser convertido
	* @return valor int convertido
	*/
	static int HostToNetworkInt(int iValue);

	/**
	* @brief M�todo est�tico para converter int da rede para o host
	* @param iValue - valor int convertido
	* @return valor int normal
	*/
	static int NetworkToHostInt(int iValue);

	/**
	* @brief M�todo est�tico para converter float do host para rede
	* @param fValue - valor float a ser convertido
	* @return valor float convertido
	*/
	static float HostToNetworkFloat(float fValue);

	/**
	* @brief M�todo est�tico para converter float da rede para o host
	* @param fValue - valor float convertido
	* @return valor float normal
	*/
	static float NetworkToHostFloat(float fValue);

	/**
	* @brief M�todo est�tico para converter double do host para rede
	* @param dValue - valor double a ser convertido
	* @return valor double convertido
	*/
	static double HostToNetworkDouble(double dValue);

	/**
	* @brief M�todo est�tico para converter double da rede para o host
	* @param dValue - valor double convertido
	* @return valor double normal
	*/
	static double NetworkToHostDouble(double dValue);
};

