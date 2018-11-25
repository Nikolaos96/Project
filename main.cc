//File: main.cc
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "Grid.h"

using namespace std;


int main(int argc, char* argv[]){
int heros, i, h_w = 0, h_s = 0, h_p = 0;
int ep, k, a;
string names[9] = {"Abbathor","Arvoreen","Brandobaris","Cyrrollalee","Charmalaine","Erevan Ilesere","Urogalan","Urdlen","St. Cuthbert"};
// onomata gia toys iroes.Ta 3 prwta gia toys warrior,ta epomena 3 gia sorcecer kai ta 3 teleutaia gia paladin
	srand(time(NULL));

	if(argv[1] == NULL || atoi(argv[1]) > 3){
		cout << "Error with argument command line" << endl;
		return -1;
	}

	heros = atoi(argv[1]);	// plithos iroon apo ti grammi entolis
	cout << "Heros are " << heros << endl << endl;
	for(i = 0 ; i < heros ; i++){
		cout << "what type do you want the hero " << i+1 << " to be ?" << endl;
		cout << "if you want to be Warrior  press 1" << endl;
		cout << "if you want to be Sorcerer press 2" << endl;
		cout << "if you want to be Paladin  press 3" << endl;
		int press;
		cin >> press;
		if(press == 1) h_w++;
		else if(press == 2) h_s++;
		else if(press == 3) h_p++;
	}
	cout << endl;

	Grid g(heros,9,9,h_w,h_s,h_p,names); // dimiourgei to grid kai tous iroes
	g.square_set(1);	// dimiourgei ta tetragona me agora

	cout << "You have " << heros << " heros" << endl << endl;
	do{
		cout << "1.  Map" << endl;
		cout << "2.  CheckInventory" << endl;
		cout << "3.  Hero_Info" << endl;
		cout << "4.  Move" << endl;
		cout << "5.  Equip" << endl;
		cout << "6.  Use Potion" << endl;
		cout << "0.  QuitGame" << endl;
		cin >> ep;
		switch (ep) {
			case 1:
				cout << endl;
				g.displayMap();  // Emfanisi xarti
				cout << endl;
				break;
			case 2:
				cout << endl;
				g.checkInventory();// Emfanisi antikeimenon irown
				cout << endl << endl;
				break;
			case 3:
				cout << endl;
				g.Hero_Info(); // Emfanisi plirofories gia tous iroes
				cout << endl << endl;
				break;
			case 4: {
				cout << endl;
				int a = g.move();// Metakinisi
				if(a == 1){ 	 // An h move epistrepsei 1 tote oi Heros metakinithikan se tetragono me agora
					cout << "Heros are in Market" << endl;
					do{
						cout << "if you want buy press 1, sell press 2, exit press 0" << endl;
						cin >> k;
						if(k == 1)g.buy();
						else if(k == 2)g.sell();
					}while(k == 1 || k == 2);
				}else if(a == 2){ // An h move epistrepsei 2  tote oi hrwes metakinithikan se tetragono me terata
					double s = rand() / (((double)RAND_MAX) + 1); // tixaios pragmatikos sto diastima (0,1)
					if(s <= 0.5){
						cout << "     Fight" << endl << endl;
						g.square_set(100);		// Dimiourgia teraton antoistixou epipedou me tous Heros
						g.fight();
					}
				}
				cout << endl << endl;
				break;  }
			case 5:
				cout << endl;
				g.equip(0);	// Allagi oplon kai panoploias
				cout << endl << endl;
				break;
			case 6:
				cout << endl;
				g.use(0);	// Potion
				cout << endl << endl;
				break;
		}
	}while(ep != 0);

 cout << '\n';
 return 0;
}
