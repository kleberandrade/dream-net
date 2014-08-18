#pragma once

/**
* @file  Encoding.h
* @brief Wrapper para as codificações e decodificações de rede
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include <winsock2.h>

/*******************************************************************
*   ESTRUTURA DA CLASSE
*******************************************************************/

/**
* @brief Wrapper para as codificações e decodificações de rede
*/
class Encoding
{
public:

	/**
	* @brief Método estático para converter int do host para rede
	* @param iValue - valor int a ser convertido
	* @return valor int convertido
	*/
	static int HostToNetworkInt(int iValue);

	/**
	* @brief Método estático para converter int da rede para o host
	* @param iValue - valor int convertido
	* @return valor int normal
	*/
	static int NetworkToHostInt(int iValue);

	/**
	* @brief Método estático para converter float do host para rede
	* @param fValue - valor float a ser convertido
	* @return valor float convertido
	*/
	static float HostToNetworkFloat(float fValue);

	/**
	* @brief Método estático para converter float da rede para o host
	* @param fValue - valor float convertido
	* @return valor float normal
	*/
	static float NetworkToHostFloat(float fValue);

	/**
	* @brief Método estático para converter double do host para rede
	* @param dValue - valor double a ser convertido
	* @return valor double convertido
	*/
	static double HostToNetworkDouble(double dValue);

	/**
	* @brief Método estático para converter double da rede para o host
	* @param dValue - valor double convertido
	* @return valor double normal
	*/
	static double NetworkToHostDouble(double dValue);
};

