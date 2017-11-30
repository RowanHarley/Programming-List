#pragma once

#include <iostream>
#include <string>
#include "Classes.h"
#include <curlpp\>

using namespace std;

class PackOpener {
	public:
		void Load() {
			string ans;
			Probability prob;
			string NonRareGolds[100] = {"Nolito", "Lucas Biglia", "Jeremy Toulalan", "Danny","Ander Herrera","Iturraspe"
										,"Jack Wilshere","Camacho","Bruno","Max Kruse","Bojan","Gonzalo Castro"
										,"Raffael","Tiago","Julian Draxler","Andre Gomes","Andreas Samaris"
										,"Paco Alcacer","Bruno Martins Indi","Bibras Natcho","Holger Badstuber"
										,"Daley Blind","Muniain","Daniel Carrico","James McCarthy","Mikel San Jose"
										,"Adrien Silva","Georginio Wijnaldum","Adam Lallana","Mikel Gonzalez"
										,"Roman Shirokov","Riccardo Montolivo","Igor Denisov","Gabi","Selcuk Inan"
										,"Stefano Mauri","Micheal Carrick","Tomas Rosicky","Adem Ljajic"
										,"Cristian Ansaldi","Alexandre Song","Joleon Lescott","Joaquin","Bernardo Silva"
										,"Federico Mancuello","Oliver Torres","Franco Vazquez","Luciano Vietto"};
			
			cout << "Welcome to the Pack Opening Simulator." << endl
		 		 << "To open a Rare Gold Pack, Type RG," << endl
		 		 << "To open a Gold Pack, Type G," << endl
				 << "And To open a Jumbo Rare Pack, Type J" << endl;
			cin >> ans;
			if (_stricmp(ans.c_str(), "RG") == 0) {

			}
			else if (_stricmp(ans.c_str(), "G") == 0) {

			}
			else if (_stricmp(ans.c_str(), "J") == 0) {

			}
			else {
				cout << "That's not a valid answer" << endl;
			}
		}
};