#pragma once


#include <iostream>
#include <string>
#include <ctime>
#include<algorithm>

#define chanceNull "";
using namespace std;

class Chance {
	public: void Load(bool isDebug) {
		string ans;
		string items[100] = {};
		time_t t;
		time(&t);
		srand(t);
		for (int i = 0; i < 100; i++) {

			if (i == 0) {
				items[i] = "Item5";
				continue;
			}
			else if (i > 0 && i <= 10) {
				items[i] = "Item4";
				continue;
			}
			else if (i > 10 && i <= 30) {
				items[i] = "Item3";
				continue;
			}
			else if (i > 30 && i <= 50) {
				items[i] = "Item2";
				continue;
			}
			else if(i > 50 && i <= 100){
				items[i] = "Item1";
				continue;
			}
			else {
				cout << i << endl;
				cout << "Error while looping!\n";
				break;
			}
		}
		random_shuffle(&items[0], &items[99]);
		cout << "Welcome To the chance game! There are 5 different items. The Items are:\n" << "Item5 which has a 1 in 100 chance of getting,\n" <<
			"Item4 which has a 1 in 10 chance of getting,\n" << "Item3 and Item2 which have a 1 in 20 chance of getting,\n" << "And finally Item1" <<
			" which has a 1 in 50 chance of getting.\n\nTo choose type anything!\n";

		cin >> ans;

		if (ans != "") {
			cout << "You got " << items[0] << "! Well done!!!" << endl;
		}
		else {
			cout << "Please enter something!\n";
			cin >> ans;
		}
	}
};