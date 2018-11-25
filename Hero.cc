// File: Hero.cc
#include <iostream>
#include <cstring>
#include <vector>
#include "Hero.h"

 using namespace std;

	int Warrior::show_Weapon()const {
			if(weap.size()){
				cout << " Your weapon are " << endl << endl;
                        	for(int i = 0 ; i < weap.size() ; i++){ cout << i+1 << "  "; weap[i]->print(); }
				return 1;
			}else {
				cout << "Warrior haven't weapons" << endl; return 0; }
                }

	int Warrior::show_Armor()const {
			if(arm.size()){
                        	cout << " Your Armors are " << endl << endl;
                        	for(int i = 0 ; i < arm.size() ; i++){ cout << i+1 << " "; arm[i]->print(); }
				return 1;
			}else{
				cout << "Warrior haven't armors" << endl; return 0; }
                }

	int Warrior::show_Potion()const {
			if(pot.size()){
                        	cout << " Your Potion are " << endl << endl;
                        	for(int i = 0 ; i < pot.size() ; i++){ cout << i+1 << " "; pot[i]->print(); }
				return 1;
			}else{
				cout << "Warrior haven't Potion" << endl; return 0; }
                }

	void Warrior::sell_Weapon(int s) {
                        if(s <= weap.size()){
				if(w[0] != NULL){
					if(w[0]->get_damage() == weap[s-1]->get_damage()){
						delete w[0];  w[0] = NULL;
					}
				}
				if(w[1] != NULL){
					if(w[1]->get_damage() == weap[s-1]->get_damage()){
						delete w[1];  w[1] = NULL;
					}
				}
                                set_money(weap[s-1]->get_value() / 2);
                                weap.erase(weap.begin()+(s-1));
                                cout << "Weapon sell"<< endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Warrior::sell_Armor(int s) {
                        if(s <= arm.size()){
				if(a[0] != NULL){
					if(a[0]->get_sub_damage() == arm[s-1]->get_sub_damage()){
						delete a[0];  a[0] = NULL;
					}
				}
                                set_money(arm[s-1]->get_value() / 2);
                                arm.erase(arm.begin()+(s-1));
                                cout << "Armor sell" << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Warrior::sell_Potion(int s){
                        if(s <= pot.size()){
                                set_money(pot[s-1]->get_value() / 2);
                                pot.erase(pot.begin()+(s-1));
                                cout << "Potion sell" << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	int Warrior::show_IceSpell()const {
			if(ice.size()){
                        	cout << "Your IceSpell are " << endl << endl;
                        	for(int i = 0 ; i < ice.size() ; i++){ cout << i+1 << " "; ice[i]->print(); }
				return 1;
			}else{
				cout << "Warrior haven't IceSpells" << endl; return 0; }
                }

	int Warrior::show_FireSpell()const {
			if(fire.size()){
                        	cout << "Your FireSpell are " << endl << endl;
                        	for(int i = 0 ; i < fire.size() ; i++){ cout << i+1 << " "; fire[i]->print(); }
				return 1;
			}else{
				cout << "Warrior haven't FireSpells" << endl; return 0; }
                }

	int Warrior::show_LightingSpell()const {
			if(light.size()){
                        	cout << "Your LightSpell are " << endl << endl;
                        	for(int i = 0 ; i < light.size() ; i++){ cout << i+1 << " "; light[i]->print(); }
				return 1;
			}else{
				cout << "Warrior haven't LightingSpells" << endl; return 0; }
                }

	void Warrior::sell_IceSpell(int s){
                        if(s <= ice.size()){
                                set_money(ice[s-1]->get_value() / 2);
                                ice.erase(ice.begin()+(s-1));
                                cout << "IceSpell sell " << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Warrior::sell_FireSpell(int s){
                        if(s <= fire.size()){
                                set_money(fire[s-1]->get_value() / 2);
                                fire.erase(fire.begin()+(s-1));
                                cout << "FireSpell sell" << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Warrior::sell_LightingSpell(int s){
                        if(s <= light.size()){
                                set_money(light[s-1]->get_value() / 2);
                                light.erase(light.begin()+(s-1));
                                cout << "lightSpell sell" << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }
	void Warrior::buy_Weapon(const Weapon& w){
		if(weap.size() < 10){
			weap.push_back(new Weapon(w));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 10 Weapons can not buy more" << endl << endl;
	}
	void Warrior::buy_Armor(const Armor& a){
		if(arm.size() < 10){
			arm.push_back(new Armor(a));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 10 Armors can not buy more" << endl << endl;
	}
	void Warrior::buy_Potion(const Potion& p){
		if(pot.size() < 5){
			pot.push_back(new Potion(p));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 5 Potions can not buy more" << endl << endl;
	}
	void Warrior::buy_IceSpell(const IceSpell& i){
		if(ice.size() < 5){
			ice.push_back(new IceSpell(i));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 5 IceSpell can not buy more" << endl << endl;
	}
	void Warrior::buy_FireSpell(const FireSpell& f){
		if(fire.size() < 5){
			fire.push_back(new FireSpell(f));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 5 FireSpell can not buy more" << endl << endl;
	}
	void Warrior::buy_LightingSpell(const LightingSpell& l){
		if(light.size() < 5){
			light.push_back(new LightingSpell(l));
			cout << "The buy was completed"<<endl<<endl;
		}else cout << "You have 5 LightingSpell can not buy more" << endl << endl;
	}

	void Warrior::w_equip(int k){
		if(k <= weap.size() && k > 0){
			if(get_level() >= weap[k-1]->get_level_hero()){
				if(weap[k-1]->get_hand() == 1){
					if(w[0] == NULL) w[0] = new Weapon(*weap[k-1]);
					else if(w[1] == NULL) w[1] = new Weapon(*weap[k-1]);
					else{
						delete w[0];
						w[0] = new Weapon(*weap[k-1]);
					}
				}else{
					if(w[0] != NULL) delete w[0];
					if(w[1] != NULL) delete w[1];
					w[0] = new Weapon(*weap[k-1]);
					w[1] = new Weapon(*weap[k-1]);
				}
			}else cout << "The warrior is not enough level for this weapon" << endl;
		}else cout << "Wrong Choice" << endl;
	}



        void Warrior::a_equip(int k){
		if(k <= arm.size() && k > 0){
			if(a[0] == NULL) a[0] = new Armor(*arm[k-1]);
			else{
				delete a[0];
				a[0] = new Armor(*arm[k-1]);
			}
		}else cout << "Wrong Choice" << endl;

	}

        void Warrior::use_potion(int k){
		if(k <= pot.size() && k > 0){
			if(pot[k-1]->get_level_hero() <= get_level()){
				if(pot[k-1]->get_stat() == 1) set_strength(pot[k-1]->get_increase_statistics());
				else if(pot[k-1]->get_stat() == 2) set_agility(pot[k-1]->get_increase_statistics());
				else set_dexterity(pot[k-1]->get_increase_statistics());
				pot.erase(pot.begin()+(k-1));
			}else cout << "Can not use this potion" << endl;
		}else
			cout << "Wrong Choice" << endl;
	}

	int Warrior::attack(){
		int d = 0;
		if(w[0] != NULL) d += w[0]->get_damage();
		if(w[1] != NULL) if(w[1]->get_damage() != d) d += w[1]->get_damage();
		d += get_strength();
		return d;
	}

	int Warrior::castSpell(int &a,int &b,int &round){
		int k, l;
		if(ice.size() > 0 || fire.size() > 0 || light.size() > 0){
		do{
			if(ice.size() > 0) cout << "For IceSpell press 1" << endl;
			if(fire.size() > 0) cout << "For FireSpell press 2" << endl;
			if(light.size() > 0) cout << "For LightingSpell press 3" << endl;
			cin >> k;
			if(k == 1){
				show_IceSpell();
				cout << "Who icespell you want" << endl;
				cin >> l;
				if(ice[l-1]->get_level_hero() <= get_level() && get_magicPower() >= ice[l-1]->get_magic_power()){
					a = ice[l-1]->get_damage() + get_dexterity()/2;
					b = ice[l-1]->get_reduction_damage();
					round = ice[l-1]->get_round();
					set_magicPower((-1)*ice[l-1]->get_magic_power());
					return 1;
				}
			}else if(k == 2){
				show_FireSpell();
				cout << "Who firespell you want" << endl;
	                        cin >> l;
				if(fire[l-1]->get_level_hero() <= get_level() && get_magicPower() >= fire[l-1]->get_magic_power()){
	                                a = fire[l-1]->get_damage() + get_dexterity()/2;
        	                        b = fire[l-1]->get_reduction_defense();
                                	round = fire[l-1]->get_round();
	                                set_magicPower((-1)*fire[l-1]->get_magic_power());
        	                        return 2;
                	        }
			}else if(k == 3){
				show_LightingSpell();
        	                cout << "Who firespell you want" << endl;
                	        cin >> l;
	                        if(light[l-1]->get_level_hero() <= get_level() && get_magicPower() >= light[l-1]->get_magic_power()){
        	                        a = light[l-1]->get_damage() + get_dexterity()/2;
	                                b = light[l-1]->get_reduction_possibility();
                	                round = light[l-1]->get_round();
                        	        set_magicPower((-1)*light[l-1]->get_magic_power());
                                	return 3;
             	           	}
			}else cout << "Wrong Choice" << endl;
		}while(k != 1 && k != 2 && k != 3);
		}else{
			cout << "warrior haven't spell" << endl;
			return 0;
		}
	}

	void Warrior::set_exper(int k){
		if(set_experience(k) == 1){// o iroas anebike epipedo ta xaraktiristika tou ayxanontai
			set_strength(20);
                	set_agility(15);
                	set_dexterity(10);
		}
	}

	int Warrior::Armor_def()const{
		if(a[0] == NULL)return 0;
		else return a[0]->get_sub_damage();
	}

//------------------------------------------------------------------------------------------------------------

	int Sorcecer::show_Weapon()const {
			if(weap.size()){
				cout << " Your weapon are " << endl << endl;
                        	for(int i = 0 ; i < weap.size() ; i++){ cout << i+1 << "  "; weap[i]->print(); }
				return 1;
			}else {
				cout << "Sorcecer haven't weapons" << endl; return 0; }
                }

	int Sorcecer::show_Armor()const {
			if(arm.size()){
                        	cout << " Your Armors are " << endl << endl;
                        	for(int i = 0 ; i < arm.size() ; i++){ cout << i+1 << " "; arm[i]->print(); }
				return 1;
			}else{
				cout << "Sorcecer  haven't armors" << endl; return 0; }
                }

	int Sorcecer::show_Potion()const {
			if(pot.size()){
                        	cout << " Your Potion are " << endl << endl;
                        	for(int i = 0 ; i < pot.size() ; i++){ cout << i+1 << " "; pot[i]->print(); }
				return 1;
			}else{
				cout << "Sorcecer haven't Potion" << endl; return 0; }
                }

	void Sorcecer::sell_Weapon(int s) {
                        if(s <= weap.size()){
				if(w[0] != NULL){
                                        if(w[0]->get_damage() == weap[s-1]->get_damage()){
                                                delete w[0];  w[0] = NULL;
                                        }
                                }
                                if(w[1] != NULL){
                                        if(w[1]->get_damage() == weap[s-1]->get_damage()){
                                                delete w[1];  w[1] = NULL;
                                        }
                                }
                                set_money(weap[s-1]->get_value() / 2);
                                weap.erase(weap.begin()+(s-1));
                                cout << "Weapon sell"<< endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Sorcecer::sell_Armor(int s) {
                        if(s <= arm.size()){
				if(a[0] != NULL){
                                        if(a[0]->get_sub_damage() == arm[s-1]->get_sub_damage()){
                                                delete a[0];  a[0] = NULL;
                                        }
                                }
                                set_money(arm[s-1]->get_value() / 2);
                                arm.erase(arm.begin()+(s-1));
                                cout << "Armor sell" << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Sorcecer::sell_Potion(int s){
                        if(s <= pot.size()){
                                set_money(pot[s-1]->get_value() / 2);
                                pot.erase(pot.begin()+(s-1));
                                cout << "Potion sell" << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	int Sorcecer::show_IceSpell()const {
			if(ice.size()){
                        	cout << "Your IceSpell are " << endl << endl;
                        	for(int i = 0 ; i < ice.size() ; i++){ cout << i+1 << " "; ice[i]->print(); }
				return 1;
			}else{
				cout << "Sorcecer haven't IceSpells" << endl; return 0; }
                }

	int Sorcecer::show_FireSpell()const {
			if(fire.size()){
                        	cout << "Your FireSpell are " << endl << endl;
                        	for(int i = 0 ; i < fire.size() ; i++){ cout << i+1 << " "; fire[i]->print(); }
				return 1;
			}else{
				cout << "Sorcecer haven't FireSpells" << endl; return 0; }
                }

	int Sorcecer::show_LightingSpell()const {
			if(light.size()){
                        	cout << "Your LightSpell are " << endl << endl;
                        	for(int i = 0 ; i < light.size() ; i++){ cout << i+1 << " "; light[i]->print(); }
				return 1;
			}else{
				cout << "Sorcecer haven't LightingSpells" << endl; return 0; }
                }

	void Sorcecer::sell_IceSpell(int s){
                        if(s <= ice.size()){
                                set_money(ice[s-1]->get_value() / 2);
                                ice.erase(ice.begin()+(s-1));
                                cout << "IceSpell sell " << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Sorcecer::sell_FireSpell(int s){
                        if(s <= fire.size()){
                                set_money(fire[s-1]->get_value() / 2);
                                fire.erase(fire.begin()+(s-1));
                                cout << "FireSpell sell" << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Sorcecer::sell_LightingSpell(int s){
                        if(s <= light.size()){
                                set_money(light[s-1]->get_value() / 2);
                                light.erase(light.begin()+(s-1));
                                cout << "lightSpell sell" << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Sorcecer::buy_Weapon(const Weapon& w){
		if(weap.size() < 10){
			weap.push_back(new Weapon(w));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 10 Weapons can not buy more" << endl << endl;
	}
	void Sorcecer::buy_Armor(const Armor& a){
		if(arm.size() < 10){
			arm.push_back(new Armor(a));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 10 Armors can not buy more" << endl << endl;
	}
	void Sorcecer::buy_Potion(const Potion& p){
		if(pot.size() < 5){
			pot.push_back(new Potion(p));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 5 Potions can not buy more" << endl << endl;
	}
	void Sorcecer::buy_IceSpell(const IceSpell& i){
		if(ice.size() < 5){
			ice.push_back(new IceSpell(i));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 5 IceSpell can not buy more" << endl << endl;
	}
	void Sorcecer::buy_FireSpell(const FireSpell& f){
		if(fire.size() < 5){
			fire.push_back(new FireSpell(f));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 5 FireSpell can not buy more" << endl << endl;
	}
	void Sorcecer::buy_LightingSpell(const LightingSpell& l){
		if(light.size() < 5){
			light.push_back(new LightingSpell(l));
			cout << "The buy was completed"<<endl<<endl;
		}else cout << "You have 5 LightingSpell can not buy more" << endl << endl;
	}


	void Sorcecer::w_equip(int k){
		if(k <= weap.size() && k > 0){
			if(get_level() >= weap[k-1]->get_level_hero()){
			if(weap[k-1]->get_hand() == 1){
				if(w[0] == NULL) w[0] = new Weapon(*weap[k-1]);
				else if(w[1] == NULL) w[1] = new Weapon(*weap[k-1]);
				else{
					delete w[0];
					w[0] = new Weapon(*weap[k-1]);
				}
			}else{
				if(w[0] != NULL) delete w[0];
				if(w[1] != NULL) delete w[1];
				w[0] = new Weapon(*weap[k-1]);
				w[1] = new Weapon(*weap[k-1]);
			}
			}else cout << "The warrior is not enough level for this weapon" << endl;
		}else cout << "Wrong Choice" << endl;
	}



        void Sorcecer::a_equip(int k){
		if(k <= arm.size() && k > 0){
			if(a[0] == NULL) a[0] = new Armor(*arm[k-1]);
			else{
				delete a[0];
				a[0] = new Armor(*arm[k-1]);
			}
		}else cout << "Wrong Choice" << endl;

	}

        void Sorcecer::use_potion(int k){
		if(k <= pot.size() && k > 0){
			if(pot[k-1]->get_level_hero() <= get_level()){
				if(pot[k-1]->get_stat() == 1) set_strength(pot[k-1]->get_increase_statistics());
				else if(pot[k-1]->get_stat() == 2) set_agility(pot[k-1]->get_increase_statistics());
				else set_dexterity(pot[k-1]->get_increase_statistics());
				pot.erase(pot.begin()+(k-1));
			}else cout << "Can not use this potion" << endl;
		}else
			cout << "Wrong Choice" << endl;
	}

	int Sorcecer::attack(){
		int d = 0;
		if(w[0] != NULL) d += w[0]->get_damage();
		if(w[1] != NULL) if(w[1]->get_damage() != d) d += w[1]->get_damage();
		d += get_strength();
		return d;
	}

	int Sorcecer::castSpell(int &a,int &b,int &round){
		int k, l;
		if(ice.size() > 0 || fire.size() > 0 || light.size() > 0){
		do{
			if(ice.size() > 0) cout << "For IceSpell press 1" << endl;
			if(fire.size() > 0) cout << "For FireSpell press 2" << endl;
			if(light.size() > 0) cout << "For LightingSpell press 3" << endl;
			cin >> k;
			if(k == 1){
				show_IceSpell();
				cout << "Who icespell you want" << endl;
				cin >> l;
				if(ice[l-1]->get_level_hero() <= get_level() && get_magicPower() >= ice[l-1]->get_magic_power()){
					a = ice[l-1]->get_damage() + get_dexterity()/2;
					b = ice[l-1]->get_reduction_damage();
					round = ice[l-1]->get_round();
					set_magicPower((-1)*ice[l-1]->get_magic_power());
					return 1;
				}
			}else if(k == 2){
				show_FireSpell();
				cout << "Who firespell you want" << endl;
                	        cin >> l;
				if(fire[l-1]->get_level_hero() <= get_level() && get_magicPower() >= fire[l-1]->get_magic_power()){
        	                        a = fire[l-1]->get_damage() + get_dexterity()/2;
                	                b = fire[l-1]->get_reduction_defense();
                        	        round = fire[l-1]->get_round();
	                                set_magicPower((-1)*fire[l-1]->get_magic_power());
        	                        return 2;
                	        }
			}else if(k == 3){
				show_LightingSpell();
	                        cout << "Who firespell you want" << endl;
        	                cin >> l;
                	        if(light[l-1]->get_level_hero() <= get_level() && get_magicPower() >= light[l-1]->get_magic_power()){
	                                a = light[l-1]->get_damage() + get_dexterity()/2;
        	                        b = light[l-1]->get_reduction_possibility();
                	                round = light[l-1]->get_round();
	                                set_magicPower((-1)*light[l-1]->get_magic_power());
        	                        return 3;
                	        }
			}else cout << "Wrong Choice" << endl;
		}while(k != 1 && k != 2 && k != 3);
		}else{
			cout << "warrior haven't spell" << endl;
			return 0;
		}
	}

	void Sorcecer::set_exper(int k){
		if(set_experience(k) == 1){ // o iroas anebike epipedo ta xaraktiristika tou ayxanontai
			set_strength(10);
                	set_agility(15);
                	set_dexterity(20);
		}
	}

	int Sorcecer::Armor_def()const{
		if(a[0] == NULL)return 0;
		else return a[0]->get_sub_damage();
	}



//-------------------------------------------------------------------------------------------------------------------


	int Paladin::show_Weapon()const {
			if(weap.size()){
				cout << " Your weapon are " << endl << endl;
                        	for(int i = 0 ; i < weap.size() ; i++){ cout << i+1 << "  "; weap[i]->print(); }
				return 1;
			}else {
				cout << "Paladin haven't weapons" << endl; return 0; }
                }

	int Paladin::show_Armor()const {
			if(arm.size()){
                        	cout << " Your Armors are " << endl << endl;
                        	for(int i = 0 ; i < arm.size() ; i++){ cout << i+1 << " "; arm[i]->print(); }
				return 1;
			}else{
				cout << "Paladin haven't armors" << endl; return 0; }
                }

	int Paladin::show_Potion()const {
			if(pot.size()){
                        	cout << " Your Potion are " << endl << endl;
                        	for(int i = 0 ; i < pot.size() ; i++){ cout << i+1 << " "; pot[i]->print(); }
				return 1;
			}else{
				cout << "Paladin haven't Potion" << endl; return 0; }
                }

	void Paladin::sell_Weapon(int s) {
                        if(s <= weap.size()){
				if(w[0] != NULL){
                                        if(w[0]->get_damage() == weap[s-1]->get_damage()){
                                                delete w[0];  w[0] = NULL;
                                        }
                                }
                                if(w[1] != NULL){
                                        if(w[1]->get_damage() == weap[s-1]->get_damage()){
                                                delete w[1];  w[1] = NULL;
                                        }
                                }
                                set_money(weap[s-1]->get_value() / 2);
                                weap.erase(weap.begin()+(s-1));
                                cout << "Weapon sell"<< endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Paladin::sell_Armor(int s) {
                        if(s <= arm.size()){
				if(a[0] != NULL){
                                        if(a[0]->get_sub_damage() == arm[s-1]->get_sub_damage()){
                                                delete a[0];  a[0] = NULL;
                                        }
                                }
                                set_money(arm[s-1]->get_value() / 2);
                                arm.erase(arm.begin()+(s-1));
                                cout << "Armor sell" << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Paladin::sell_Potion(int s){
                        if(s <= pot.size()){
                                set_money(pot[s-1]->get_value() / 2);
                                pot.erase(pot.begin()+(s-1));
                                cout << "Potion sell" << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	int Paladin::show_IceSpell()const {
			if(ice.size()){
                        	cout << "Your IceSpell are " << endl << endl;
                        	for(int i = 0 ; i < ice.size() ; i++){ cout << i+1 << " "; ice[i]->print(); }
				return 1;
			}else{
				cout << "Paladin haven't IceSpells" << endl; return 0; }
                }

	int Paladin::show_FireSpell()const {
			if(fire.size()){
                        	cout << "Your FireSpell are " << endl << endl;
                        	for(int i = 0 ; i < fire.size() ; i++){ cout << i+1 << " "; fire[i]->print(); }
				return 1;
			}else{
				cout << "Paladin haven't FireSpells" << endl; return 0; }
                }

	int Paladin::show_LightingSpell()const {
			if(light.size()){
                        	cout << "Your LightSpell are " << endl << endl;
                        	for(int i = 0 ; i < light.size() ; i++){ cout << i+1 << " "; light[i]->print(); }
				return 1;
			}else{
				cout << "Paladin haven't LightingSpells" << endl; return 0; }
                }

	void Paladin::sell_IceSpell(int s){
                        if(s <= ice.size()){
                                set_money(ice[s-1]->get_value() / 2);
                                ice.erase(ice.begin()+(s-1));
                                cout << "IceSpell sell " << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Paladin::sell_FireSpell(int s){
                        if(s <= fire.size()){
                                set_money(fire[s-1]->get_value() / 2);
                                fire.erase(fire.begin()+(s-1));
                                cout << "FireSpell sell" << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }

	void Paladin::sell_LightingSpell(int s){
                        if(s <= light.size()){
                                set_money(light[s-1]->get_value() / 2);
                                light.erase(light.begin()+(s-1));
                                cout << "lightSpell sell" << endl;
                        }else
				cout << "Wrong Choice" << endl;
                }
	void Paladin::buy_Weapon(const Weapon& w){
		if(weap.size() < 10){
			weap.push_back(new Weapon(w));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 10 Weapons can not buy more" << endl << endl;
	}
	void Paladin::buy_Armor(const Armor& a){
		if(arm.size() < 10){
			arm.push_back(new Armor(a));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 10 Armors can not buy more" << endl << endl;
	}
	void Paladin::buy_Potion(const Potion& p){
		if(pot.size() < 5){
			pot.push_back(new Potion(p));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 5 Potions can not buy more" << endl << endl;
	}
	void Paladin::buy_IceSpell(const IceSpell& i){
		if(ice.size() < 5){
			ice.push_back(new IceSpell(i));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 5 IceSpell can not buy more" << endl << endl;
	}
	void Paladin::buy_FireSpell(const FireSpell& f){
		if(fire.size() < 5){
			fire.push_back(new FireSpell(f));
			cout << "The buy was completed" << endl << endl;
		}else cout << "You have 5 FireSpell can not buy more" << endl << endl;
	}
	void Paladin::buy_LightingSpell(const LightingSpell& l){
		if(light.size() < 5){
			light.push_back(new LightingSpell(l));
			cout << "The buy was completed"<<endl<<endl;
		}else cout << "You have 5 LightingSpell can not buy more" << endl << endl;
	}



	void Paladin::w_equip(int k){
		if(k <= weap.size() && k > 0){
			if(get_level() >= weap[k-1]->get_level_hero()){
			if(weap[k-1]->get_hand() == 1){
				if(w[0] == NULL) w[0] = new Weapon(*weap[k-1]);
				else if(w[1] == NULL) w[1] = new Weapon(*weap[k-1]);
				else{
					delete w[0];
					w[0] = new Weapon(*weap[k-1]);
				}
			}else{
				if(w[0] != NULL) delete w[0];
				if(w[1] != NULL) delete w[1];
				w[0] = new Weapon(*weap[k-1]);
				w[1] = new Weapon(*weap[k-1]);
			}
			}else cout << "The warrior is not enough level for this weapon" << endl;
		}else cout << "Wrong Choice" << endl;
	}



        void Paladin::a_equip(int k){
		if(k <= arm.size() && k > 0){
			if(a[0] == NULL) a[0] = new Armor(*arm[k-1]);
			else{
				delete a[0];
				a[0] = new Armor(*arm[k-1]);
			}
		}else cout << "Wrong Choice" << endl;

	}

        void Paladin::use_potion(int k){
		if(k <= pot.size() && k > 0){
			if(pot[k-1]->get_level_hero() <= get_level()){
				if(pot[k-1]->get_stat() == 1) set_strength(pot[k-1]->get_increase_statistics());
				else if(pot[k-1]->get_stat() == 2) set_agility(pot[k-1]->get_increase_statistics());
				else set_dexterity(pot[k-1]->get_increase_statistics());
				pot.erase(pot.begin()+(k-1));
			}else cout << "Can not use this potion" << endl;
		}else
			cout << "Wrong Choice" << endl;
	}

	int Paladin::attack(){
		int d = 0;
		if(w[0] != NULL) d += w[0]->get_damage();
		if(w[1] != NULL) if(w[1]->get_damage() != d) d += w[1]->get_damage();
		d += get_strength();
		return d;
	}

	int Paladin::castSpell(int &a,int &b,int &round){
		int k, l;
		if(ice.size() > 0 || fire.size() > 0 || light.size() > 0){
		do{
			if(ice.size() > 0) cout << "For IceSpell press 1" << endl;
			if(fire.size() > 0) cout << "For FireSpell press 2" << endl;
			if(light.size() > 0) cout << "For LightingSpell press 3" << endl;
			cin >> k;
			if(k == 1){
				show_IceSpell();
				cout << "Who icespell you want" << endl;
				cin >> l;
				if(ice[l-1]->get_level_hero() <= get_level() && get_magicPower() >= ice[l-1]->get_magic_power()){
					a = ice[l-1]->get_damage() + get_dexterity()/2;
					b = ice[l-1]->get_reduction_damage();
					round = ice[l-1]->get_round();
					set_magicPower((-1)*ice[l-1]->get_magic_power());
					return 1;
				}
			}else if(k == 2){
				show_FireSpell();
				cout << "Who firespell you want" << endl;
                	        cin >> l;
				if(fire[l-1]->get_level_hero() <= get_level() && get_magicPower() >= fire[l-1]->get_magic_power()){
	                                a = fire[l-1]->get_damage() + get_dexterity()/2;
        	                        b = fire[l-1]->get_reduction_defense();
                	                round = fire[l-1]->get_round();
                        	        set_magicPower((-1)*fire[l-1]->get_magic_power());
	                                return 2;
        	                }
			}else if(k == 3){
				show_LightingSpell();
                	        cout << "Who firespell you want" << endl;
	                        cin >> l;
        	                if(light[l-1]->get_level_hero() <= get_level() && get_magicPower() >= light[l-1]->get_magic_power()){
        	                        a = light[l-1]->get_damage() + get_dexterity()/2;
                	                b = light[l-1]->get_reduction_possibility();
                        	        round = light[l-1]->get_round();
                        	        set_magicPower((-1)*light[l-1]->get_magic_power());
                                	return 3;
	                        }
			}else cout << "Wrong Choice" << endl;
		}while(k != 1 && k != 2 && k != 3);
		}else{
			cout << "warrior haven't spell" << endl;
			return 0;
		}
	}

	void Paladin::set_exper(int k){
		if(set_experience(k)){ // o iroas anebike epipedo ta xaraktiristika tou ayxanontai
			set_strength(20);
                	set_agility(10);
                	set_dexterity(20);
		}
	}

	int Paladin::Armor_def()const{
		if(a[0] == NULL)return 0;
		else return a[0]->get_sub_damage();
	}

