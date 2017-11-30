#pragma once

#include <iostream>

#include <string>

using namespace std;
using namespace System;
using namespace System::Speech::Synthesis;
using namespace System::Speech::Recognition;

class SpeechTest {

	SpeechRecognitionEngine SpeechRecognized(SpeechRecognizedEventArgs ^a) {
		if (a->Result->Text == "Exit") {
			exit(0);
		}
		if(a->Result->Text == "Hello"){
			SpeechSynthesizer s;
			s.Speak("Hello, How are you?");
		}
		if (a->Result->Text == "fine") {
			SpeechSynthesizer s;
			s.Speak("Thats Great!");
		}
		if (a->Result->Text == "not") {
			if (a->Result->Text == "well") {
				SpeechSynthesizer s;
				s.Speak("Why is that?");
				if (a->Result->Text == "Dont want to talk") {
					SpeechSynthesizer s;
					s.Speak("Ok");
				}
			}
		}
	}

	public: void Load(bool isDebug) {
		cout << "Loading..." << endl;
		SpeechSynthesizer speaker;
		SpeechRecognitionEngine rec;

		speaker.Rate = 0.5;
		speaker.Volume = 100;
		speaker.Speak("Hello and welcome to this example!");
		speaker.Speak("Do you want to start a conversation with me?");
		string ans;
		cin >> ans;
		if (ans == "Yes") {
			rec.SetInputToWaveFile("\speech.wav");
			rec.Recognize();
		}
	}
};