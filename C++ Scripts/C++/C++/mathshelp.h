
#pragma once
#include "stdafx.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;


class Test {
public: void Load(bool isDebug) {
	int amountOfNumbers;
	int num1;
	int num2;
	int num3;
	string eq;

	std::cout << "How many numbers are in the question? (2 or 1)";
	cin >> amountOfNumbers;
	if (amountOfNumbers == 1) {
		std::cout << "Number 1: ";
		cin >> num1;

		std::cout << "Type of equation?\nR = Square Root\n";
		cin >> eq;
		if (eq == "R" || eq == "r") {
			int i = 0;
			while (i * i != num1) {
				i++;
			}
			/*for (int i = 0; i >= num1;)
			{
			if (i * i != num1) {
			i++;
			}
			else {
			break;
			}
			}*/
			std::cout << "The Answer is " << i << endl;
		}
		else {
			std::cout << eq << " is not a valid letter";
		}
	}
	else if (amountOfNumbers == 2) {
		std::cout << "Number 1 (in order of equation): ";
		cin >> num1;
		std::cout << "Number 2 (in order of equation): ";
		cin >> num2;

		std::cout << "Type of equation?\nA = Addition, S = Subtraction, D = Division, M = Multiplication,\nE = Exponents (To the power of)\n";
		cin >> eq;
		if (eq == "A" || eq == "a") {
			num3 = num1 + num2;
			std::cout << "The Answer is " << num3 << endl;
		}
		else if (eq == "S" || eq == "s") {
			num3 = num1 - num2;
			std::cout << "The Answer is " << num3 << endl;
		}
		else if (eq == "D" || eq == "d") {
			num3 = num1 / num2;
			std::cout << "The Answer is " << num3 << endl;
		}
		else if (eq == "E" || eq == "e") {
			num3 = pow(num1, num2);
			std::cout << "The Answer is " << num3 << endl;
		}
		else if (eq == "M" || eq == "m") {
			num3 = num1 * num2;
			std::cout << "The Answer is " << num3 << endl;
		}
		else {
			std::cout << eq << " is not a valid letter";
		}
	}
	else {
		std::cout << "You can only have a max of 2 numbers in the sum!\n";
	}
	std::system("pause");
}
};
