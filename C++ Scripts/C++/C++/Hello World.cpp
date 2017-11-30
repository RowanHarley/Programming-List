// Hello World.cpp : main project file.

#include "stdafx.h"

#include "MoreProbability.h"

#include "moneyGame.h"
#include "mathshelp.h"
#include "speech.h"
#include "search.h"
#include "Chance.h"
#include "guessingGame.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	for (;;) {
		string str;
		string debug;
		bool isDebug;

		cout << "Hello World!\n";

		system("pause");
		cout << "Do you want to use debug mode (Y\N)? ";
		cin >> debug;
		if (debug == "Y" || debug == "y") {
			isDebug = true;
		}
		else if (debug == "N" || debug == "n") {
			isDebug = false;
		}
		else {
			cout << debug << " is not a valid answer!" << endl;
			cin >> debug;
		}
		std::cout << "To view maths help, type M,\nTo view Speech, type S,\nTo view Search, type SE,\nOr to exit type E\n";
		std::cin >> str;

		if (str == "S" || str == "s") {
			system("cls");
			SpeechTest s;
			s.Load(isDebug);
		}
		else if (str == "M" || str == "m") {
			system("cls");
			Test t;
			t.Load(isDebug);
		}
		else if (str == "E" || str == "e") {
			break;
		}
		else if (str == "C" || str == "c") {
			system("cls");
			Chance c;
			c.Load(isDebug);
		}
		else if (str == "P" || str == "p") {
			system("cls");
			MoreProbability p;
			p.Load(isDebug);
		}
		else if (str == "MG" || str == "mg" || str == "Mg" || str == "mG") {
			system("cls");
			Game g;
			g.Load(isDebug);
		}
		else if (str == "GG" || str == "gg" || str == "Gg" || str == "gG") {
			system("cls");
			guessingGame g;
			g.Load(isDebug);
		}
		else if (str == "SE" || str == "se" || str == "Se" || str == "sE") {
			system("cls");
			Search search;
			search.Load(isDebug);
		}
	}

	return 0;
}


