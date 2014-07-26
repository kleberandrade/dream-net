/* The MIT License (MIT)
*
* Copyright (c) 2014 Dream Net
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of
* this software and associated documentation files (the "Software"), to deal in
* the Software without restriction, including without limitation the rights to
* use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
* the Software, and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
* FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
* IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
*/

#ifndef TCPCLIENT_H
#define	TCPCLIENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef _WIN32_WCE
#define _WCE_SECTION
#define DebugLog(...)				NKDbgPrintfW(L __VA_ARGS__)
#else
#define DebugLog(...)				printf(__VA_ARGS__)
#endif

#ifdef _WCE_SECTION
#pragma comment(lib,"ws2.lib")
#else
#pragma comment (lib, "ws2_32.lib")
#endif

#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>  
#include <time.h> 


#define DEFAULT_FAMILY		AF_UNSPEC
#define DEFAULT_SOCKTYPE    SOCK_STREAM
#define NETWORK_ERROR		1
#define SLEEP_TIME			20
#define SERVER_PORT			12322
#define SERVER_ADDRESS		"127.0.0.1"

class TCPClient
{
public:
	TCPClient(void);
	~TCPClient(void);

private:
	static DWORD WINAPI Sender(LPVOID param);
	static DWORD WINAPI Receiver(LPVOID param);

	int iResult;							/* For error checking function calls in Winsock library */
	SOCKET client;							/* Socket for client to connect to server */
	WSADATA wsaData;						/* Structure for WinSock setup communication */
	SOCKADDR_IN service;
	DWORD sendId, recvId;
};

#endif /* TCPCLIENT_H */
