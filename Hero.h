// File: Hero.h
#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <vector>
#include "Living.h"
#include "Item.h"
#include "Spell.h"
#include "Monster.h"

using namespace std;

class Hero : public Living {
	private:
		int magicPower;//magiki energeia
		int strength;//dinami
		int dexterity;//epidexiotita
		int agility;//eukinisia
		int money;//xrimata pou exei
		int experience;//poso empirias
	public:
		Hero(string name, int magP, int st, int dex, int ag, int m, int ex): Living(name),magicPower(magP),
		strength(st),dexterity(dex),agility(ag),money(m),experience(ex) { }
		~Hero(){ }

		void set_magicPower(int m){ magicPower += m; }
		void set_money(int m){ money += m; }
		void set_strength(int k=20){ strength += k; }
		void set_agility(int k=10){ agility += k; }
		void set_dexterity(int k=10){ dexterity += k; }
		int set_experience(int m){
			experience += m;
			if(experience > 100){
				if(get_level() < 10){
					set_level();
					experience -= 100;
					return 1;
				}
			}
			return 0;
		}

		int get_money()const{ return money; }
		int get_experience(){ return experience; }
		int get_strength()const{ return strength; }
		int get_dexterity()const{ return dexterity; }
		int get_agility()const{ return agility; }
		int get_magicPower()const{ return magicPower; }

		void print()const {
			cout << "Hero  " << get_name() << endl;
			Living::print();
			cout << "magicPower  " << magicPower << endl;
			cout << "strength  "   << strength << endl;
			cout << "dexterity  "  << dexterity << endl;
			cout << "agility  " << agility << endl;
			cout << "money  " << money << endl;
			cout << "experience  " << experience << endl;
		}
};

class Warrior : public Hero {
	private:
		Weapon** w;
		Armor**  a;
		vector <Weapon*>  weap;
                vector <Armor*>  arm;
                vector <Potion*>  pot;
                vector <IceSpell*> ice;
                vector <FireSpell*> fire;
                vector <LightingSpell*> light;
	public:
		Warrior(string name,int mg = 1000,int st = 50,int dex = 10,int ag = 20,int m= 800,int ex = 0):
		Hero(name,mg,st,dex,ag,m,ex){

			w = new Weapon*[2];
			w[0] = NULL;
			w[1] = NULL;
			a = new Armor*[1];
			a[0] = NULL;
		}
		~Warrior(){

			if(w[0] != NULL) delete w[0];
                        if(w[1] != NULL) delete w[1];
                        delete [] w;
                        if(a[0] != NULL) delete a[0];
                        delete [] a;
		}
		void print()const{
			Hero::print();
			if(w[0] == NULL && w[1] == NULL)
				cout << "The Warrior does not use Weapon" << endl;
			else if((w[0] != NULL && w[1] == NULL) || (w[1] != NULL && w[0] == NULL)){
				if(w[0] != NULL)
					cout << "The Warrior Use one Weapon with damage " << w[0]->get_damage() << endl;
				else
					cout << "The warrior Use one Weapon with damage" << w[1]->get_damage() << endl;
			}else if(w[0] != NULL && w[1] != NULL){
				if(w[0]->get_damage() == w[1]->get_damage())
					cout << "The Warrior use one Wapon with two hand with damage " << w[0]->get_damage() << endl;
				else
					cout << "The Warrior use two Weapon with damage " << w[0]->get_damage() << " and " << w[1]->get_damage() << endl;
			}

			if(a[0] == NULL) cout << "The Warrior does not use Armor" << endl;
			else cout << "The Warrior USE Armor with sub_damage " << a[0]->get_sub_damage() << endl;
			cout << endl;
		}

		int show_Weapon()const;
                int show_Armor()const;
                int show_Potion()const;
		void sell_Weapon(int s);
                void sell_Armor(int s);
                void sell_Potion(int s);
		int show_IceSpell()const;
		int show_FireSpell()const;
		int show_LightingSpell()const;
		void sell_IceSpell(int s);
		void sell_FireSpell(int s);
		void sell_LightingSpell(int s);

		void buy_Weapon(const Weapon& w);
                void buy_Armor(const Armor& a);
                void buy_Potion(const Potion& p);
                void buy_IceSpell(const IceSpell& i);
                void buy_FireSpell(const FireSpell& f);
                void buy_LightingSpell(const LightingSpell& l);

		void w_equip(int);
                void a_equip(int);

                void use_potion(int);

		int attack();

		void set_exper(int);

		int castSpell(int&,int&,int&);

		int Armor_def()const;
};

