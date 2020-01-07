
#include "Socket.h"

typedef struct ListenSK {
	u_int fd_count;               /* how many are SET? */
	SOCKET  TYPE_SOCKET;   /* an array of SOCKETs */
} ListenSK;

//vector<SOCKET> T_check_client(vector<SOCKET> client_connect);
Socket::Socket(u_short port)
{
	printf(" \nInitialising Winsock... :%d", ListenSocket);
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf(" Failed.Error Code : % d ", WSAGetLastError());

	}

	printf(" Initialised.\n ");

	//Create a socket
	if ((ListenSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : % d", WSAGetLastError());
	}

	printf(" Socket created.\n ");

	server.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	server.sin_family = AF_INET;
	server.sin_port = htons(3333);

	bind(ListenSocket, (struct sockaddr*) & server, sizeof(struct sockaddr));

	listen(ListenSocket, 2);


}

SOCKET Socket::get_ListenSocket()
{
	return ListenSocket;
}
vector<SOCKET> Socket::get_client()
{
	return client_re;
}
void Socket::add_client(SOCKET& Newclient)
{
	client_re.push_back(Newclient);
}


//void Socket::Socket_Init(char* ip_server, u_short port)
//{
//	struct timeval timeout;
//	struct sockaddr_in server;
//	
//	printf(" \nInitialising Winsock... ");
//	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
//	{
//		printf(" Failed.Error Code : % d ", WSAGetLastError());
////		return 1;
//	}
//
//	printf(" Initialised.\n ");
//
//	//Create a socket
//	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
//	{
//		printf("Could not create socket : % d", WSAGetLastError());
//	}
//
//	printf(" Socket created.\n ");
//	/*timeout.tv_sec = 100;
//	timeout.tv_usec = 0;
//
//	if (setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout,
//		sizeof(timeout)) < 0)
//		printf("setsockopt failed\n");
//
//	if (setsockopt(s, SOL_SOCKET, SO_SNDTIMEO, (char*)&timeout,
//		sizeof(timeout)) < 0)
//		printf("setsockopt failed\n");*/
//
//	server.sin_addr.s_addr = inet_addr(ip_server);
//
//	server.sin_family = AF_INET;
//	server.sin_port = htons(port);
//	cout << "\nserver.sin_addr.s_addr" << server.sin_addr.s_addr << endl;
//	cout << "server.sin_addr.s_addr" << server.sin_addr.s_addr << endl;
//	cout << "server.sin_addr.s_addr" << server.sin_addr.s_addr << endl;
//	//Connect to remote server
//	if (connect(s, (struct sockaddr*) & server, sizeof(server)), 0)
//	{
//		puts("connect error");
////		return 1;
//	}
//
//	puts("Connected");
//}
//int  Socket::Socket_Server_Init(u_short port)
//{
//	WSADATA wsaData;
//	int iResult, iSendResult;
//
//	struct addrinfo* result = NULL;
//	struct addrinfo hints;
//	SOCKET ListenSocket = INVALID_SOCKET;
//	SOCKET ClientSocket = INVALID_SOCKET;
//	char recvbuf[DEFAULT_BUFLEN];
//	int recvbuflen = DEFAULT_BUFLEN;
//
//	char buffer[1024];
//	memset(buffer, 0, 1024);
//	printf(" \nInitialising Winsock... :%d", ListenSocket);
//	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
//	{
//		printf(" Failed.Error Code : % d ", WSAGetLastError());
//		return 1;
//	}
//
//	printf(" Initialised.\n ");
//
//	//Create a socket
//	if ((ListenSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
//	{
//		printf("Could not create socket : % d", WSAGetLastError());
//	}
//
//	printf(" Socket created.\n ");
//
//	server.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
//	server.sin_family = AF_INET;
//	server.sin_port = htons(port);
//
//	bind(ListenSocket, (struct sockaddr*) & server, sizeof(struct sockaddr));
//
//	listen(ListenSocket,2);
//	// Create the master file descriptor set and zero it
//	//typedef struct fd_set {
//	//	u_int fd_count;               /* how many are SET? */
//	//	SOCKET  fd_array[FD_SETSIZE];   /* an array of SOCKETs */
//	//} fd_set;
//
//	fd_set master;
//	
//	// Add our first socket that we're interested in interacting with; the listening socket!
//	// It's important that this socket is added for our server or else we won't 'hear' incoming
//	// connections 
//	FD_ZERO(&master);
//	FD_SET(ListenSocket, &master);
//	char buf[4096];
//	ZeroMemory(buf, 4096);
//	int i = 0;
//	//while (1) {
//	//	iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
//	//	if (iResult > 0) {
//	//		printf("Bytes received: %d\n", iResult);
//	//		// Echo the buffer back to the sender
//	//		iSendResult = send(ClientSocket, recvbuf, iResult, 0);
//	//		if (iSendResult == SOCKET_ERROR) {
//	//			printf("send failed with error: %d\n", WSAGetLastError());
//	//			closesocket(ClientSocket);
//	//			WSACleanup();
//	//			return 1;
//	//		}
//	//		printf("Bytes sent: %d\n", iSendResult);
//	//	}
//	//	else if (iResult == 0) {
//	//		printf("Connection closing...\n");
//	//		break;
//	//	}
//	//	else {
//	//		printf("recv failed with error: %d\n", WSAGetLastError());
//	//		closesocket(ClientSocket);
//	//		WSACleanup();
//	//		return 1;
//	//	}
//	//}
//
//	//cout << "Client connected!" << endl;
//	//printf("\ndest.sin_addr: %d", dest.sin_addr.S_un.S_un_b.s_b1);
//	//printf("\ndest.sin_addr: %d", dest.sin_addr.S_un.S_un_b.s_b2);
//	//printf("\ndest.sin_addr: %d", dest.sin_addr.S_un.S_un_b.s_b3);
//	//printf("\ndest.sin_addr: %d", dest.sin_addr.S_un.S_un_b.s_b4);
//	//struct sockaddr_in dst;
//	//dst.sin_addr.S_un.S_un_b.s_b1 = 192;
//	//dst.sin_addr.S_un.S_un_b.s_b2 = 168;
//	//dst.sin_addr.S_un.S_un_b.s_b3 = 100;
//	//dst.sin_addr.S_un.S_un_b.s_b4 = 55;
////	ClientSocketB=accept(ListenSocket, (struct sockaddr*) & dst, &socksize);
////	dst.sin_addr.S_un.S_un_b.s_b1
////	printf("\nIncoming connection from %s - sending welcome\n", inet_ntoa(dest.sin_addr));
//	bool check = true;
//	vector <SOCKET> client_save;
//	//check and control client via 2 thread created
//	while (1) {
//		
////		client_save = check_client( client_save);
//	}
//
//	
//	// shutdown the connection since we're done
//	iResult = shutdown(ClientSocket, SD_SEND);
//	if (iResult == SOCKET_ERROR) {
//		printf("shutdown failed with error: %d\n", WSAGetLastError());
//		closesocket(ClientSocket);
//		WSACleanup();
//		return 1;
//	}
//
//	// cleanup
//	closesocket(ClientSocket);
//	WSACleanup();
//
//
//	return 0;
//
//
//}
//
//int Socket::Socket_Server_Init_NEW(const char* port)
//{
//	WSADATA wsaData;
//	int iResult;
//
//	SOCKET ListenSocket = INVALID_SOCKET;
//	SOCKET ClientSocket = INVALID_SOCKET;
//
//	struct addrinfo* result = NULL;
//	struct addrinfo hints;
//
//	int iSendResult;
//	char recvbuf[DEFAULT_BUFLEN];
//	memset(recvbuf, 0, sizeof(recvbuf));
//	int recvbuflen = DEFAULT_BUFLEN;
//	
//	printf(" \nThis is the Socket of SEVER.\n  ");
//	// Initialize Winsock
//	printf(" \nInitialising Winsock ....\n  ");
//	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	if (iResult != 0) {
//		printf("WSAStartup failed with error: %d\n", iResult);
//		return 1;
//	}
//	printf(" Initialised.\n ");
//	//ADDED
//	ZeroMemory(&hints, sizeof(hints));
//	hints.ai_family = AF_INET;
//	hints.ai_socktype = SOCK_STREAM;
//	hints.ai_protocol = IPPROTO_TCP;
//	hints.ai_flags = AI_PASSIVE;
//
//	// Resolve the server address and port
//	//ADDED
//	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
//	if (iResult != 0) {
//		printf("Getaddrinfo failed with error: %d\n", iResult);
//		WSACleanup();
//		return 1;
//	}
//	fd_set read;
//
//	// Create a SOCKET for connecting to server
//	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
//	if (ListenSocket == INVALID_SOCKET) {
//		printf("Socket failed with error: %ld\n", WSAGetLastError());
//		freeaddrinfo(result);
//		WSACleanup();
//		return 1;
//	}
//	printf("Socket created.\n ");
//	// Setup the TCP listening socket
//	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
//	//ADDED from Docs.Microsoft
//	if (iResult == SOCKET_ERROR) {
//		printf("Bind failed with error: %d\n", WSAGetLastError());
//		freeaddrinfo(result);
//		closesocket(ListenSocket);
//		WSACleanup();
//		return 1;
//	}
//	printf("Setup the TCP listening socket finished!.\n ");
//	freeaddrinfo(result);
//
//	iResult = listen(ListenSocket, SOMAXCONN);
//	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
//		printf("Listen failed with error: %ld\n", WSAGetLastError());
//		closesocket(ListenSocket);
//		WSACleanup();
//		return 1;
//	}
////	iResult = listen(ListenSocket, 10);
//	//ADDED from Docs.Microsoft
//	if (iResult == SOCKET_ERROR) {
//		printf("listen failed with error: %d\n", WSAGetLastError());
//		closesocket(ListenSocket);
//		WSACleanup();
//		return 1;
//	}
//	// Add struct sockaddr_in dest to get IP's Client.
//	struct sockaddr_in dest;
//	socklen_t socksize = sizeof(struct sockaddr_in);
//	// Accept a client socket
//
//	ClientSocket = accept(ListenSocket, (struct sockaddr*) & dest, &socksize);
//	if (ClientSocket != INVALID_SOCKET)
//		printf("\nAccepted\n");
//	else{
//		printf("accept failed with error: %d\n", WSAGetLastError());
//		closesocket(ListenSocket);
//		WSACleanup();
//		return 1;
//	}
//	
//	// No longer need server socket
//	closesocket(ListenSocket);
//	//Printing the IP when Client'd to connect! 
//	printf("Incoming connection from %s - sending welcome\n", inet_ntoa(dest.sin_addr));
//	
//	cout << "Client connected!" << endl;
//	printf("\ndest.sin_addr: %d", dest.sin_addr.S_un.S_un_b.s_b1);
//	printf("\ndest.sin_addr: %d", dest.sin_addr.S_un.S_un_b.s_b2);
//	printf("\ndest.sin_addr: %d", dest.sin_addr.S_un.S_un_b.s_b3);
//	printf("\ndest.sin_addr: %d", dest.sin_addr.S_un.S_un_b.s_b4);
//	// Receive until the peer shuts down the connection
//	do {
//		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
//		if (iResult > 0) {
//			
//			dest.sin_addr.S_un.S_un_b.s_b1 = 192;
//			dest.sin_addr.S_un.S_un_b.s_b2 = 168;
//			dest.sin_addr.S_un.S_un_b.s_b3 = 100;
//			dest.sin_addr.S_un.S_un_b.s_b4 = 101;
//			printf("Data: %s\n", recvbuf);
//			cout << "Affter setting..!" << endl;
//			printf("\ndest.sin_addr: %d", dest.sin_addr.S_un.S_un_b.s_b1);
//			printf("\ndest.sin_addr: %d", dest.sin_addr.S_un.S_un_b.s_b2);
//			printf("\ndest.sin_addr: %d", dest.sin_addr.S_un.S_un_b.s_b3);
//			printf("\ndest.sin_addr: %d", dest.sin_addr.S_un.S_un_b.s_b4);
//
//			// Echo the buffer back to the sender
//			iSendResult = send(ClientSocket, recvbuf, iResult, 0);
//			if (iSendResult == SOCKET_ERROR) {
//				printf("send failed with error: %d\n", WSAGetLastError());
//				closesocket(ClientSocket);
//				WSACleanup();
//				return 1;
//			}
//			printf("Bytes sent: %d\n", iSendResult);
//		}
//		else if (iResult == 0) {
//			printf("Connection closing...\n");			
//		}
//		else {
//			if (ListenSocket) {
//				continue;
//			}
//			else {
//				printf("recv failed with error: %d\n", WSAGetLastError());
//				closesocket(ClientSocket);
//				WSACleanup();
//				return 1;
//			}
//		}
////		closesocket(ClientSocket);
//	}while (iResult > 0);
//
//	// shutdown the connection since we're done
//	iResult = shutdown(ClientSocket, SD_SEND);
//	if (iResult == SOCKET_ERROR) {
//		printf("shutdown failed with error: %d\n", WSAGetLastError());
//		closesocket(ClientSocket);
//		WSACleanup();
//		return 1;
//	}
//
//	// cleanup
//	closesocket(ClientSocket);
//	WSACleanup();
//
//
//	return 0;
//}

