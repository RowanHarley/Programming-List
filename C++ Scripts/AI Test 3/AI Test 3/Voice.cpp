#include "Voice.h"
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

void Voice::say(string phrase) {
	string command = "espeak \"" + phrase + "\"";
	const char* charCommand = command.c_str();
	cout << phrase << endl;
	system(charCommand);
}