#include <winsock.h>
#include <iostream>
#include <Windows.h>

using namespace std;

#pragma comment (lib, "ws2_32.lib")

SOCKADDR_IN addr;
int addrLen = sizeof(addr);

int counter;
SOCKET sConnect;
SOCKET sListen;
SOCKET *Connections;

int InitWinSock() {
	int val = 0;
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	val = WSAStartup(DllVersion, &wsaData);

	return val;
}

int ServerThread(int ID) {
	char *buffer = new char[256];
	char *Buffer = new char[256];
	int size = 0;

	while (true) {
		ZeroMemory(Buffer, 256);
		if ((size = recv(Connections[ID], Buffer, 256, NULL)) > 0) {

			for (int i = 0; i < counter; i++) {
				if (Connections[i] == Connections[ID]) {
					ZeroMemory(buffer, 256);

					sprintf_s(buffer, sizeof(buffer), "Client[%i]: %s", ID, Buffer);
					cout << "New Message: " << buffer << endl;
				}
				else 
				{
					ZeroMemory(buffer, 256);

					sprintf_s(buffer, sizeof(buffer), "Client[%i]: %s", ID, Buffer);
					send(Connections[i], Buffer, 256, NULL);
				}
			}
			

		}
	}
}

int main() {

	cout << "Server Started!" << endl;
	int Val = InitWinSock();

	if (Val != 0) {
		MessageBoxA(NULL, "Error while attempting to startup WinSock!", "Error!", MB_OK | MB_ICONERROR);
		exit(1);
	}
	Connections = (SOCKET*)calloc(64, sizeof(SOCKET));

	sListen = socket(AF_INET, SOCK_STREAM, NULL);
	sConnect = socket(AF_INET, SOCK_STREAM, NULL);

	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(2222);
	addr.sin_family = AF_INET;

	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));

	listen(sListen, 64);

	while (true) {
		if (sConnect = accept(sListen,(SOCKADDR*)&addr, &addrLen)) {
			Connections[counter] = sConnect;

			char *Name = new char[64];

			ZeroMemory(Name, 64);

			send(Connections[counter],Name, 64, NULL);
			send(Connections[counter], "Welcome to my server!", 64, NULL);

			sprintf_s(Name, sizeof(Name), "%i", counter);

			cout << "New Connection!\n";
			counter++;

			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ServerThread, (LPVOID)(counter - 1), NULL, NULL);
		}
		Sleep(50);
	}
	return 0;
}