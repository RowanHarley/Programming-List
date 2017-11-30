#pragma once

#include <iostream>

using namespace std;

class guessingGame {

	int difficulty = 100000;
	char input = 'n';		// User's input
	int lowerBound = 0;		// Lowest possible number left
	int upperBound = difficulty + 1; // Highest possible number left
	int myGuess = 0;		// My current guess
	int	lastGuess = -1;		// My last guess

	bool MainMenu() {
		cout << "Welcome to the Game!" << endl << endl;
		while (true) {
			cout << "1. Play" << endl;
			cout << "2. Exit" << endl;
			cout << ">";
			cin >> input;

			if (input == '1') return true; // This play the game
			else if (input == '2') return false; // This will quit
		}
	}

	// This function could show a little cutscene intro story.
	// I've used it to display some instructions.
	void ShowStory() {
		input = 'n'; // Make sure input is not 'y'

		cout << "Once upon a time..." << endl;
		cout << "You thought of a number between 0 and " << difficulty << endl;
		while (input != 'y') {
			cout << "Have you got one (y/n)? ";
			cin >> input;
			if (input != 'y') cout << "Ok, I'll wait a bit..." << endl;
		}

		cout << endl;
	}

	void ResetGame() {
		lowerBound = 0;
		upperBound = difficulty + 1;
		input = 'n';
	}

	bool UpdateWorld() {
		myGuess = (lowerBound + upperBound) / 2; // Generate the next guess

		if (lastGuess == myGuess) {
			cout << "You cheated :(" << endl;
			return false; // Quit
		}

		lastGuess = myGuess;
		return true; // All good keep going
	}

	void DrawGraphics() {
		cout << "I think it's " << myGuess << "! Am I right?" << endl;
		cout << "l. Lower" << endl;
		cout << "h. Higher" << endl;
		cout << "y. Yes!" << endl;
	}

	void GetInput() {
		cin >> input; // Read something from the keyboard

					  // Act on input:
		switch (input) {
		case 'l': upperBound = myGuess; break;
		case 'h': lowerBound = myGuess; break;
		case 'y': cout << "YaY!!!" << endl; break;
		}
	}

	bool GameOverScreen()
	{
		cout << endl;
		cout << "That was pretty good, play again (y/n)? " << endl;
		cin >> input;

		if (input == 'y') return true;
		else return false;
	}

	bool PlayGame() {
		ShowStory(); // Show the game story

		ResetGame(); // Reset all variables to original values

		while (input != 'y') { // This is the main game loop
			UpdateWorld();

			DrawGraphics();

			GetInput();
		}

		return GameOverScreen();
	}

	public: void Load(bool isDebug) {
		while (MainMenu()) { // While they say they want to play
			while (PlayGame());	// repeatedly run the game loop
		}
	}
};