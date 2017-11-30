#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

void saveData(int numToSave);
int loadData();

void Play() {
	int coins = loadData();
	int ans;
	cout << "You have " << coins << " coins." << endl;

	cout << "How much do you want to spend? ";
	cin >> ans;

	if (loadData() >= ans && ans > 20) {
		coins = coins - ans;
		system("cls");
		cout << "Ok, you've put down " << ans << " coins.\n"
			 <<"The top prize is " << ans * 5 << " which is 5 times the amount of you're bet!\n" 
			 << "You can also win 3 times your bet, or even your bet back.\n"
			 << "But you may also win nothing!\n" 
			 << "To find out what you won press any key" 
			 << endl;

		system("pause");
		int winnings;
		int percentage = 1 + rand() % 100;
		if (percentage == 1) {
			winnings = ans * 5;
			cout << "Well done!!!! You won " << winnings << " coins!" << endl;
			saveData(coins + winnings);
		}else if(percentage > 1 && percentage <= 11){
			winnings = ans * 3;
			cout << "Well done!!!! You won " << winnings << " coins!" << endl;
			saveData(coins + winnings);
		}
		else if (percentage > 11 && percentage <= 50) {
			winnings = ans;
			cout << "Well, you got your " << winnings << " coins back, I guess." << endl;
			saveData(coins + winnings);
		}
		else {
			winnings = 0;
			cout << "Well, you cant win them all I guess. You won " << winnings << " coins." << endl;
			saveData(coins + winnings);

		}
	}
	else if(loadData() < ans) {
		cout << "You don't have enough money to spend!\n";
		cin >> ans;
	}
	else if (ans < 20) {
		cout << "You must bet more than 20!\n";
		cin >> ans;
	}
}


void Buy() {
	cout << "You are now Buying!" << endl;
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
int loadData() {
	int data1;
	FILE* f = fopen("game.txt", "r");
	if (f == NULL) {
		cout << "cant open file";
		return NULL;
	}
	//load data from file, fscanf return the number of read data
	//so if we reach the end of file (EOF) it return 0 and we end
	while (fscanf(f, "%d", &data1) == 1) {
		return data1;
	}

	fclose(f);

}
class Game {
	public: void Load(bool isDebug) {
		srand(time(0));
		int ans;
		cout << "Welcome to the game! What Would you like to do?" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "                              1. Start Playing!!!                              " << endl;
		cout << "                               2. Buy Some Coins                               " << endl;
		cout << "                                    3. Exit                                    " << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		cin >> ans;

		switch (ans) {
			case 1:
				Play();
				break;
			case 2:
				Buy();
				break;
			case 3:
				exit(0);
				break;
			default:
				cout << "Thats not a valid answer";
				break;
		}
	}
};