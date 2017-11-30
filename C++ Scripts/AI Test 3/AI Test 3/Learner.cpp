#include "Learner.h"
#include <iostream>
#include <fstream>
// #include <string>

using namespace std;



void Learner::respond(string phrase)
{
	fstream memory;
	memory.open("memory/memory.txt", ios::in);
	while ( !memory.eof() ) {
		string identifier;
		getline(memory, identifier);

		if (identifier == phrase) {
			string response;
			getline(memory, response);
			Voice.say(response);
			return;
		}
	}
	memory.close();
	memory.open("memory/memory.txt", ios::out | ios::app);
	memory << phrase << endl;

	Voice.say(phrase);
	string userResponse;
	cout << "YOU: ";
	getline(cin, userResponse);
	memory << userResponse << endl;
	memory.close();
}

void Learner::say(string phrase) {
	this->voice.say(phrase);
}

