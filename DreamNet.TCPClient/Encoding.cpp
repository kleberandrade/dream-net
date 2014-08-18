/**
* @file  Encoding.cpp
* @brief Implementa��o do wrapper para as codifica��es e decodifica��es de rede
*
* @copyright DreanNet 2011-2014, EESC-USP.
*
*/

#include "Encoding.h"

/*******************************************************************
*   IMPLEMENTA��O DA CLASSE
*******************************************************************/

/**
* @brief M�todo est�tico para converter int do host para rede
* @param iValue - valor int a ser convertido
* @return valor int convertido
*/
int Encoding::HostToNetworkInt(int iValue)
{
#if __BIG_ENDIAN
	return htonl(iValue);
#else
	return iValue;
#endif
}

/**
* @brief M�todo est�tico para converter int da rede para o host
* @param iValue - valor int convertido
* @return valor int normal
*/
int Encoding::NetworkToHostInt(int iValue)
{
#if __BIG_ENDIAN
	return ntohl(iValue);
#else
	return iValue;
#endif
}

/**
* @brief M�todo est�tico para converter float do host para rede
* @param fValue - valor float a ser convertido
* @return valor float convertido
*/
float Encoding::HostToNetworkFloat(float fValue)
{
#if __BIG_ENDIAN
	unsigned short i;                            
	unsigned short j;
	unsigned short convert;

	union {
		float val;                       
		unsigned char p[4];
	}zone;                         

	zone.val = fValue;

	for (i = 0, j = 3; i < j; i++, j--)
	{
		convert = (zone.p[i] << 8) + zone.p[j];
		convert = htons(convert);
		zone.p[i] = convert >> 8;
		zone.p[j] = convert & 0x00ff;
	}

	return(zone.val);
#else
	return fValue;
#endif
}

/**
* @brief M�todo est�tico para converter float da rede para o host
* @param fValue - valor float convertido
* @return valor float normal
*/
float Encoding::NetworkToHostFloat(float fValue)
{
#if __BIG_ENDIAN
	unsigned short i;                          
	unsigned short  j;                            
	unsigned short  convert;                  

	union {
		float val;                      
		unsigned char p[4];                   
	}zone;                        

	zone.val = fValue;

	for (i = 0, j = 3; i < j; i++, j--)
	{
		convert = (zone.p[i] << 8) + zone.p[j];
		convert = ntohs(convert);
		zone.p[i] = convert >> 8;
		zone.p[j] = convert & 0x00ff;
	}

	return(zone.val);
#else
	return fValue;
#endif
}

/**
* @brief M�todo est�tico para converter double do host para rede
* @param dValue - valor double a ser convertido
* @return valor double convertido
*/
double Encoding::HostToNetworkDouble(double dValue)
{
#if __BIG_ENDIAN
	unsigned short i;           
	unsigned short j;
	unsigned short convert;

	union {
		double val;                    
		unsigned char p[8];                
	}zone;                           

	zone.val = dValue;

	for (i = 0, j = 7; i < j; i++, j--)
	{
		convert = (zone.p[i] << 8) + zone.p[j];
		convert = htons(convert);
		zone.p[i] = convert >> 8;
		zone.p[j] = convert & 0x00ff;
	}

	return(zone.val);
#else
	return dValue;
#endif
}

/**
* @brief M�todo est�tico para converter double da rede para o host
* @param dValue - valor double convertido
* @return valor double normal
*/
double Encoding::NetworkToHostDouble(double dValue)
{
#if __BIG_ENDIAN
	unsigned short  i;                        
	unsigned short  j;                        
	unsigned short  convert;                     
 
    union {
        double val;                      
        unsigned char p[8];                    
    }zone;                        
 
    zone.val = dValue;
 
    for (i=0, j=7; i < j; i++, j--)
    {
        convert=(zone.p[i] << 8) + zone.p[j];
        convert=ntohs(convert);
        zone.p[i]=convert >> 8;
        zone.p[j]=convert & 0x00ff;
    }
 
    return(zone.val);      
#else
	return dValue;
#endif
}