//
//int Socket::Socket_Send(char* data, uint16_t size)
//{
//	return send(s, data, size, 0);
//}
//
//int Socket::Socket_Recv(char* src, uint16_t size)
//{
//	return recv(s, src, size, 0);
//}
//while (check)
//{
//
//	fd_set copy = master;
//
//	vector<SOCKET> Client_JOIN;
//	// hàm select block chuong trình và sẽ tiep tuc sau khi đã duyệt nếu có sự kiện,sau khi lắng nghe và nhận sự kiện có connect từ client ==> trả về giá trị,ở đây nếu 1 client connect==> trả về giá trị =1
//	int socketCount = select(1, &copy, nullptr, nullptr, nullptr);
//	for (int i = 0; i < socketCount; i++)
//	{
//		// Makes things easy for us doing this assignment
//		SOCKET sock = copy.fd_array[i];
//
//
//		// Is it an inbound communication?
//		if (sock == ListenSocket)
//		{
//
//			cout << "\nsocketCount:" << socketCount << endl;
//			struct sockaddr_in dst;
//			socklen_t socksize = sizeof(struct sockaddr_in);
//			SOCKET client = accept(ListenSocket, (struct sockaddr*) & dst, &socksize);
//			printf("\nIncoming connection from %s - sending welcome\n", inet_ntoa(dst.sin_addr));
//			cout << "\nClient connected!" << endl;
//			printf("\ndst.sin_addr: %d", dst.sin_addr.S_un.S_un_b.s_b1);
//			printf("\ndst.sin_addr: %d", dst.sin_addr.S_un.S_un_b.s_b2);
//			printf("\ndst.sin_addr: %d", dst.sin_addr.S_un.S_un_b.s_b3);
//			printf("\ndst.sin_addr: %d\n", dst.sin_addr.S_un.S_un_b.s_b4);
//			// Accept a new connection
//
//
//			// Add the new connection to the list of connected clients
//			FD_SET(client, &master);
//
//			// Send a welcome message to the connected client
//			string welcomeMsg = "Welcome to the Awesome Chat Server!\r\n";
//			//				send(ClientSocket, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
//			send(client, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
//		}
//		else // It's an inbound message
//		{
//			//	char buf[4096];
//			//	ZeroMemory(buf, 4096);
//
//			//	// Receive message
//			int bytesIn = recv(sock, buffer, 512, 0);
//			printf("\nSOCK:%d said that:", sock);
//			printf("%s", buffer);
//			for (int i = 0; i < master.fd_count; i++)
//			{
//
//				SOCKET SENDSOCK = master.fd_array[i];
//				if (SENDSOCK != ListenSocket && SENDSOCK != sock)
//					send(SENDSOCK, buffer, strlen(buffer), 0);
//				if (bytesIn <= 0)
//				{
//					printf("\nSOCK:%d closed the socket!", sock);
//					// Drop the client
//					closesocket(sock);
//					FD_CLR(sock, &master);
//				}
//			}
//
//			//	//else
//			//	{
//			//	
//
//			//		// Send message to other clients, and definiately NOT the listening socket
//
//			//		for (int i = 0; i < master.fd_count; i++)
//			//		{
//			//			SOCKET outSock = master.fd_array[i];
//			//			if (outSock != ListenSocket && outSock != sock)
//			//			{
//			//				ostringstream ss;
//			//				ss << "SOCKET #" << sock << ": " << buf << "\r\n";
//			//				string strOut = ss.str();
//
//			//				send(outSock, strOut.c_str(), strOut.size() + 1, 0);
//			//			}
//			//		}
//			//	}
//			//}
////				printf("Bytes received: %d\n", iResult);
//				// Echo the buffer back to the sender
////				iSendResult = send(ClientSocket, buffer, strlen(buffer), 0);
//			/*	if (iSendResult == SOCKET_ERROR) {
//					printf("send failed with error: %d\n", WSAGetLastError());
//					closesocket(ClientSocket);
//					WSACleanup();
//					return 1;
//				}*/
//				//		//			printf("Bytes sent: %d\n", iSendResult);
//				//	}
//				//	else if (iResult == 0) {
//				//		printf("Connection closing...\n");
//				//		closesocket(ClientSocket);
//				//	}
//				//	else {
//				//		printf("The client tried to interrupt it off...\n");
//				//		printf("Recv failed with error: %d\n", WSAGetLastError());
//				//		closesocket(ClientSocket);
//				//		WSACleanup();
//				//		return 1;
//
//				//	}				
//			memset(buffer, 0, 1024);
//			//}
//
//		}
//	}
//
//}




