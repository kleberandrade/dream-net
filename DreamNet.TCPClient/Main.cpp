#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
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

	ClientNetwork client = ClientNetwork("127.0.0.1", 13000);
	client.SetDispatcher(new RobotDispatcherMessage);
	client.SetRequest(new GameRequestMessage);
	client.Open();

	int angle = 0;
	int direction = -1;

	clock_t start,
		stop;

	while (client.IsOpen())
	{
		start = clock();

		// Define as informações do robo
		((RobotDispatcherMessage*)client.GetDispatcherData())->SetStatus(0);
		((RobotDispatcherMessage*)client.GetDispatcherData())->SetPosition(angle);

		if (direction == -1)
			angle -= 5;
		else
			angle += 5;

		if (abs(angle) >= 90)
			direction *= (-1);

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
		
		//Exibe as informações enviadas e recebidas
		system("CLS");
		printf("ROBOT #######################\n\n");
		printf("Status: %d\n", 0);
		printf("Position: %d\n", angle);

		printf("\nGAME ########################\n");
		printf("Position: %Lf\n", position);
		printf("Stiffness: %Lf\n", stiffness);
		printf("Velocity: %Lf\n", velocity);
		printf("Acceleration: %Lf\n", acceleration); 
		printf("Control: %d\n", control);
		
		printf("\nTempo %.3f (ms)\n", ((double)(stop - start) / CLOCKS_PER_SEC));
	}

	client.Close();

	system("PAUSE");

	return EXIT_SUCCESS;
}