class Sorcecer : public Hero {
	private:
		Weapon** w;
		Armor**  a;
		vector <Weapon*>  weap;
		vector <Armor*>  arm;
		vector <Potion*>  pot;
		vector <IceSpell*> ice;
		vector <FireSpell*> fire;
		vector <LightingSpell*> light;
	public:
		Sorcecer(string name,int mg = 1000,int st = 30,int dex = 20,int ag = 30,int m= 800,int ex = 0):
		Hero(name,mg,st,dex,ag,m,ex){

			w = new Weapon*[2];
                        w[0] = NULL;
                        w[1] = NULL;
                        a = new Armor*[1];
                        a[0] = NULL;
		}
		~Sorcecer() {
			if(w[0] != NULL) delete w[0];
                        if(w[1] != NULL) delete w[1];
                        delete [] w;
			if(a[0] != NULL) delete a[0];
                        delete [] a;
		}
		void print()const{
			Hero::print();
			if(w[0] == NULL && w[1] == NULL)
				cout << "The Sorcecer does not use Weapon" << endl;
			else if((w[0] != NULL && w[1] == NULL) || (w[1] != NULL && w[0] == NULL)){
				if(w[0] != NULL)
					cout << "The Sorcecer Use one Weapon with damage " << w[0]->get_damage() << endl;
				else
					cout << "The Sorcecer Use one Weapon with damage" << w[1]->get_damage() << endl;
			}else if(w[0] != NULL && w[1] != NULL){
				if(w[0]->get_damage() == w[1]->get_damage())
					cout << "The Sorcecer use one Wapon with two hand with damage " << w[0]->get_damage() << endl;
				else
					cout << "The Sorcecer use two Weapon with damage " << w[0]->get_damage() << " and " << w[1]->get_damage() << endl;
			}

			if(a[0] == NULL) cout << "The Sorcecer does not use Armor" << endl;
			else cout << "The Sorcecer USE Armor with sub_damage " << a[0]->get_sub_damage() << endl;
			cout << endl;
		}

		int show_Weapon()const;
		int show_Armor()const;
		int show_Potion()const;
		void sell_Weapon(int s);
                void sell_Armor(int s);
                void sell_Potion(int s);
		int show_IceSpell()const;
                int show_FireSpell()const;
                int show_LightingSpell()const;
		void sell_IceSpell(int s);
                void sell_FireSpell(int s);
                void sell_LightingSpell(int s);

		void buy_Weapon(const Weapon& w);
		void buy_Armor(const Armor& a);
		void buy_Potion(const Potion& p);
		void buy_IceSpell(const IceSpell& i);
		void buy_FireSpell(const FireSpell& f);
		void buy_LightingSpell(const LightingSpell& l);

		void w_equip(int);
		void a_equip(int);

		void use_potion(int);

		int attack();

		void set_exper(int);

		int castSpell(int&,int&,int&);

		int Armor_def()const;
};

class Paladin : public Hero {
	private:
		Weapon** w;
        	Armor**  a;
        	vector <Weapon*>  weap;
                vector <Armor*>  arm;
                vector <Potion*>  pot;
                vector <IceSpell*> ice;
                vector <FireSpell*> fire;
                vector <LightingSpell*> light;
	public:
		Paladin(string name,int mg = 1000,int st = 50,int dex = 20,int ag = 10,int m= 800,int ex = 0):
		Hero(name,mg,st,dex,ag,m,ex){
			w = new Weapon*[2];
                        w[0] = NULL;
                        w[1] = NULL;
                        a = new Armor*[1];
                        a[0] = NULL;
		}
		~Paladin() {
			if(w[0] != NULL) delete w[0];
			if(w[1] != NULL) delete w[1];
			delete [] w;
			if(a[0] != NULL) delete a[0];
			delete [] a;
		}
		void print()const{
			Hero::print();
			if(w[0] == NULL && w[1] == NULL)
				cout << "The Paladin does not use Weapon" << endl;
			else if((w[0] != NULL && w[1] == NULL) || (w[1] != NULL && w[0] == NULL)){
				if(w[0] != NULL)
					cout << "The Paladin Use one Weapon with damage " << w[0]->get_damage() << endl;
				else
					cout << "The Paladin Use one Weapon with damage" << w[1]->get_damage() << endl;
			}else if(w[0] != NULL && w[1] != NULL){
				if(w[0]->get_damage() == w[1]->get_damage())
					cout << "The Paladin use one Wapon with two hand with damage " << w[0]->get_damage() << endl;
				else
					cout << "The Paladin use two Weapon with damage " << w[0]->get_damage() << " and " << w[1]->get_damage() << endl;
			}

			if(a[0] == NULL) cout << "The Paladin does not use Armor" << endl;
			else cout << "The Paladin USE Armor with sub_damage " << a[0]->get_sub_damage() << endl;
			cout << endl;
		}

		int show_Weapon()const;
		int show_Armor()const;
		int show_Potion()const;
		void sell_Weapon(int s);
                void sell_Armor(int s);
                void sell_Potion(int s);
		int show_IceSpell()const;
                int show_FireSpell()const;
                int show_LightingSpell()const;
		void sell_IceSpell(int s);
                void sell_FireSpell(int s);
                void sell_LightingSpell(int s);

		void buy_Weapon(const Weapon& w);
                void buy_Armor(const Armor& a);
                void buy_Potion(const Potion& p);
                void buy_IceSpell(const IceSpell& i);
                void buy_FireSpell(const FireSpell& f);
                void buy_LightingSpell(const LightingSpell& l);

		void w_equip(int);
                void a_equip(int);

                void use_potion(int);

		int attack();

		void set_exper(int);

		int castSpell(int&,int&,int&);

		int Armor_def()const;
};
#endif
