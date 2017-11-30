// AI Test 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "lotto.h"

using namespace std;

int main()
{

	ifstream userinfo("C:/Program Files/AI Test/info.txt");
	ofstream adduserinfo("C:/Program Files/AI Test/info.txt", fstream::app);
	string name;
	string optionchoice;

	cout << "Welcome to AI Test\n";
	cout << "Version: 0.5.5\n";
	userinfo >> name;
	if (name != "") {
		cout << "Hello " << name << "! What would you like to do?\n";
	}
	else {
		cout << "Looks like you're new! What's your name?\n";
		cin >> name;
		if (name == "") {
			cout << "I need to call you something! What would you like me to call you?\n";
			cin >> name;
			if (name == "") {
				cout << "Ok. If you want to name yourself later, just tell me\n";
			}
			else {
				adduserinfo << name;
				cout << "Hello " << name << "! What would you like to do?\n";
			}
		}
		else {
			adduserinfo << name;
			cout << "Hello " << name << "! What would you like to do?\n";
		}
	}
	while (true) {
		cin >> optionchoice;
		transform(optionchoice.begin(), optionchoice.end(), optionchoice.begin(), tolower);
		if (optionchoice != "") {
			if (optionchoice.find("lotto") || optionchoice.find("lottery")) {
				if (!PlayLotto()) {
					cout << "Now that you've played the lotto, what would you like to do?\n";
				}
			}
			else if (optionchoice.find("help")) {
				cout << "Seems like you need a bit of help... Here's a list of the things you can do:\n1. You can play our mini-lottery game\n";
			}
			else if (optionchoice.find("exit") || optionchoice.find("leave")) {
				cout << "Goodbye, have a nice day";
				break;
			}
			else if ((optionchoice.find("turn") && optionchoice.find("on")) && ((optionchoice.find("food") || optionchoice.find("oven")) || (optionchoice.find("tv") || optionchoice.find("television")) || optionchoice.find("lights"))) {
				cout << "This feature is currently unavailable. Ideas to make it work: Special Plug - Can connect to WiFi, Integration into appliances, Special switches for lights\n";
			}
			else {
				cout << "Sorry, that's not a suitable command. If you need help, all you need to do is ask\n";
			}
		}
		else {
			cout << "If you don't want me to do anything, just tell me.\n";
		}
	}
	system("PAUSE");
	userinfo.close();
	adduserinfo.close();
	return 0;
}

vector<string> split(string stringToSplit);

vector<string> split(string stringToSplit) {
	string buf;
	stringstream ss(stringToSplit);
	vector<string> stringSplit;
	while(ss >> buf)
		stringSplit.push_back(buf);
	return stringSplit;
}

