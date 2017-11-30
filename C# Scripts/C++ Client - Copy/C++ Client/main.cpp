#include <iostream>
#include <winsock.h>
#include <Windows.h>

#pragma comment (lib, "ws2_32.lib")

SOCKET sConnect;
SOCKADDR_IN addr;

using namespace std;

int Startup_WinSock() {
	WSADATA wsaData;
	WORD DllVersion = MAKEWORD(2, 1);

	int val = WSAStartup(DllVersion, &wsaData);

	return val;
}

int ClientThread() {
	char *Buffer = new char[256];
	int size = 0;

	while (true) {
		ZeroMemory(Buffer, 256);
		if ((size = recv(sConnect, Buffer, 256, NULL)) > 0) {
			cout << Buffer << endl;
		}
		Sleep(50);
	}
}

int main() {
	int val = Startup_WinSock();

	if (val != 0) {
		cout << "Can't start up WinSock!" << endl;
		exit(1);
	}

	sConnect = socket(AF_INET, SOCK_STREAM, NULL);

	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(2222);
	addr.sin_family = AF_INET;

	cout << "Please Press [ENTER]" << endl;
	cin.get();

	if (val != 0) {
		cout << "Can't reach server!" << endl;
		main();
	}
	else {
		system("cls");

		int ID;
		char *nID = new char[64];
		char *hello = new char[64];

		ZeroMemory(hello, 64);
		ZeroMemory(nID, 64);

		recv(sConnect, nID, 64, NULL);
		recv(sConnect, hello, 64, NULL);

		ID = atoi(nID);
		cout << hello << endl;
		cout << "Your ID: " << ID << endl;
		cout << "If you are ready press [ENTER] again." << endl;
		cin.get();

		system("cls");

		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientThread, NULL, NULL, NULL);

		while (true) {
			char *MSG = new char[256];

			ZeroMemory(MSG, 256);

			cin.getline(MSG, 256);

			send(sConnect, MSG, 256, NULL);

			Sleep(50);

		}
	}
	return 0;
}
