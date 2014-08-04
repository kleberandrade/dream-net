#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

// #define __BIG_ENDIAN
#define __LITTLE_ENDIAN

#ifdef _WCE_SECTION
#pragma comment(lib,"ws2.lib")
#else
#pragma comment (lib, "Ws2_32.lib")
#endif

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ClientNetwork.h"
#include "Buffer.h"
#include "BufferDecode.h"
#include "BufferEncode.h"

#ifdef _WCE_SECTION
/**
	hInstance: HANDLE TO AN INSTANCE.  This is the "handle" to YOUR PROGRAM ITSELF.
	hPrevInstance: USELESS on modern windows (totally ignore hPrevInstance)
	lpCmdLine: Command line arguments.  similar to argv in standard C programs
	nCmdShow: Start window maximized, minimized, etc.
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow){
#else
int __cdecl main(int argc, char **argv){
#endif

	printf("********************************************************************************\n");
	printf("                        GRUPO DE REABILITACAO ROBOTICA                          \n");
	printf("                      ESCOLA DE ENGENHARIA DE SAO CARLOS                        \n");
	printf("                           UNIVERSIDADE DE SAO PAULO                            \n");
	printf("********************************************************************************\n");
	printf("                           ROBO DE REABILITACAO: V1.0                           \n");
	printf("********************************************************************************\n\n");


/**************************************************************************
			Teste da classe TCPClient e NetworkServices

	TCPClient client = TCPClient("127.0.0.1", 13000, 0, 1);
	client.InitializeSockets();
	client.Open();

	for (int i = 0; i < 5; i++)
	{
		if (!client.IsOpen())
			break;

		char message[256];
		printf("Digite uma mensagem: ");
		gets(message);

		//int iResult = client.Send(message, strlen(message));
		int iResult = client.Send(message, 256);
		printf("%d bytes enviados.\n", iResult);

		char buffer[256];
		iResult = client.Receiver(buffer, 256);
		printf("Receive: %s\n", buffer);
	}

	client.Close();

	printf("Client disconnect...\n");
*/

/***************************************************************************
			Teste da classe Buffer
	
	Buffer buffer1 = Buffer();
	printf("Buffer 1 (vazio): %s\n", buffer1.GetBuffer());

	Buffer buffer2 = Buffer("Kleber");
	printf("Buffer 2 (Kleber): %s\n", buffer2.GetBuffer());

	buffer2.Clear();
	printf("Buffer 2 (vazio): %s\n", buffer2.GetBuffer());

	buffer1.SetBuffer("Kleber Andrade");
	printf("Buffer 1 (Kleber Andrade): %s\n", buffer1.GetBuffer());

*/

/***************************************************************************
			Teste das classes BufferDecode, BufferEncode e Encoding

	double doubleToEncode = 999.564;
	float floatToEncode = 100.12f;
	int intToEncode = 50;
	int int2ToEncode = 36;

	printf("Values: %Lf | %d | %f | %d\n", doubleToEncode, intToEncode, floatToEncode, int2ToEncode);

	BufferEncode encode = BufferEncode();
	encode.EncodeDouble(doubleToEncode);
	encode.EncodeInt(intToEncode);
	encode.EncodeFloat(floatToEncode);
	encode.EncodeInt(int2ToEncode);
	
	printf("Buffer (encode): %s\n", encode.GetBuffer());

	char bufferToDecode[BUFFER_SIZE];
	memcpy(&bufferToDecode, encode.GetBuffer(), BUFFER_SIZE);

	printf("Copy Buffer (encode): %s\n", bufferToDecode);

	BufferDecode decode = BufferDecode(bufferToDecode);
	double doubletoDecode = decode.DecodeDouble();
	int intToDecode = decode.DecodeInt();
	float floatToDecode = decode.DecodeFloat();
	int int2ToDecode = decode.DecodeInt();

	printf("Buffer (decode): %s\n", decode.GetBuffer());

	printf("Values: %Lf | %d | %f | %d\n", doubletoDecode, intToDecode, floatToDecode, int2ToDecode);

*/

/***************************************************************************
	Teste das classes trabalhando junto:
		NetworkServices
		TCPClient
		Buffer
		BufferDecode
		BufferEncode
		Encoding
	
	TCPClient client = TCPClient("127.0.0.1", 13000, 0, 1);
	client.InitializeSockets();
	client.Open();

	for (int i = 0; i < 3; i++)
	{
		if (!client.IsOpen())
			break;

		printf("Digite um int: ");
		int intTosend;
		scanf("%d", &intTosend);

		printf("Digite um double: ");
		double doubleToSend;
		scanf("%Lf", &doubleToSend);

		BufferEncode encode = BufferEncode();
		encode.EncodeInt(intTosend);
		encode.EncodeDouble(doubleToSend);

		char message[BUFFER_SIZE];
		memcpy(&message, encode.GetBuffer(), BUFFER_SIZE);

		int iResult = client.Send(message, 256);
		printf("%d bytes enviados.\n", iResult);

		char buffer[256];
		iResult = client.Receiver(buffer, 256);

		BufferDecode decode = BufferDecode(buffer);
		int iValor = decode.DecodeInt();
		double dValor = decode.DecodeDouble();

		printf("Receive: %s | Int: %d | Double: %Lf\n", buffer, iValor, dValor);
	}
	

	//client.ShutdownSocket();
	client.Close();

	printf("Client disconnect...\n");
	
*/


	ClientNetwork client = ClientNetwork();
	client.SetDispatcher(new RobotDispatcherMessage);
	client.SetRequest(new GameRequestMessage);
	client.Open();

	int cont = 0;
	clock_t start,
		stop;

	while (client.IsOpen())
	{
		start = clock();

		// Define as informações do robo
		((RobotDispatcherMessage*)client.GetDispatcherData())->SetStatus(cont);
		((RobotDispatcherMessage*)client.GetDispatcherData())->SetPosition(cont * 10.0);

		// Envia e recebe dados pela rede
		client.Send();
		client.Receive();

		// Recebe os dados nas variáveis
		double position = ((GameRequestMessage*)client.GetRequestData())->GetPosition();
		double stiffness = ((GameRequestMessage*)client.GetRequestData())->GetStiffness();
		double velocity = ((GameRequestMessage*)client.GetRequestData())->GetVelocity();
		double acceleration = ((GameRequestMessage*)client.GetRequestData())->GetAcceleration();
		int control = ((GameRequestMessage*)client.GetRequestData())->GetControl();

		stop = clock();

		//Exibe as informações na tela
		system("CLS");
		printf("ROBOT #######################\n");
		printf("Status: %d\n", cont);
		printf("Position: %Lf\n", cont * 10.0);
		
		printf("\nGAME ########################\n");
		printf("Position: %Lf\n", position);
		printf("Stiffness: %Lf\n", stiffness);
		printf("Velocity: %Lf\n", velocity);
		printf("Acceleration: %Lf\n", acceleration); 
		printf("Control: %d\n", control);


		printf("Tempo %.3f (ms)\n", ((double)(stop - start) / CLOCKS_PER_SEC));

		// Atualiza o contador
		cont++;
	}

	client.Close();

	system("PAUSE");

	return EXIT_SUCCESS;
}

