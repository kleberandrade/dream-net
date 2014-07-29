#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include "TCPClient.h"

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


	TCPClient client = TCPClient();
	client.Connect();


	return EXIT_SUCCESS;
}
