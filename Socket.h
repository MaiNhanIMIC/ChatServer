
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define DEFAULT_BUFLEN 512

#include "stdio.h"
#include "stdint.h"
#include "Winsock2.h";
#include "Ws2tcpip.h"
#include "Ws2def.h"
#include <stdlib.h> 
#include <string.h> 
#include<iostream>
#include <sstream>
#include<vector>
using namespace std;
#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#define DEFAULT_BUFLEN 512
#include <errno.h>
#include "stdio.h"
#include "stdint.h"
#include "Winsock2.h";
#include "Ws2tcpip.h"
#include "Ws2def.h"
#include <stdlib.h> 
#include <string.h> 
#include<iostream>
#include <sstream>
#include<vector>
#include<thread>
using namespace std;
#undef UNICODE



// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "3333"


//#include <stdio.h> 
//#include <sys/socket.h> 
//#include <arpa/inet.h> 
//#include <unistd.h> 
//#include <string.h> 

class Socket
{
public:
	Socket(u_short port);
	SOCKET get_ListenSocket();
	vector<SOCKET> get_client();
	void add_client(SOCKET& Newclient);
private:
	vector<SOCKET> client_re;
	WSADATA wsa;
	struct sockaddr_in client;
	struct sockaddr_in server;
	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;
};
