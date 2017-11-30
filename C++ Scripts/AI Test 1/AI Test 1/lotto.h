#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <algorithm>

using namespace std;

bool PlayLotto() {
	const int size = 7;
	int playernumbers[size];
	int drawednumbers[size];
	int count = 0;
	int luckynumbers = 0;

	for (int i = 0; i < 5; i++)
		drawednumbers[i] = rand() % 50;

	for (int i = 5; i < 7; i++)
		drawednumbers[i] = rand() % 12;

	for (int i = 0; i < 5; i++)
		playernumbers[i] = rand() % 50;

	for (int i = 5; i < 7; i++)
		playernumbers[i] = rand() % 12;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (drawednumbers[i] == playernumbers[j]) {
				count++;
				break;
			}
		}
	}
	for (int i = 5; i < 7; i++) {
		for (int j = 5; j < 7; j++) {
			if (drawednumbers[i] == playernumbers[j]) {
				luckynumbers++;
				break;
			}
		}
	}
	sort(drawednumbers, drawednumbers + 5);
	sort(drawednumbers + 6, drawednumbers + 7);
	sort(playernumbers, playernumbers + 5);
	sort(playernumbers + 6, playernumbers + 7);
	cout << "Winning Numbers: " << drawednumbers[0] << " " << drawednumbers[1] << " " << drawednumbers[2] << " " << drawednumbers[3] << " " << drawednumbers[4] << "   Lucky Numbers: " << drawednumbers[5] << " " << drawednumbers[6] << "\n";
	cout << "Your Numbers: " << playernumbers[0] << " " << playernumbers[1] << " " << playernumbers[2] << " " << playernumbers[3] << " " << playernumbers[4] << "   Lucky Numbers: " << playernumbers[5] << " " << playernumbers[6] << "\n";

	if (count == 0 && luckynumbers == 0) {
		cout << "Hard Luck! Better luck next time!\n";
	}
	else if (count == 1 && luckynumbers == 0) {
		cout << "You matched 1 number... Alright...\n";
	}
	else if (count == 2 && luckynumbers == 0) {
		cout << "You matched 2 numbers... Not too bad!\n";
	}
	else if (count == 0 && luckynumbers == 1) {
		cout << "You got one of the lucky numbers! Well done!\n";
	}
	else if (count == 2 && luckynumbers == 1) {
		cout << "You got a lucky number as well as matching 2 other numbers! Well done!\n";
	}
	else if (count == 0 && luckynumbers == 2) {
		cout << "You matched 2 lucky numbers! Good Job!\n";
	}
	else if (count == 2 && luckynumbers == 2) {
		cout << "You matched 2 lucky numbers and 2 other numbers! That's hard!\n";
	}
	else if (count == 3 && luckynumbers == 0) {
		cout << "You matched 3 numbers... Great!\n";
	}
	else if (count == 4 && luckynumbers == 0) {
		cout << "You matched 4 numbers! Wow!\n";
	}
	else if (count == 5 && luckynumbers == 0) {
		cout << "You matched 5 numbers! Just missed out on those lucky numbers!\n";
	}
	else if (count == 3 && luckynumbers == 1) {
		cout << "You matched 3 numbers and 1 lucky one!\n";
	}
	else if (count == 3 && luckynumbers == 2) {
		cout << "You matched 3 numbers and 2 lucky ones! Well done!\n";
	}
	else if (count == 4 && luckynumbers == 1) {
		cout << "You matched 4 numbers and 1 lucky one!\n";
	}
	else if (count == 4 && luckynumbers == 2) {
		cout << "You matched 4 numbers and 2 lucky ones! Very Lucky!\n";
	}
	else if (count == 5 && luckynumbers == 1) {
		cout << "You matched 5 numbers and 1 lucky number! So close to the jackpot!\n";
	}
	else if (count == 5 && luckynumbers == 2) {
		cout << "Well done! You've won the JACKPOT!!!\n";
	}
	cout << "Would you like to try again?\n";
	string ans;
	cin >> ans;
	transform(ans.begin(), ans.end(), ans.begin(), tolower);
	if (ans == "ya" || ans == "yes" || ans == "sure") {
		PlayLotto();
	}
	else {
		return false;
	}
}