#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifdef _WIN32_WCE
#define _WCE_SECTION
#endif

#ifdef _WCE_SECTION
#pragma comment(lib,"ws2.lib")
#else
#pragma comment (lib, "ws2_32.lib")
#endif


#include <windows.h>
#include <stdlib.h>
#include "ClientNetwork.h"

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

	printf("********************************************\n");
	printf("       GRUPO DE REABILITACAO ROBOTICA       \n");
	printf("     ESCOLA DE ENGENHARIA DE SAO CARLOS     \n");
	printf("          UNIVERSIDADE DE SAO PAULO         \n");
	printf("********************************************\n");
	printf("          ROBO DE REABILITACAO: V1.0        \n");
	printf("********************************************\n\n");


	ClientNetwork client = ClientNetwork();
	client.Open();


	system("PAUSE");

	return EXIT_SUCCESS;
}
