//File: Grid.cc
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "Grid.h"

using namespace std;


	int Grid::move(){
			cout << "up press    1" << endl;
			cout << "down press  2" << endl;
			cout << "right press 3" << endl;
			cout << "left press  4" << endl;
			int press;
			cin >> press;
			if(press == 1){
				if(line == 0){
					cout << "You can not go up" << endl;
					return 0;
				}
				if(strcmp(map[line-1][stele], "n") == 0){
					cout << "The square is NonAccessible" << endl;
					return 0;
				}
				line--;
				if(strcmp(map[line][stele], "m") == 0) return 1;
				else if(strcmp(map[line][stele], "c") == 0)return 2;
			}else if(press == 2){
				if(line == 8){
					cout << "You can not go down" << endl;
					return 0;
				}
				if(strcmp(map[line+1][stele], "n") == 0){
					cout << "The square is NonAccessible" << endl;
					return 0;
				}
				line++;
				if(strcmp(map[line][stele], "m") == 0) return 1;
                                else if(strcmp(map[line][stele], "c") == 0)return 2;
			}else if(press == 3){
				if(stele == 8){
					cout << "You can not go right" << endl;
					return 0;
				}
				if(strcmp(map[line][stele+1], "n") == 0){
					cout << "The square is NonAccessible" << endl;
					return 0;
				}
				stele++;
				if(strcmp(map[line][stele], "m") == 0) return 1;
                                else if(strcmp(map[line][stele], "c") == 0)return 2;
			}else if(press == 4){
				if(stele == 0){
					cout << "You can not go left" << endl;
					return 0;
				}
				if(strcmp(map[line][stele-1], "n") == 0){
					cout << "The square is NonAccessible" << endl;
					return 0;
				}
				stele--;
				if(strcmp(map[line][stele], "m") == 0) return 1;
                                else if(strcmp(map[line][stele], "c") == 0)return 2;
			}else{
				cout << "Wrong Choice" << endl;
				return 0;
			}
		}



  void Grid::buy() {
             int ep, item, k, j;
             do{
                   if(heros_w) cout << "For Warrior press 1" << endl;
                   if(heros_s) cout << "For Sorcecer press 2" << endl;
                   if(heros_p) cout << "For Paladin press 3" << endl;
                   cout << "For Exit press 0" << endl;
                   cin >> j;

                   if( j == 1 ){
                   	cout << "You have " << heros_w << " Warrior" <<endl;
                        if(heros_w > 0) {
                        	cout << "For who warrior you want to buy" << endl;
                                cin >> k; }
			if(k <= 0 || k > heros_w){ cout << "Wrong Choice" << endl; break; }
                   }else if(j == 2){
      		             cout << "You have " << heros_s << " Sorcecer" << endl;
                             if(heros_s > 0){
           	             	cout << "For who sorcecer you want to buy" << endl;
                                cin >> k; }
				if(k <= 0 || k > heros_s){ cout << "Wrong Choice" << endl; break; }
	    	   }else if(j == 3){
                  	 cout << "You have " << heros_p << " Paladin" << endl;
                         if(heros_p > 0){
   	                      cout << "For who paladin you want to buy" << endl;
                              cin >> k; }
			if(k <= 0 || k > heros_p){ cout << "Wrong Choice" << endl; break; }
                   }else if(j == 0){
			break;
		   }else{ cout << "Wrong Choice" << endl; break; }

                        cout << "1. for Weapons" << endl;
                        cout << "2. for Armor" << endl;
                        cout << "3. for Potion" << endl;
                        cout << "4. for IceSpell" << endl;
                        cout << "5. for FireSpell" << endl;
                        cout << "6. for LightSpell" << endl;
                        cout << "7. Exit" << endl;
                        cout << "press 1 - 7" << endl;
                        cin >> ep;

			if(j == 1){	// Agora antikeimenou gia Warrior
        	                switch (ep){
                                	case 1:
                        	                S[line][stele]->show_Weapon();		// Emfanizei ta opla apo tin agora
                                                cout << endl << "Select weapon 1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(war[k-1]->get_money() >= S[line][stele]->Weapon_value(item)){// An exei arketa lefta agorazei
                    	                                war[k-1]->set_money((-1)*S[line][stele]->Weapon_value(item));
                                                        war[k-1]->buy_Weapon(*S[line][stele]->Weapon_buy(item));
                                                }else
                                	                cout << "The hero's money is not enough" << endl;
                                                        break;
                                        case 2:
                        	                S[line][stele]->show_Armor();		// Emfanizei tis panoplies apo tin agora
                                                cout << endl << "Select armor 1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(war[k-1]->get_money() >= S[line][stele]->Armor_value(item)){
                                	                war[k-1]->set_money((-1)*S[line][stele]->Armor_value(item));
                                                        war[k-1]->buy_Armor(S[line][stele]->Armor_buy(item));
                                                }else
                                                        cout << "The hero's money is not enough" << endl;
                                                break;
                                        case 3:
						S[line][stele]->show_Potion();		// Emfanizei ta Potion apo tin agora
						cout << endl << "Select potion 1 - 30" << endl;
						do{ cin >> item; }while(item <= 0 || item > 30);
						if(war[k-1]->get_money() >= S[line][stele]->Potion_value(item)){
                                                           war[k-1]->set_money((-1)*S[line][stele]->Potion_value(item));
                                              		   war[k-1]->buy_Potion(S[line][stele]->Potion_buy(item));
                                                 }else
                                           	      cout << "The hero's money is not enough" << endl;
						 break;
					case 4:
						S[line][stele]->show_IceSpell();		// Emfanizei ta iceSpell apo tin agora
						cout << endl << "Select icespel1 - 30" << endl;
						do{ cin >> item; }while(item <= 0 || item > 30);
						if(war[k-1]->get_money() >= S[line][stele]->IceSpell_value(item)){
                                                	war[k-1]->set_money((-1)*S[line][stele]->IceSpell_value(item));
                                                        war[k-1]->buy_IceSpell(S[line][stele]->IceSpell_buy(item));
                                                 }else
                                                 	cout << "The hero's money is not enough" << endl;
						 break;
					case 5:
						S[line][stele]->show_FireSpell();		// Emfanizei ta fireSpell apo tin agora
						cout << endl << "Select firespell1 - 30" << endl;
						do{ cin >> item; }while(item <= 0 || item > 30);
						if(war[k-1]->get_money() >= S[line][stele]->FireSpell_value(item)){
                                                	war[k-1]->set_money((-1)*S[line][stele]->FireSpell_value(item));
                                                        war[k-1]->buy_FireSpell(S[line][stele]->FireSpell_buy(item));
                                                }else
                	                                cout << "The hero's money is not enough" << endl;
						break;
					case 6:
						S[line][stele]->show_LightSpell();		// Emfanizei ta LightingSpell apo tin agora
						cout << endl << "Select lightspell1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
						if(war[k-1]->get_money() >= S[line][stele]->LightingSpell_value(item)){
                                                	war[k-1]->set_money((-1)*S[line][stele]->LightingSpell_value(item));
                                                        war[k-1]->buy_LightingSpell(S[line][stele]->LightSpell_buy(item));
                                               	}else
                                                        cout << "The hero's money is not enough" << endl;
						break;
					}
			}else if(j == 2){ // Agora antikeimenou gia Sorcecer
				switch (ep){
					case 1:
                                                S[line][stele]->show_Weapon();
                                                cout << endl << "Select weapon 1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(sor[k-1]->get_money() >= S[line][stele]->Weapon_value(item)){
                                                        sor[k-1]->set_money((-1)*S[line][stele]->Weapon_value(item));
                                                        sor[k-1]->buy_Weapon(*S[line][stele]->Weapon_buy(item));
                                                }else
                                                        cout << "The hero's money is not enough" << endl;
                                                        break;
                                        case 2:
                                                S[line][stele]->show_Armor();
                                                cout << endl << "Select armor 1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(sor[k-1]->get_money() >= S[line][stele]->Armor_value(item)){
                                                        sor[k-1]->set_money((-1)*S[line][stele]->Armor_value(item));
                                                        sor[k-1]->buy_Armor(S[line][stele]->Armor_buy(item));
                                                }else
                                                        cout << "The hero's money is not enough" << endl;
                                                break;
					case 3:
                                                S[line][stele]->show_Potion();
                                                cout << endl << "Select potion 1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(sor[k-1]->get_money() >= S[line][stele]->Potion_value(item)){
                                                           sor[k-1]->set_money((-1)*S[line][stele]->Potion_value(item));
                                                           sor[k-1]->buy_Potion(S[line][stele]->Potion_buy(item));
                                                 }else
                                                      cout << "The hero's money is not enough" << endl;
                                                 break;
                                        case 4:
                                                S[line][stele]->show_IceSpell();
                                                cout << endl << "Select icespel1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(sor[k-1]->get_money() >= S[line][stele]->IceSpell_value(item)){
                                                        sor[k-1]->set_money((-1)*S[line][stele]->IceSpell_value(item));
                                                        sor[k-1]->buy_IceSpell(S[line][stele]->IceSpell_buy(item));
                                                 }else
                                                        cout << "The hero's money is not enough" << endl;
                                                 break;
					case 5:
                                                S[line][stele]->show_FireSpell();
                                                cout << endl << "Select firespell1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(sor[k-1]->get_money() >= S[line][stele]->FireSpell_value(item)){
                                                        sor[k-1]->set_money((-1)*S[line][stele]->FireSpell_value(item));
                                                        sor[k-1]->buy_FireSpell(S[line][stele]->FireSpell_buy(item));
                                                }else
                                                        cout << "The hero's money is not enough" << endl;
                                                break;
                                        case 6:
                                                S[line][stele]->show_LightSpell();
                                                cout << endl << "Select lightspell1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(sor[k-1]->get_money() >= S[line][stele]->LightingSpell_value(item)){
                                                        sor[k-1]->set_money((-1)*S[line][stele]->LightingSpell_value(item));
                                                        sor[k-1]->buy_LightingSpell(S[line][stele]->LightSpell_buy(item));
                                                }else
                                                        cout << "The hero's money is not enough" << endl;
                                                break;
					}
			}else if(j == 3){ // Agora antikeimenou gia Paladin
				switch (ep){
					case 1:
                                                S[line][stele]->show_Weapon();
                                                cout << endl << "Select weapon 1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(pal[k-1]->get_money() >= S[line][stele]->Weapon_value(item)){
                                                        pal[k-1]->set_money((-1)*S[line][stele]->Weapon_value(item));
                                                        pal[k-1]->buy_Weapon(*S[line][stele]->Weapon_buy(item));
                                                }else
                                                        cout << "The hero's money is not enough" << endl;
                                                        break;
                                        case 2:
                                                S[line][stele]->show_Armor();
                                                cout << endl << "Select armor 1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(pal[k-1]->get_money() >= S[line][stele]->Armor_value(item)){
                                                        pal[k-1]->set_money((-1)*S[line][stele]->Armor_value(item));
                                                        pal[k-1]->buy_Armor(S[line][stele]->Armor_buy(item));
                                                }else
                                                        cout << "The hero's money is not enough" << endl;
                                                break;
					case 3:
                                                S[line][stele]->show_Potion();
                                                cout << endl << "Select potion 1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(pal[k-1]->get_money() >= S[line][stele]->Potion_value(item)){
                                                           pal[k-1]->set_money((-1)*S[line][stele]->Potion_value(item));
                                                           pal[k-1]->buy_Potion(S[line][stele]->Potion_buy(item));
                                                 }else
                                                      cout << "The hero's money is not enough" << endl;
                                                 break;
                                        case 4:
                                                S[line][stele]->show_IceSpell();
                                                cout << endl << "Select icespel1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(pal[k-1]->get_money() >= S[line][stele]->IceSpell_value(item)){
                                                        pal[k-1]->set_money((-1)*S[line][stele]->IceSpell_value(item));
                                                        pal[k-1]->buy_IceSpell(S[line][stele]->IceSpell_buy(item));
                                                 }else
                                                        cout << "The hero's money is not enough" << endl;
                                                 break;
					case 5:
                                                S[line][stele]->show_FireSpell();
                                                cout << endl << "Select firespell1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(pal[k-1]->get_money() >= S[line][stele]->FireSpell_value(item)){
                                                        pal[k-1]->set_money((-1)*S[line][stele]->FireSpell_value(item));
                                                        pal[k-1]->buy_FireSpell(S[line][stele]->FireSpell_buy(item));
                                                }else
                                                        cout << "The hero's money is not enough" << endl;
                                                break;
                                        case 6:
                                                S[line][stele]->show_LightSpell();
                                                cout << endl << "Select lightspell1 - 30" << endl;
                                                do{ cin >> item; }while(item <= 0 || item > 30);
                                                if(pal[k-1]->get_money() >= S[line][stele]->LightingSpell_value(item)){
                                                        pal[k-1]->set_money((-1)*S[line][stele]->LightingSpell_value(item));
                                                        pal[k-1]->buy_LightingSpell(S[line][stele]->LightSpell_buy(item));
                                                }else
                                                        cout << "The hero's money is not enough" << endl;
                                                break;
					}
				}
		}while(ep <= 6);
  }

    void Grid::sell() {
    	int j, k, ep, item;
	    do{
                   if(heros_w) cout << "For Warriors press 1" << endl;
                   if(heros_s) cout << "For Sorcecers press 2" << endl;
                   if(heros_p) cout << "For Paladins press 3" << endl;
                   cout << "For Exit press 0" << endl;
                   cin >> j;

                   if( j == 1 ){
                        cout << "You have " << heros_w << " Warrior" <<endl;
                        if(heros_w > 0) {
                                cout << "For who warrior you want to sell" << endl;
                                cin >> k; }
				if(k <= 0 || k > heros_w){ cout << "Wrong Choice" << endl; break; }
                   }else if(j == 2){
                             cout << "You have " << heros_s << " Sorcecer" << endl;
                             if(heros_s > 0){
                                cout << "For who sorcecer you want to sell" << endl;
                                cin >> k; }
				if(k <= 0 || k > heros_s){ cout << "Wrong Choice" << endl; break; }
                   }else if(j == 3){
                         cout << "You have " << heros_p << " Paladin" << endl;
                         if(heros_p > 0){
                              cout << "For who paladin you want to sell" << endl;
                              cin >> k; }
			if(k <= 0 || k > heros_p){ cout << "Wrong Choice" << endl; break; }
                   }else if(j == 0){
                        break;
                   }else{ cout << "Wrong Choice" << endl; break; }

	    	   cout << "1. for Weapons" << endl;
                   cout << "2. for Armor" << endl;
                   cout << "3. for Potion" << endl;
                   cout << "4. for IceSpell" << endl;
                   cout << "5. for FireSpell" << endl;
                   cout << "6. for LightSpell" << endl;
                   cout << "7. Exit" << endl;
                   cout << "press 1 - 7" << endl;
                   cin >> ep;
		   if(j == 1){// Poulaei kapoios Warrior
                                switch (ep){
                                        case 1:
                                                if(war[k-1]->show_Weapon()){// poulaei opla
                                                	cout << endl << "Select weapon " << endl;
                                                	cin >> item;
							war[k-1]->sell_Weapon(item);
						}
						break;
                                        case 2:
                                                if(war[k-1]->show_Armor()){// poulaei panoplies
                                                	cout << endl << "Select armor " << endl;
                                                	cin >> item;
                                                	war[k-1]->sell_Armor(item);
						}
                                                break;
                                        case 3:
                                               	if(war[k-1]->show_Potion()){
                                                	cout << endl << "Select potion " << endl;
                                                	cin >> item;
                                                	war[k-1]->sell_Potion(item);
						}
                                                break;
					case 4:
						if(war[k-1]->show_IceSpell()){
                                                	cout << endl << "Select icespell " << endl;
                                                	cin >> item;
                                                	war[k-1]->sell_IceSpell(item);
						}
                                                break;
                                        case 5:
						if(war[k-1]->show_FireSpell()){
                                                	cout << endl << "Select firespell " << endl;
                                                	cin >> item;
                                                	war[k-1]->sell_FireSpell(item);
						}
                                                break;
					case 6:
						if(war[k-1]->show_LightingSpell()){// poulaei lightingSpell
                                                	cout << endl << "Select Lightingspell " << endl;
                                                	cin >> item;
                                                	war[k-1]->sell_LightingSpell(item);
						}
                                                break;
                                        }
                        }else if(j == 2){ // Poulaei kapoios Sorcecer
				switch (ep){
                                        case 1:
                                                sor[k-1]->show_Weapon();	// poulaei kapoio oplo
                                                cout << endl << "Select weapon " << endl;
                                                cin >> item;
                                                sor[k-1]->sell_Weapon(item);
                                                break;
                                        case 2:
                                                sor[k-1]->show_Armor();
                                                cout << endl << "Select armor " << endl;
                                                cin >> item;
                                                sor[k-1]->sell_Armor(item);
                                                break;
					case 3:
                                                sor[k-1]->show_Potion();
                                                cout << endl << "Select potion " << endl;
                                                cin >> item;
                                                sor[k-1]->sell_Potion(item);
                                                break;
                                        case 4:
                                                sor[k-1]->show_IceSpell();
                                                cout << endl << "Select icespell " << endl;
                                                cin >> item;
                                                sor[k-1]->sell_IceSpell(item);
                                                break;
                                        case 5:
                                                sor[k-1]->show_FireSpell();
                                                cout << endl << "Select firespell " << endl;
                                                cin >> item;
                                                sor[k-1]->sell_FireSpell(item);
                                                break;
					case 6:
                                                sor[k-1]->show_LightingSpell();// poulaei lightingSpell
                                                cout << endl << "Select Lightingspell " << endl;
                                                cin >> item;
                                                sor[k-1]->sell_LightingSpell(item);
                                                break;
                                        }
			}else if(j == 3){ // Poulaei kapoios Paladin
				switch (ep){
                                        case 1:
                                                pal[k-1]->show_Weapon();// poulaei opla
                                                cout << endl << "Select weapon " << endl;
                                                cin >> item;
                                                pal[k-1]->sell_Weapon(item);
                                                break;
                                        case 2:
                                                pal[k-1]->show_Armor();
                                                cout << endl << "Select armor " << endl;
                                                cin >> item;
                                                pal[k-1]->sell_Armor(item);
                                                break;
                                        case 3:
                                                pal[k-1]->show_Potion();
                                                cout << endl << "Select potion " << endl;
                                                cin >> item;
                                                pal[k-1]->sell_Potion(item);
                                                break;
                                        case 4:
                                                pal[k-1]->show_IceSpell();
                                                cout << endl << "Select icespell " << endl;
                                                cin >> item;
                                                pal[k-1]->sell_IceSpell(item);
                                                break;
					case 5:
                                                pal[k-1]->show_FireSpell();
                                                cout << endl << "Select firespell " << endl;
                                                cin >> item;
                                                pal[k-1]->sell_FireSpell(item);
                                                break;
                                        case 6:
                                                pal[k-1]->show_LightingSpell();// poulaei lightingSpell
                                                cout << endl << "Select Lightingspell " << endl;
                                                cin >> item;
                                                pal[k-1]->sell_LightingSpell(item);
                                                break;
                                        }
			}
		}while(ep <= 6);
	}


	void Grid::checkInventory() {// emfanizei ta antikeimena kai ksorkia ton Heros
			for(int i = 0 ; i < heros_w ; i++){
				cout << "For Warrior " << i+1 << endl << endl;
				war[i]->show_Weapon();
				war[i]->show_Armor();
				war[i]->show_Potion();
				war[i]->show_IceSpell();
				war[i]->show_FireSpell();
				war[i]->show_LightingSpell();
			}
			for(int i = 0 ; i < heros_s ; i++){
				cout << "For Sorcecer " << i << i+1 << endl << endl;
				sor[i]->show_Weapon();
				sor[i]->show_Armor();
				sor[i]->show_Potion();
				sor[i]->show_IceSpell();
                                sor[i]->show_FireSpell();
                                sor[i]->show_LightingSpell();
			}
			for(int i = 0 ; i < heros_p ; i++){
				cout << "For Paladin " << i+1 << endl << endl;
				pal[i]->show_Weapon();
				pal[i]->show_Armor();
				pal[i]->show_Potion();
				pal[i]->show_IceSpell();
                                pal[i]->show_FireSpell();
                                pal[i]->show_LightingSpell();
			}
	}

	void Grid::equip(int her){ // allazei h xrisimopoiei kapoi oplo h panoplia gia kapoio Warrior
		int k, l, m;
		if(her == 1 || her == 0){// analoga apo pou kalestike i sinartisi an her =0 tote apo main alliws apo fight
			if(heros_w){
				cout << "Warrior are " << heros_w << endl;
				cout << "For who warrior you want changes ";
				for(int i = 0 ; i < heros_w ; i++) cout << " " << i+1 << " , ";
				cout << endl;
				cin >> k;
				if(k <= heros_w && k > 0){
					cout << "For Weapon press 1, for Armor press 2" << endl;
					cin >> l;
					if(l == 1){
						if(war[k-1]->show_Weapon()){
							cout << "Select weapon for changes" << endl;
							cin >> m;
							war[k-1]->w_equip(m);
						}
					}else if(l == 2){
						if(war[k-1]->show_Armor()){
							cout << "Select armor for changes" << endl;
	                                        	cin >> m;
							war[k-1]->a_equip(m);
						}
					}
				}else cout << "Wrong Choice" << endl;
			}
		}
		cout << endl;
		if(her == 2 || her == 0){	// allazei h xrisimopoiei kapoi oplo h panoplia gia kapoio Sorcecer
			if(heros_s){
				cout << "Sorcecer are " << heros_s << endl;
				cout << "For who Sorcecer you want changes ";
				for(int i = 0 ; i < heros_s ; i++) cout << " " << i+1 << " , ";
				cout << endl;
				cin >> k;
				if(k <= heros_s && k > 0){
					cout << "For Weapon press 1, for Armor press 2" << endl;
        	                        cin >> l;
                	                if(l == 1){
          	                              if(sor[k-1]->show_Weapon()){
                	                        	cout << "Select weapon for changes" << endl;
                        	                	cin >> m;
                    		                    	sor[k-1]->w_equip(m);
						}
        	                        }else if(l == 2){
                	                        if(sor[k-1]->show_Armor()){
                        	                	cout << "Select armor for changes" << endl;
                                	        	cin >> m;
                                        		sor[k-1]->a_equip(m);
						}
	                                }
				}else cout << "Wrong Choice" << endl;
			}
		}
		cout << endl;
		if(her == 3 || her == 0){	// allazei h xrisimopoiei kapoi oplo h panoplia gia kapoio Paladin
			if(heros_p){
				cout << "Paladin are " << heros_p << endl;
				cout << "For who Paladin you want changes ";
				for(int i = 0 ; i < heros_p ; i++) cout << " " << i+1 << " , ";
				cout << endl;
				cin >> k;
				if(k <= heros_p && k > 0){
					cout << "For Weapon press 1, for Armor press 2" << endl;
                	                cin >> l;
                                	if(l == 1){
	                                        if(pal[k-1]->show_Weapon()){
        	                                	cout << "Select weapon for changes" << endl;
                	                        	cin >> m;
                        	                	pal[k-1]->w_equip(m);
						}
        	                        }else if(l == 2){
                	                        if(pal[k-1]->show_Armor()){
                        	                	cout << "Select armor for changes" << endl;
	                                        	cin >> m;
        	                                	pal[k-1]->a_equip(m);
						}
                        	        }
				}else cout << "Wrong Choice" << endl;
			}
		}
		cout << endl;
	}

	void Grid::use(int her){
		int k, l, m;
		if(her == 1 || her == 0){// kapoios Warrior xrisimopoiei kapoio filtro
	                if(heros_w){
        	                cout << "Warrior are " << heros_w << endl;
                	        cout << "For who warrior you want Potion ";
				for(int i = 0 ; i < heros_w ; i++) cout << " " << i+1 << " , ";
                        	cout << endl;
	                        cin >> k;
        	                if(k <= heros_w && k > 0){
					if(war[k-1]->show_Potion()){
						cout << "Select potion" << endl;
						cin >> l;
						war[k-1]->use_potion(l);
					}
        	                }else cout << "Wrong Choice" << endl;
                	}
		}
		cout << endl;
		if(her == 2 || her == 0){// kapoios Sorcecer xrisimopoiei kapoio filtro
			if(heros_s){
				cout << "Sorcecer are " << heros_s << endl;
				cout << "For who Sorcecer you want Potion ";
				for(int i = 0 ; i < heros_s ; i++) cout << " " << i+1 << " , ";
				cout << endl;
	                        cin >> k;
        	                if(k <= heros_s && k > 0){
					if(sor[k-1]->show_Potion()){
						cout << "Select potion" << endl;
	                               		cin >> l;
						sor[k-1]->use_potion(l);
					}
				}else cout << "Wrong Choice" << endl;
			}
		}
		cout << endl;
		if(her == 3 || her == 0){// kapoios Paladin xrisimopoiei kapoio filtro
			if(heros_p){
				cout << "Paladin are " << heros_p << endl;
				cout << "For who Paladin you want Potion ";
				for(int i = 0 ; i < heros_p ; i++) cout << " " << i+1 << " , ";
        	                cout << endl;
	                        cin >> k;
        	                if(k <= heros_p && k > 0){
					if(pal[k-1]->show_Potion()){
						cout << "Select potion" << endl;
	                                	cin >> l;
						pal[k-1]->use_potion(l);
					}
	                        }else cout << "Wrong Choice" << endl;
			}
		}		cout << endl;
	}

		void Grid::Hero_Info()const {
			for(int i = 0 ; i < heros_w ; i++) war[i]->print();
			for(int i = 0 ; i < heros_s ; i++) sor[i]->print();
			for(int i = 0 ; i < heros_p ; i++) pal[i]->print();
		}

		void Grid::displayMap()const {// Emfanizei to xarti kai se poio tetragwno einai oi Heros
			cout << endl << endl;;
			cout << "   n = nonAccessible" << endl;
			cout << "   m = market" << endl;
			cout << "   c = commom" << endl;
			cout << '\n' << "   ";
			for(int i = 0 ; i < length ; i++) cout << "   " << i;
			cout << '\n' << '\n';
			for(int i = 0 ; i < length ; i++){
				cout << "  " << i;
				for(int j = 0 ; j < width ; j++){
					if(i == line && j == stele){
						if(strcmp(map[i][j],"m") == 0) cout << "   M";
						else if(strcmp(map[i][j],"c") == 0) cout << "   C";
						else cout << "   c";
					}else
						cout << "   " << map[i][j];
				}
				cout << '\n';
			}
			cout << endl << "The Heros are in the square : " << line << "," << stele << endl;
			if(strcmp(map[line][stele], "m") == 0) cout << "Square is market" << endl;
			else if(strcmp(map[line][stele], "c") == 0) cout << "Square is commom" << endl;
		}


		void Grid::square_set(int a){// dimiourgei kai arxikopoiei ta terata kai tin agora
			int i,j;
			if(a == 1){// arxikopoiei tin agora se kathe tetragono pou einai market
				for(i = 0 ; i < length ; i++){
					for(j = 0 ; j < width ; j++) if(strcmp(map[i][j], "m") == 0) S[i][j]->set();
				}
			}else if(a == 100){// arxikopoiei ta terata se tetragona pou einai commom
				int level = 1;
				if(heros_w >= 1) level = war[0]->get_level();
				else if(heros_s >= 1) level = sor[0]->get_level();
				else level = pal[0]->get_level();
				S[line][stele]->set2(level);
			}
		}

		void Grid::fight(){// Maxi
			int r = 2, i, k, j;
			int health_H = 0, health_M = 0;
			int a, b, round;

			do{
				cout << endl << endl << "           Round    " << r-1 << endl << endl;
				cout << "To display statistical monsters and heroes press 1 or 2 for continue" << endl;
				cout << "If you want to quit the fight press 0" << endl;
				cin >> j;
				if(j == 1){
					Hero_Info();
					cout << endl;
					S[line][stele]->print_Statictics_Monsters();
				}else if(j == 0) return;
				int hh = 0, hh2 = 0, hh3 = 0;
				cout << endl;/////////////////////////////////////////////////////////////////////////////////
				if(r != 2){
					for(i = 0 ; i < heros_w ; i++){
						if(war[i]->get_healthPower() > 0 && war[i]->get_healthPower() < (2000-war[i]->get_level()*20)){
							war[i]->set_healthPower(war[i]->get_level()*20);
							hh = war[i]->get_level()*20;
						}
						if(war[i]->get_magicPower() < (1000-war[i]->get_level()*20)) war[i]->set_magicPower(war[i]->get_level()*20);
					}
					for(i = 0 ; i < heros_s ; i++){
						if(sor[i]->get_healthPower() > 0 && sor[i]->get_healthPower() < (2000-sor[i]->get_level()*20)){
		 					sor[i]->set_healthPower(sor[i]->get_level()*20);
							hh2 = sor[i]->get_level()*20;
						}
						if(sor[i]->get_magicPower() < (1000-sor[i]->get_level()*20)) sor[i]->set_magicPower(sor[i]->get_level()*20);
					}
					for(i = 0 ; i < heros_p ; i++){
						if(pal[i]->get_healthPower() > 0 && pal[i]->get_healthPower() < (2000-pal[i]->get_level()*20)){
							pal[i]->set_healthPower(pal[i]->get_level()*20);
							hh3 = pal[i]->get_level()*20;
						}
						if(pal[i]->get_magicPower() < (1000-pal[i]->get_level()*20)) pal[i]->set_magicPower(pal[i]->get_level()*20);
					}
					int m = hh;
					if(hh2 > m) m = hh2;// Ta terata angenoun zotiki energeia oso kai o iroas me to megalytero epipedo
					if(hh3 > m) m = hh3;
					if(S[line][stele]->get_D_health(0) > 0 && S[line][stele]->get_D_health(0) < (2000-m+1)) S[line][stele]->set_D_health(0,m);
                                        if(S[line][stele]->get_E_health(0) > 0 && S[line][stele]->get_E_health(0) < (2000-m+1)) S[line][stele]->set_E_health(0,m);
                                        if(S[line][stele]->get_S_health(0) > 0 && S[line][stele]->get_S_health(0) < (2000-m+1)) S[line][stele]->set_S_health(0,m);
					if(S[line][stele]->get_D_health(1) > 0 && S[line][stele]->get_D_health(1) < (2000-m+1)) S[line][stele]->set_D_health(1,m);
			                if(S[line][stele]->get_E_health(1) > 0 && S[line][stele]->get_E_health(1) < (2000-m+1)) S[line][stele]->set_E_health(1,m);
                			if(S[line][stele]->get_S_health(1) > 0 && S[line][stele]->get_S_health(1) < (2000-m+1)) S[line][stele]->set_S_health(1,m);
				}
				if(r % 2 == 0){
					cout << "     Heros  turn" << endl;
					for(i = 0 ; i < heros_w ; i++){
					if(war[i]->get_healthPower() > 0){
						cout << "What movement for warrior " << i+1 << endl;
						cout << "attack  press 1" << endl;
						cout << "castSpell press 2" << endl;
						cout << "use potion press 3" << endl;
						cout << "equip armor or weapon press 4" << endl;
						cin >> k;
						switch (k){
							case 1:
								if(S[line][stele]->get_D_health(0) > 0){// Xtipaei to prwto teras
									int r = (rand() % 200) + 1;
									if(r > S[line][stele]->gD_possibility_of_avoidance(0))
										S[line][stele]->set_D_health(0,(-1)*(war[i]->attack()-S[line][stele]->gD_defense(0)));
								}else if(S[line][stele]->get_D_health(1) > 0){// xtipaei to deytero teras
									int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gD_possibility_of_avoidance(1))
                                                                                S[line][stele]->set_D_health(1,(-1)*(war[i]->attack()-S[line][stele]->gD_defense(1)));
								}else if(S[line][stele]->get_E_health(0) > 0){
									int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gE_possibility_of_avoidance(0))
                                                                                S[line][stele]->set_E_health(0,(-1)*(war[i]->attack()-S[line][stele]->gE_defense(0)));
								}else if(S[line][stele]->get_E_health(1) > 0){
									int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gE_possibility_of_avoidance(1))
                                                                                S[line][stele]->set_E_health(1,(-1)*(war[i]->attack()-S[line][stele]->gE_defense(1)));
								}else if(S[line][stele]->get_S_health(0) > 0){
									int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gS_possibility_of_avoidance(0))
                                                                                S[line][stele]->set_S_health(0,(-1)*(war[i]->attack()-S[line][stele]->gS_defense(0)));
								}else if(S[line][stele]->get_S_health(1) > 0){
									int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gS_possibility_of_avoidance(1))//xtypaei to ekto teras
                                                                                S[line][stele]->set_S_health(1,(-1)*(war[i]->attack()-S[line][stele]->gS_defense(1)));
								}else health_M = 6; // olla ta terata einai nekra
								break;
							case 2: {
								int r = (rand() % 200) + 1;
                                                                int kk = war[i]->castSpell(a,b,round);
								if(kk != 0){
								if(S[line][stele]->get_D_health(0) > 0){// xtipaei to prwto teras
									if(kk == 1){// me icespell
										if(S[line][stele]->gD_possibility_of_avoidance(0) < r)
											S[line][stele]->set_D_health(0,(-1)*(a-S[line][stele]->gD_defense(0)));
									}else if(kk == 2){// me firespell
										if(S[line][stele]->gD_possibility_of_avoidance(0) < r)
											S[line][stele]->set_D_health(0,(-1)*(a-(S[line][stele]->gD_defense(0)-b)));
									}else{// me lightingspell
										if(S[line][stele]->gD_possibility_of_avoidance(0)-b < r)
											S[line][stele]->set_D_health(0,(-1)*(a-S[line][stele]->gD_defense(0)));
									}
                                                                }else if(S[line][stele]->get_D_health(1) > 0){// xtipaei to deutero teras
									if(kk == 1){// me icespell
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_D_health(1,(-1)*(a-S[line][stele]->gD_defense(1)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_D_health(1,(-1)*(a-(S[line][stele]->gD_defense(1)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(1)-b < r)
                                                                                        S[line][stele]->set_D_health(1,(-1)*(a-S[line][stele]->gD_defense(1)));
                                                                        }
                                                                }else if(S[line][stele]->get_E_health(0) > 0){// xtipaei to trito teras
									if(kk == 1){// me icespell
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_E_health(0,(-1)*(a-S[line][stele]->gE_defense(0)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_E_health(0,(-1)*(a-(S[line][stele]->gE_defense(0)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(0)-b < r)
                                                                                        S[line][stele]->set_E_health(0,(-1)*(a-S[line][stele]->gE_defense(0)));
                                                                        }
                                                                }else if(S[line][stele]->get_E_health(1) > 0){
									if(kk == 1){
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_E_health(1,(-1)*(a-S[line][stele]->gE_defense(1)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_E_health(1,(-1)*(a-(S[line][stele]->gE_defense(1)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(1)-b < r)
                                                                                        S[line][stele]->set_E_health(1,(-1)*(a-S[line][stele]->gE_defense(1)));
                                                                        }
                                                                }else if(S[line][stele]->get_S_health(0) > 0){
									if(kk == 1){
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_S_health(0,(-1)*(a-S[line][stele]->gS_defense(0)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_S_health(0,(-1)*(a-(S[line][stele]->gS_defense(0)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(0)-b < r)
                                                                                        S[line][stele]->set_S_health(0,(-1)*(a-S[line][stele]->gS_defense(0)));
                                                                        }
                                                                }else if(S[line][stele]->get_S_health(1) > 0){//xtipaei to ekto teras
									if(kk == 1){// me icespell
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_S_health(1,(-1)*(a-S[line][stele]->gS_defense(0)));
                                                                        }else if(kk == 2){// me firespell
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_S_health(1,(-1)*(a-(S[line][stele]->gS_defense(1)-b)));
                                                                        }else{// me lightingspell
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(1)-b < r)
                                                                                        S[line][stele]->set_S_health(1,(-1)*(a-S[line][stele]->gS_defense(0)));
                                                                        }
								}else health_M = 6;// olla ta terata einai nekra
								break ;
								}
								break;
								}
							case 3:
								use(1);
								break;
							case 4:
								equip(1);
								break;
						}
					}
					}
					for(i = 0 ; i < heros_s ; i++){ // An o iroas einai Sorcecer kanei epithesi
					if(sor[i]->get_healthPower() > 0){
                                                cout << "What movement for Sorcecer " << i+1 << endl;
                                                cout << "attack  press 1" << endl;
                                                cout << "castSpell press 2" << endl;
                                                cout << "use potion press 3" << endl;
                                                cout << "equip armor or weapon press 4" << endl;
                                                cin >> k;
						switch (k){
							case 1:
								if(S[line][stele]->get_D_health(0) > 0){
                                                                        int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gD_possibility_of_avoidance(0))
                                                                                S[line][stele]->set_D_health(0,(-1)*(sor[i]->attack()-S[line][stele]->gD_defense(0)));
                                                                }else if(S[line][stele]->get_D_health(1) > 0){
                                                                        int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gD_possibility_of_avoidance(1))
                                                                                S[line][stele]->set_D_health(1,(-1)*(sor[i]->attack()-S[line][stele]->gD_defense(1)));
                                                                }else if(S[line][stele]->get_E_health(0) > 0){
                                                                        int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gE_possibility_of_avoidance(0))
                                                                                S[line][stele]->set_E_health(0,(-1)*(sor[i]->attack()-S[line][stele]->gE_defense(0)));
                                                                }else if(S[line][stele]->get_E_health(1) > 0){
                                                                        int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gE_possibility_of_avoidance(1))
                                                                                S[line][stele]->set_E_health(1,(-1)*(sor[i]->attack()-S[line][stele]->gE_defense(1)));
                                                                }else if(S[line][stele]->get_S_health(0) > 0){
                                                                        int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gS_possibility_of_avoidance(0))
                                                                                S[line][stele]->set_S_health(0,(-1)*(sor[i]->attack()-S[line][stele]->gS_defense(0)));
                                                                }else if(S[line][stele]->get_S_health(1) > 0){
									int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gS_possibility_of_avoidance(1))
                                                                                S[line][stele]->set_S_health(1,(-1)*(sor[i]->attack()-S[line][stele]->gS_defense(1)));
                                                                }else health_M = 6;
                                                                break;
							case 2: {
								int r = (rand() % 200) + 1;
                                                                int kk = sor[i]->castSpell(a,b,round);
								if(kk != 0){
                                                                if(S[line][stele]->get_D_health(0) > 0){
                                                                        if(kk == 1){
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_D_health(0,(-1)*(a-S[line][stele]->gD_defense(0)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_D_health(0,(-1)*(a-(S[line][stele]->gD_defense(0)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(0)-b < r)
                                                                                        S[line][stele]->set_D_health(0,(-1)*(a-S[line][stele]->gD_defense(0)));
                                                                        }
                                                                }else if(S[line][stele]->get_D_health(1) > 0){
                                                                        if(kk == 1){
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_D_health(1,(-1)*(a-S[line][stele]->gD_defense(1)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_D_health(1,(-1)*(a-(S[line][stele]->gD_defense(1)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(1)-b < r)
                                                                                        S[line][stele]->set_D_health(1,(-1)*(a-S[line][stele]->gD_defense(1)));
                                                                        }
                                                                }else if(S[line][stele]->get_E_health(0) > 0){
									if(kk == 1){
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_E_health(0,(-1)*(a-S[line][stele]->gE_defense(0)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_E_health(0,(-1)*(a-(S[line][stele]->gE_defense(0)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(0)-b < r)
                                                                                        S[line][stele]->set_E_health(0,(-1)*(a-S[line][stele]->gE_defense(0)));
                                                                        }
                                                                }else if(S[line][stele]->get_E_health(1) > 0){
                                                                        if(kk == 1){
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_E_health(1,(-1)*(a-S[line][stele]->gE_defense(1)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_E_health(1,(-1)*(a-(S[line][stele]->gE_defense(1)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(1)-b < r)
                                                                                        S[line][stele]->set_E_health(1,(-1)*(a-S[line][stele]->gE_defense(1)));
                                                                        }
								}else if(S[line][stele]->get_S_health(0) > 0){
                                                                        if(kk == 1){
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_S_health(0,(-1)*(a-S[line][stele]->gS_defense(0)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_S_health(0,(-1)*(a-(S[line][stele]->gS_defense(0)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(0)-b < r)
                                                                                        S[line][stele]->set_S_health(0,(-1)*(a-S[line][stele]->gS_defense(0)));
                                                                        }
                                                                }else if(S[line][stele]->get_S_health(1) > 0){
                                                                        if(kk == 1){
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_S_health(1,(-1)*(a-S[line][stele]->gS_defense(0)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_S_health(1,(-1)*(a-(S[line][stele]->gS_defense(1)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(1)-b < r)
                                                                                        S[line][stele]->set_S_health(1,(-1)*(a-S[line][stele]->gS_defense(0)));
                                                                        }
                                                                }else health_M = 6;
								break;
								}
								break;
								}
							case 3:
								use(2);
								break;
							case 4:
								equip(2);
								break;
						}
					}
					}
					for(i = 0 ; i < heros_p ; i++){// An o iroas einai Paladin kanei epithesi
					if(pal[i]->get_healthPower() > 0){
						cout << "What movement for Paladin " << i+1 << endl;
                                                cout << "attack  press 1" << endl;
                                                cout << "castSpell press 2" << endl;
                                                cout << "use potion press 3" << endl;
                                                cout << "equip armor or weapon press 4" << endl;
                                                cin >> k;
						switch (k){
							case 1:
                                                        	if(S[line][stele]->get_D_health(0) > 0){
                                                                        int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gD_possibility_of_avoidance(0))
                                                                                S[line][stele]->set_D_health(0,(-1)*(pal[i]->attack()-S[line][stele]->gD_defense(0)));
                                                                }else if(S[line][stele]->get_D_health(1) > 0){
                                                                        int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gD_possibility_of_avoidance(1))
                                                                                S[line][stele]->set_D_health(1,(-1)*(pal[i]->attack()-S[line][stele]->gD_defense(1)));
                                                                }else if(S[line][stele]->get_E_health(0) > 0){
                                                                        int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gE_possibility_of_avoidance(0))
                                                                                S[line][stele]->set_E_health(0,(-1)*(pal[i]->attack()-S[line][stele]->gE_defense(0)));
                                                                }else if(S[line][stele]->get_E_health(1) > 0){
                                                                        int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gE_possibility_of_avoidance(1))
                                                                                S[line][stele]->set_E_health(1,(-1)*(pal[i]->attack()-S[line][stele]->gE_defense(1)));
                                                                }else if(S[line][stele]->get_S_health(0) > 0){
                                                                        int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gS_possibility_of_avoidance(0))
                                                                                S[line][stele]->set_S_health(0,(-1)*(pal[i]->attack()-S[line][stele]->gS_defense(0)));
                                                                }else if(S[line][stele]->get_S_health(1) > 0){
									int r = (rand() % 200) + 1;
                                                                        if(r > S[line][stele]->gS_possibility_of_avoidance(1))
                                                                                S[line][stele]->set_S_health(1,(-1)*(pal[i]->attack()-S[line][stele]->gS_defense(1)));
                                                                }else health_M = 6;
                                                                break;
							case 2: {
								int r = (rand() % 200) + 1;
                                                                int kk = pal[i]->castSpell(a,b,round);
								if(kk != 0){
                                                                if(S[line][stele]->get_D_health(0) > 0){
                                                                        if(kk == 1){
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_D_health(0,(-1)*(a-S[line][stele]->gD_defense(0)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_D_health(0,(-1)*(a-(S[line][stele]->gD_defense(0)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(0)-b < r)
                                                                                        S[line][stele]->set_D_health(0,(-1)*(a-S[line][stele]->gD_defense(0)));
                                                                        }
                                                                }else if(S[line][stele]->get_D_health(1) > 0){
                                                                        if(kk == 1){
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_D_health(1,(-1)*(a-S[line][stele]->gD_defense(1)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_D_health(1,(-1)*(a-(S[line][stele]->gD_defense(1)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gD_possibility_of_avoidance(1)-b < r)
                                                                                        S[line][stele]->set_D_health(1,(-1)*(a-S[line][stele]->gD_defense(1)));
                                                                        }
                                                                }else if(S[line][stele]->get_E_health(0) > 0){
									if(kk == 1){
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_E_health(0,(-1)*(a-S[line][stele]->gE_defense(0)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_E_health(0,(-1)*(a-(S[line][stele]->gE_defense(0)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(0)-b < r)
                                                                                        S[line][stele]->set_E_health(0,(-1)*(a-S[line][stele]->gE_defense(0)));
                                                                        }
                                                                }else if(S[line][stele]->get_E_health(1) > 0){
                                                                        if(kk == 1){
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_E_health(1,(-1)*(a-S[line][stele]->gE_defense(1)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_E_health(1,(-1)*(a-(S[line][stele]->gE_defense(1)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gE_possibility_of_avoidance(1)-b < r)
                                                                                        S[line][stele]->set_E_health(1,(-1)*(a-S[line][stele]->gE_defense(1)));
                                                                        }
								}else if(S[line][stele]->get_S_health(0) > 0){
                                                                        if(kk == 1){
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_S_health(0,(-1)*(a-S[line][stele]->gS_defense(0)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(0) < r)
                                                                                        S[line][stele]->set_S_health(0,(-1)*(a-(S[line][stele]->gS_defense(0)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(0)-b < r)
                                                                                        S[line][stele]->set_S_health(0,(-1)*(a-S[line][stele]->gS_defense(0)));
                                                                        }
                                                                }else if(S[line][stele]->get_S_health(1) > 0){
                                                                        if(kk == 1){
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_S_health(1,(-1)*(a-S[line][stele]->gS_defense(1)));
                                                                        }else if(kk == 2){
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(1) < r)
                                                                                        S[line][stele]->set_S_health(1,(-1)*(a-(S[line][stele]->gS_defense(1)-b)));
                                                                        }else{
                                                                                if(S[line][stele]->gS_possibility_of_avoidance(1)-b < r)
                                                                                        S[line][stele]->set_S_health(1,(-1)*(a-S[line][stele]->gS_defense(1)));
                                                                        }
                                                                }else health_M = 6;
								break;
								}
								break;
								}
							case 3:
								use(3);
								break;
							case 4:
								equip(3);
								break;
						}
					}
					}
				}else{// einai i sira ton teraton
					cout << endl << "     Monsters  turn" << endl;
					if(S[line][stele]->get_D_health(0) > 0){// to prwto teras kanei epithsi
						int b = 0; // otan kanei epithesi se kapoio iroa to b ginetai 1 oste na min kanei epithesi se allo iroa
						for(i = 0 ; i < heros_w ; i++){
							if(war[i]->get_healthPower() > 0){
								int r  = (rand() % 200) + 1;
                                                                if(r > war[i]->get_agility()){
                                        	                        war[i]->set_healthPower((-1)*(S[line][stele]->gD_damage(0)-war[i]->Armor_def()));
                                                                }
								if(war[i]->get_healthPower() <= 0) health_H++;
								b = 1;
								break;
							}
						}
						if(b == 0){// den exei kanei epithesi se kapoi iroa warrior ara mporei na kanei se sercecer
							for(i = 0 ; i < heros_s ; i++){
								if(sor[i]->get_healthPower() > 0){
									int r  = (rand() % 200) + 1;
        	                                                        if(r > sor[i]->get_agility()){
                	                                                        sor[i]->set_healthPower((-1)*(S[line][stele]->gD_damage(0)-sor[i]->Armor_def()));
                        	                                        }
									if(sor[i]->get_healthPower() <=0) health_H++;
									b = 1;
									break;
								}
							}
						}
						if(b == 0){// den exei kanei epithesi se kapoio iroa warrior i sorcecer ara mporei na kanei se paladin
							for(i = 0 ; i < heros_p ; i++){
								if(pal[i]->get_healthPower() > 0){
								int r  = (rand() % 200) + 1;
                	                                                if(r > pal[i]->get_agility()){
        	                                                                pal[i]->set_healthPower((-1)*(S[line][stele]->gD_damage(0)-pal[i]->Armor_def()));
	                                                                }
									if(pal[i]->get_healthPower() <= 0) health_H++;
									b = 1;
									break;
								}
							}
						}
					}
					if(S[line][stele]->get_D_health(1) > 0){// to deutero teras diladi o deuteros Dragon kanei epithesi
						int b1 = 0;
						for(i = 0 ; i < heros_w ; i++){
                                                        if(war[i]->get_healthPower() > 0){
								int r  = (rand() % 200) + 1;
                                                                if(r > war[i]->get_agility()){
                                                                        war[i]->set_healthPower((-1)*(S[line][stele]->gD_damage(1)-war[i]->Armor_def()));
                                                                }
								if(war[i]->get_healthPower() <= 0) health_H++;
                                                                b1 = 1;
                                                                break;
							}
                                                }
                                                if(b1 == 0){
                                                        for(i = 0 ; i < heros_s ; i++){
                                                                if(sor[i]->get_healthPower() > 0){
								int r  = (rand() % 200) + 1;
                	                                                if(r > sor[i]->get_agility()){
        	                                                                sor[i]->set_healthPower((-1)*(S[line][stele]->gD_damage(1)-sor[i]->Armor_def()));
	                                                                }
									if(sor[i]->get_healthPower() <= 0) health_H++;
                                                                        b1 = 1;
                                                                        break;
								}
                                                        }
                                                }
                                                if(b1 == 0){
                                                        for(i = 0 ; i < heros_p ; i++){
                                                                if(pal[i]->get_healthPower() > 0){
									int r  = (rand() % 200) + 1;
                                                                	if(r > pal[i]->get_agility()){
                                                                        	pal[i]->set_healthPower((-1)*(S[line][stele]->gD_damage(1)-pal[i]->Armor_def()));
                                                                	}
									if(pal[i]->get_healthPower() <= 0) health_H++;
                                                                        b1 = 1;
                                                                        break;
								}
                                                        }
                                                }
					}
					if(S[line][stele]->get_E_health(0) > 0){// o prwtos Exoskeleton kanei epithesi
						int b2 = 0;
						for(i = 0 ; i < heros_w ; i++){
                                                        if(war[i]->get_healthPower() > 0){
								int r  = (rand() % 200) + 1;
                                                                if(r > war[i]->get_agility()){
                                                                        war[i]->set_healthPower((-1)*(S[line][stele]->gE_damage(0)-war[i]->Armor_def()));
                                                                }
								if(war[i]->get_healthPower() <= 0) health_H++;
                                                                b2 = 1;
                                                                break;
							}
                                                }
                                                if(b2 == 0){
                                                        for(i = 0 ; i < heros_s ; i++){
                                                                if(sor[i]->get_healthPower() > 0){
									int r  = (rand() % 200) + 1;
                                                                	if(r > sor[i]->get_agility()){
                                                                        	sor[i]->set_healthPower((-1)*(S[line][stele]->gE_damage(0)-sor[i]->Armor_def()));
                                                                	}
									if(sor[i]->get_healthPower() <= 0) health_H++;
                                                                        b2 = 1;
                                                                        break;
								}
                                                        }
                                                }
                                                if(b2 == 0){
                                                        for(i = 0 ; i < heros_p ; i++){
                                                                if(pal[i]->get_healthPower() > 0){
									int r  = (rand() % 200) + 1;
                                                                	if(r > pal[i]->get_agility()){
                                                                        	pal[i]->set_healthPower((-1)*(S[line][stele]->gE_damage(0)-pal[i]->Armor_def()));
                                                                	}
									if(pal[i]->get_healthPower() <= 0) health_H++;
                                                                        b2 = 1;
                                                                        break;
								}
                                                        }
                                                }
					}
					if(S[line][stele]->get_E_health(1) > 0){// o deuteros Exoskeleton kanei epithesi
						int b3 = 0;
						for(i = 0 ; i < heros_w ; i++){
                                                        if(war[i]->get_healthPower() > 0){
								int r  = (rand() % 200) + 1;
                                                                if(r > war[i]->get_agility()){
                                                                        war[i]->set_healthPower((-1)*(S[line][stele]->gE_damage(1)-war[i]->Armor_def()));
                                                                }
								if(war[i]->get_healthPower() <= 0) health_H++;
                                                                b3 = 1;
                                                                break;
							}
                                                }
                                                if(b3 == 0){
                                                        for(i = 0 ; i < heros_s ; i++){
                                                                if(sor[i]->get_healthPower() > 0){
									int r  = (rand() % 200) + 1;
                                                                	if(r > sor[i]->get_agility()){
                                                                        	sor[i]->set_healthPower((-1)*(S[line][stele]->gE_damage(1)-sor[i]->Armor_def()));
                                                                	}
									if(sor[i]->get_healthPower() <= 0) health_H++;
                                                                        b3 = 1;
                                                                        break;
								}
                                                        }
                                                }
                                                if(b3 == 0){
                                                        for(i = 0 ; i < heros_p ; i++){
                                                                if(pal[i]->get_healthPower() > 0){
									int r  = (rand() % 200) + 1;
                                                                	if(r > pal[i]->get_agility()){
                                                                        	pal[i]->set_healthPower((-1)*(S[line][stele]->gE_damage(1)-pal[i]->Armor_def()));
                                                                	}
									if(pal[i]->get_healthPower() <= 0) health_H++;
                                                                        b3 = 1;
                                                                        break;
								}
                                                        }
                                                }
					}
					if(S[line][stele]->get_S_health(0) > 0){// o prwtos spirit kanei epithesi
						int b4 = 0;
						for(i = 0 ; i < heros_w ; i++){
                                                        if(war[i]->get_healthPower() > 0){
								int r  = (rand() % 200) + 1;
                                                                if(r > war[i]->get_agility()){
                                                	                war[i]->set_healthPower((-1)*(S[line][stele]->gS_damage(0)-war[i]->Armor_def()));
                                                                }
								if(war[i]->get_healthPower() <= 0) health_H++;
                                                                b4 = 1;
                                                                break;
							}
                                                }
                                                if(b4 == 0){
                                                        for(i = 0 ; i < heros_s ; i++){
                                                                if(sor[i]->get_healthPower() > 0){
									int r  = (rand() % 200) + 1;
                                                                        if(r > sor[i]->get_agility()){
                                                                                sor[i]->set_healthPower((-1)*(S[line][stele]->gS_damage(0)-sor[i]->Armor_def()));
                                                                        }
									if(sor[i]->get_healthPower() <= 0) health_H++;
                                                                        b4 = 1;
                                                                        break;
								}
                                                        }
                                                }
                                                if(b4 == 0){
                                                        for(i = 0 ; i < heros_p ; i++){
                                                                if(pal[i]->get_healthPower() > 0){
									int r  = (rand() % 200) + 1;
                                                                        if(r > pal[i]->get_agility()){
                                                                                pal[i]->set_healthPower((-1)*(S[line][stele]->gS_damage(0)-pal[i]->Armor_def()));
                                                                        }
									if(pal[i]->get_healthPower() <= 0) health_H++;
                                                                        b4 = 1;
                                                                        break;
								}
                                                        }
                                                }
					}
					if(S[line][stele]->get_S_health(1) > 0){// to ekto kai teleutaio teras diladi o deuteros spirit epitithete
						int b5 = 0;
						for(i = 0 ; i < heros_w ; i++){
                                                        if(war[i]->get_healthPower() > 0){
								int r  = (rand() % 200) + 1;
                                                                if(r > war[i]->get_agility()){
                                                	                war[i]->set_healthPower((-1)*(S[line][stele]->gS_damage(1)-war[i]->Armor_def()));
                                                                }
								if(war[i]->get_healthPower() <= 0) health_H++;
                                                                b5 = 1;
                                                                break;
							}
                                                }
                                                if(b5 == 0){
                                                        for(i = 0 ; i < heros_s ; i++){
                                                                if(sor[i]->get_healthPower() > 0){
									int r  = (rand() % 200) + 1;
									if(r > sor[i]->get_agility()){
										sor[i]->set_healthPower((-1)*(S[line][stele]->gS_damage(1)-sor[i]->Armor_def()));
									}
									if(sor[i]->get_healthPower() <= 0) health_H++;
                                                                        b5 = 1;
                                                                        break;
								}
                                                        }
                                                }
                                                if(b5 == 0){
                                                        for(i = 0 ; i < heros_p ; i++){
                                                                if(pal[i]->get_healthPower() > 0){
									int r  = (rand() % 200) + 1;
									if(r > pal[i]->get_agility()){
										pal[i]->set_healthPower((-1)*(S[line][stele]->gS_damage(1)-pal[i]->Armor_def()));
									}
									if(pal[i]->get_healthPower() <= 0) health_H++;
                                                                        b5 = 1;
                                                                        break;
								}
                                                        }
                                                }
					}
				}
				r++;
				if(health_M >= 6) break;// An ta terata einai olla nekra tote vges apo to loop
			}while(health_H < (heros_w+heros_s+heros_p));// sinexise oso oi irwes den oi nekroi
			if(health_M == 6){
				cout << endl << "     Heros win" << endl << endl;
				int j, xx;
					for(i = 0 ; i < heros_w ; i++){
						if(war[i]->get_healthPower() > 0){
							war[i]->set_money(200*war[i]->get_level());
							xx = war[i]->get_level();
							for(j = 0 ; j < xx ; j++) war[i]->set_exper(40); // experience = 40*level
						}else war[i]->set_health_h();
					}
					for(i = 0 ; i < heros_s ; i++){
                                                if(sor[i]->get_healthPower() > 0){
                                                        sor[i]->set_money(200*sor[i]->get_level());
							xx  = sor[i]->get_level();
							for(j = 0 ; j < xx ; j++) sor[i]->set_exper(40);
                                                }else sor[i]->set_health_h();
                                        }
					for(i = 0 ; i < heros_p ; i++){
                                                if(pal[i]->get_healthPower() > 0){
                                                        pal[i]->set_money(200*pal[i]->get_level());
							xx = pal[i]->get_level();
							for(j = 0 ; j < xx ; j++) pal[i]->set_exper(40);
                                                }else pal[i]->set_health_h();
                                        }
			}else{
				cout << endl << "     Monsters win" << endl << endl;
				for(i = 0 ; i < heros_w ; i++){ war[i]->set_money((-1)*war[i]->get_money()/2); war[i]->set_health_h(); }
                                for(i = 0 ; i < heros_s ; i++){ sor[i]->set_money((-1)*sor[i]->get_money()/2); sor[i]->set_health_h(); }
                                for(i = 0 ; i < heros_p ; i++){ pal[i]->set_money((-1)*pal[i]->get_money()/2); pal[i]->set_health_h(); }
			}
		}
