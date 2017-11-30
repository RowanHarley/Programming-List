#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <random>
#include <vector>
#include <cassert>

using namespace std;

class Probability {
	public:
		///<summary>
		/// Get's the probability of multiple items, returning '0' for Nothing and 1 - numOfItems for a result.
		/// Note: It may be more reliable to use multiple GetProbability's.
		/// See Also <b>GetProbability()</b>
		///</summary>
		int GetMultipleProbability(int min, int max,int numOfItems,int probability[]) {

			assert(numOfItems <= sizeof(probability)); // Check if numOfItems is smaller or equal to probability[]

			srand(time(0));
			vector <int> probabilityVect(max);
			int j = 0;
			for (int i = 0; i < max; i++) {
				if (i >= 0 && i <= probability[j]) {
					probabilityVect.insert(probabilityVect.begin(), j + 1);
					if (i == probability[j]) {
						j++;
					}
					/*probabilityArray[i] = 1;*/
				}
				else {
					probabilityVect.insert(probabilityVect.end(), 0);
					/*probabilityArray[i] = 0;*/
				}
			}
			// Arrays go from 0 to max-1 to account for the 0
			std::random_shuffle(&probabilityVect[min], &probabilityVect[max - 1]);
			bool isFound = false;
			for (int r = 1; r < j; r++) {

				// Check if the first element of the randomly shufffled array is equal to 1
				if (probabilityVect[0] == r) {
					isFound = true;
					return r;
					/*cout << "Probability Successful" << endl;*/
				}
			}
			if (isFound == false) {
				return 0;
			}
			
		}
		bool GetProbability(int min, int max, int probability) {
			srand(time(0));
			vector <int> probabilityVect(max);
			/*int probabilityArray[100000];*/
			for (int i = 0; i < max; i++) {
				if (i >= 0 && i <= probability) {
					probabilityVect.insert(probabilityVect.begin(), 1);
					/*probabilityArray[i] = 1;*/
				}
				else {
					probabilityVect.insert(probabilityVect.end(), 0);
					/*probabilityArray[i] = 0;*/
				}
			}
			// Arrays go from 0 to max-1 to account for the 0
			std::random_shuffle(&probabilityVect[min], &probabilityVect[max - 1]);

			// Check if the first element of the randomly shufffled array is equal to 1
			if (probabilityVect[0] == 1) {
				return true;
				/*cout << "Probability Successful" << endl;*/
			}
			else {
				return false;
				/*cout << "Probability Failed" << endl;*/
			}
		}
};
class Versioning {
	public: 
		int SetVersion(int major) {

		}
		int SetVersion (int major,int minor){

		}
		int SetVersion(int major, int minor, int build) {

		}
		int SetVersion(int major, int minor, int build, int revision) {

		}
};