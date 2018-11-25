//File: Spell.h
#ifndef SPELL_H
#define SPELL_H
#include <iostream>
#include <cstring>

using namespace std;

class Spell {
        private:
                string name;
                int value;	// poso kanei gia agora
                int level_hero; // elaxisto epipedo gia na to xrisimopoiisei
		int damage;	// zimia pou prokalei
		int magic_power; // magiki energei gia na ektelestei
        public:
		Spell(string nam,int val,int level,int dam,int mg):name(nam),value(val),level_hero(level),magic_power(mg),damage(dam){  }
		~Spell(){ }

		int get_value()const { return value; }
		int get_level_hero()const { return level_hero; }
		int get_damage()const { return damage; }
		int get_magic_power()const { return magic_power; }

		void print()const {
			cout << "Spell name: " << name;
			cout << ",  value: " << value;
			cout << ",  level_hero: " << level_hero;
			cout << ",  damage: " << damage;
			cout << ",  wants magic_power: " << magic_power;
		}
};

class IceSpell : public Spell {
        private:
		int reduction_damage; // meiosi zimias pou kanei o antipalos
		int round;	     // gia posous girous
        public:
		IceSpell(string name,int value,int l_h, int r_d,int r,int mg,int dam):reduction_damage(r_d),round(r),
		Spell(name,value,l_h,dam,mg) { }
		~IceSpell(){ }


		int get_reduction_damage()const { return reduction_damage; }
		int get_round()const { return round; }

		void print()const {
			Spell::print();
			cout << ",  reduction_damage: " << reduction_damage;
			cout << ",  round: " << round << endl;
		}
};

class FireSpell : public Spell {
        private:
		int reduction_defense;// miosi tis aminas
		int round;		// gia posous girous
        public:
		FireSpell(string name,int value,int l_h,int r_d,int r,int mg,int dam):reduction_defense(r_d),round(r),
		Spell(name,value,l_h,dam,mg) { }
		~FireSpell(){ }

		int get_reduction_defense()const { return reduction_defense; }
		int get_round()const { return round; }

		void print()const {
                        Spell::print();
                        cout << ",  reduction_defence: " << reduction_defense;
                        cout << ",  round: " << round << endl;
                }
};


class LightingSpell : public Spell {
        private:
		int reduction_possibility; // miosi pithanotitas apofigis epithesi
		int round;		  // gia posous girous
        public:
		LightingSpell(string name,int value,int l_h,int r_p,int r,int mg,int dam):reduction_possibility(r_p),round(r),
		Spell(name,value,l_h,dam,mg) { }
		~LightingSpell(){ }

		int get_reduction_possibility()const { return reduction_possibility; }
		int get_round()const { return round; }

		void print()const {
                        Spell::print();
                        cout << ",  reduction_possibility: " << reduction_possibility;
                        cout << ",  round: " << round << endl;
                }
};
#endif
