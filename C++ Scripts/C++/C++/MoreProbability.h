	#pragma once
	#include <iostream>
	#include <ctime>
	#include <algorithm>
	#include <random>

	using namespace std;


	// Be sure to have this in to get a truly random number

	class MoreProbability {


		// Be sure to have this in to get a truly random number
	


		int GetProbability(int min, int max, int probability) {
			const int arrayMax = max;
			int probabilityArray[100000];
			for (int i = 0; i < max; i++) {
				if (i >= 0 && i <= probability) {
					probabilityArray[i] = 1;
				}
				else {
					probabilityArray[i] = 0;
				}
			}
			// Arrays go from 0 to max-1 to account for the 0
			std::random_shuffle(&probabilityArray[0], &probabilityArray[max - 1]);

			// Check if the first element of the randomly shufffled array is equal to 1
			if (probabilityArray[0] == 1) {
				return 1;
				/*cout << "Probability Successful" << endl;*/
			}
			else {
				return 0;
				/*cout << "Probability Failed" << endl;*/
			}
		}
		public: void Load(bool isDebug) {
			srand(time(0));
			int amount;
			amount = amount + GetProbability(0, 100000, 100);
			cout << amount << endl;
		}
	};
