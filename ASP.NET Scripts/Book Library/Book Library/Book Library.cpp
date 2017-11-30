// Book Library.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	string option;
	string name;
	// TODO: Add ID feature for simpler search
	string id;
	string genre;
	ofstream fout;
	ifstream fin;
	cout << "Welcome to My Library V0.6.0a\n";
	cout << "Would you like to search for a book, add one or delete one?\n";
	cin >> option;

	

	if (option.find("add") != string::npos) {
		fout.open("bookinfo.dat", ios::app);
		cout << "Name of the book: ";
		cin >> name;
		// cout << "ID: ";
		cout << "Genre: ";
		cin >> genre;
		fout << name << " " << genre << endl;
		fout.close();
	} else if ((option.find("search") || option.find("find") || option.find("look")) != string::npos) {
		fin.open("bookinfo.dat");
		cout << "Name of book: ";
		cin >> name;
		std::string fullResults;
		vector<string> results;
		int i = 0;
		std::vector<string>::iterator it;
		it = results.begin();
		while (std::getline(fin, fullResults))
		{
			results.resize(results.size() + 1);
			results.insert(it, fullResults);
			it++;
			fullResults = "";
		}
		transform(name.begin(), name.end(), name.begin(), ::tolower);
		for (i = 0; i <= results.size(); i++) {
			if (results[i].find(name)) {

			}
		}
		
	} else if ((option.find("delete") || option.find("remove")) != string::npos) {
		// TODO: Work on this function
	}
    return 0;
}

