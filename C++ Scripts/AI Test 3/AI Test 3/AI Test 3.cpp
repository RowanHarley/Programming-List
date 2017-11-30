// AI Test 3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Learner.h"
#include <string>

using namespace std;

int main(){
	Learner AI;

	for (;;) {
		cout << "\nYOU: ";
		string phrase;
		cin >> phrase;

		cout << "COMPUTER: ";
		AI.respond(phrase);
	}
	return 0;
}