/*printf("\nwaiting.... \n");


}	while (true)
	{
		recv(client_save[1], buf, 4096, 0);
		printf("\nSOCK:%d said that:%s", client_save[1], buf);
		send(client_save[0], buf, strlen(buf), 0);
		break;



	}
	while (true) {
		if (recv(client_save[0], buf, 4096, 0) > 0) {
			printf("\nSOCK:%d said that:%s", client_save[0], buf);
			send(client_save[1], buf, strlen(buf), 0);
		}


	}*/
	//	ZeroMemory(buf, 4096);



		//				while (check_msg) {
		//					int bytesIn = recv(client_save[0], buf, 4096, 0);
		//					int bytesIn1 = recv(client_save[1], buf, 4096, 0);
		//
		//					if (bytesIn > 0) {
		//						printf("\nSOCK:%d said that:", client_save[0]);
		//						printf("%s", buf);
		//						send(client_save[1], buf, strlen(buf), 0);
		//						ZeroMemory(buf, 4096);
		////						check_msg = false;
		//					}
		//				
		//					if (bytesIn1 > 0) {
		//						printf("\nSOCK1:%d said that:", client_save[1]);
		//						printf("%s", buf);
		//						send(client_save[0], buf, strlen(buf), 0);
		//						ZeroMemory(buf, 4096);// check_msg = false;
		//					}
		//					check_msg = false;
		//					
		//				}


					/*for (int i = 0; i < master.fd_count; i++)
					{

						SOCKET SENDSOCK = master.fd_array[i];
						if (SENDSOCK != ListenSocket && SENDSOCK != client)
							send(SENDSOCK, buffer, strlen(buffer), 0);

					}*/
