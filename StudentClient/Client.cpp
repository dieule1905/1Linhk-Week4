#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<winsock.h>
using namespace std;

int main() {
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}
	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(12345);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		MessageBoxA(NULL, "Failed to connect", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}
	cout << "Connected!" << endl;
	char mesRecv[1000];
	char  mesSend[1000];
	
	while (true) {
		recv(Connection, mesRecv, sizeof(mesRecv), NULL);
		cout << mesRecv;
		cin >> mesSend;
		send(Connection, mesSend, sizeof(mesSend), NULL);
		
	}
	system("pause");
	return 0;

}