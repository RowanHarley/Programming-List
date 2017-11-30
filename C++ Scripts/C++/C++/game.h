#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;


class Game {
	bool MainMenu() {

	}
	void Register() {

	}
	void EndGameScreen() {

	}
	void PlayGameScreen() {

	}
	bool IsLoggedIn() {
		if (loadData("users") == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	void saveData(int numToSave) {
		FILE* f = fopen("game.txt", "w");
		if (f == NULL) {
			cout << "cant save data";
			return;
		}
		//write some data (as integer) to file
		fprintf(f, "%d\n", numToSave);

		fclose(f);
	}
	int loadData(string FileName) {
		int login;
		string ending = ".gamefile";
		FILE* f = fopen((FileName.c_str() + ending.c_str), "r");
		if (f == NULL) {
			cout << "cant open file";
			return NULL;
		}
		//load data from file, fscanf return the number of read data
		//so if we reach the end of file (EOF) it return 0 and we end
		while (fscanf(f, "%d", &login) == 1) {
			return login;
		}

		fclose(f);

	}
	int loadData(string FileName, string user, string pass) {
		string login;
		string ending = ".gamefile";
		FILE* f = fopen((FileName.c_str() + ending.c_str), "r");
		if (f == NULL) {
			cout << "cant open file";
			return NULL;
		}
		//load data from file, fscanf return the number of read data
		//so if we reach the end of file (EOF) it return 0 and we end
		string dataPass;
		while (fscanf(f, "%d %d", &dataPass) == 1) {
			if (dataPass == pass) {
				return 1;
			}
			else {
				return 0;
			}
		}

		fclose(f);

	}
	void SystemLogin() {
		for (;;) {
			string user;
			string pass;
			system("cls");
			cout << "Username: ";
			cin >> user;
			cout << "Password: ";
			cin >> pass;

			if (loadData(user, user, pass)) {
				saveData(1);
				break;
			}
			else {
				cout << "Invalid Username/Password!" << endl;
			}
		}
	}
	public: void Load() {
		if (IsLoggedIn()) {
			while (MainMenu()) {

			}
		}
		else {
			SystemLogin();
		}
	}
};
