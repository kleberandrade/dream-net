#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif


#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifdef _WIN32_WCE
#define _WCE_SECTION
#endif

#ifdef _WCE_SECTION
#pragma comment(lib,"ws2.lib")
#else
#pragma comment (lib, "Ws2_32.lib")
#endif


#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "ClientNetwork.h"
#include "RequestMessage.h"

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


	//ClientNetwork client = ClientNetwork();
	
	//client.Open();

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

	system("PAUSE");

	return EXIT_SUCCESS;
}
