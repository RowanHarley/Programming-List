#pragma once

#include<string>
#include<string.h>
//#include <boost/algorithm/string.hpp>
#include <iostream>

using namespace std;

class Search {
	public: void Load(bool isDebug) {
		bool hasFoundResult;
		int breakInt = 0;
		string ans;
		string search;
		string searchKeywordName[100][50] = { {"Test"}, {"std", "namespace"}, {"iostream", "include"} };
		string searchName[100] = {"Test", "The 'std' Namespace", "iostream"};
		string searchDesc[100] = {"This is a test", "This is the main namespace used in C++.\nIt contains many functions including cout, cin and many more!", "iostream is one of the main include directories in C++.\nIt contains many functions."};
		for (;;) {
			std::cout << "Welcome to this search engine! Do you want to search for anything?" << endl;
			cin >> ans;
			if (_stricmp(ans.c_str(), "yes") == 0) {
				cout << "What would you like to search?\n";
				std::cin >> search;

				for (int i = 0; i < 100; i++) {

					for (int j = 0; j < 50; j++) {

						if (_stricmp(search.c_str(), searchKeywordName[i][j].c_str()) == 0) {
							std::cout << "Name: " << searchName[i] << endl << "Description: " << searchDesc[i] << endl;
							breakInt = 1;
							hasFoundResult = true;
							break;
						}
						else if (isDebug) {
							if (j <= 48) {
								std::cout << "Nothing found in reference " << i << ", " << j << ". Trying in " << i << ", " << j + 1 << endl;
							}
							else if (j == 49) {
								std::cout << "Nothing found in reference " << i << ", " << j << ". Trying in " << i + 1 << ", " << 0 << endl;
							}
							hasFoundResult = false;
						}

					}
					if (breakInt == 1) {
						break;
					}
				}
				if (!hasFoundResult) {
					cout << "No results found" << endl;
					
				}
				break;
			}
			else if (_stricmp(ans.c_str(), "no") == 0) {
				for (int i = 0; i < 100; i++) {
					if (searchName[i] != "" && searchDesc[i] != "") {
						std::cout << "Name: " << searchName[i] << endl << "Description: " << searchDesc[i] << endl;
						std::cout << "--------------------------------------------------------------------------------" << endl;
					}
					else {
						std::cout << "No More Results." << endl;
					}
					break;
				}
			}
			else if (_stricmp(ans.c_str(), "y") == 0) {
				cout << "What would you like to search?\n";
				std::cin >> search;

				
				for (int i = 0; i < 100; i++) {
					for (int j = 0; j < 50; j++) {

						if (_stricmp(search.c_str(), searchKeywordName[i][j].c_str()) == 0) {
							std::cout << "Name: " << searchName[i] << endl << "Description: " << searchDesc[i] << endl;
							breakInt = 1;
							hasFoundResult = true;
							break;
						}
						else if (isDebug) {
							if (j <= 48) {
								std::cout << "Nothing found in reference " << i << ", " << j << ". Trying in " << i << ", " << j + 1 << endl;
							}
							else if (j == 49) {
								std::cout << "Nothing found in reference " << i << ", " << j << ". Trying in " << i + 1 << ", " << 0 << endl;
							}
							hasFoundResult = false;
						}
					}

					if (breakInt == 1) {
						break;
					}
				}
				if (!hasFoundResult) {
					cout << "No results found" << endl;
					
				}
				break;
			}
			else if (_stricmp(ans.c_str(), "n") == 0) {
				for (int i = 0; i < 100; i++) {
					std::cout << "Name: " << searchName[i] << endl << "Description: " << searchDesc[i] << endl;
					std::cout << "--------------------------------------------------------------------------------" << endl;
				}
				break;
			}
			else {
				cout << "That is not a valid answer!" << endl;
				continue;
			}
			if (breakInt == 1) {
				break;
			}
		}
		
		/*for (int i = 0; i <= 100; i++) {
			if (search == searchName[i]) {
				std::cout << "Name: " << searchName[i] << endl << "Description: " << searchDesc[i] << endl;
				break;
			}
			else {
				std::cout << "Nothing found in reference " << i << ". Trying in " << i + 1 << endl;
			}
		}*/
		system("Pause");
	}
};