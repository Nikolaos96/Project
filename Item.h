//File: Item.h
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>

using namespace std;

class Item {
        private:
                string name;    // to onoma tou
                int value;     // poso kanei gia na to agorasei
                int level_hero; // elaxisto epipedo level gia na to xrisiom
        public:
		Item(string nam,int val,int l_h): name(nam),value(val),level_hero(l_h){ }
		~Item(){ }

		int get_value()const{ return value; }
		int get_level_hero()const { return level_hero; }

		void print()const {
			cout << "Name: " << name ;
			cout << ",  Cost: " << value ;
			cout << ",  Level_hero: " << level_hero;
		}
};

class Weapon : public Item {
        private:
                int damage;
                int hand;
        public:
		Weapon(string name,int value,int l_h,int d,int h):Item(name,value,l_h),
		damage(d),hand(h) {  }
		~Weapon(){ }

		int get_damage()const { return damage; }
		int get_hand()const { return hand; }

		void print()const {
			Item::print();
			cout << ",  Damage: " << damage ;
			cout << ",  Wants hand: " << hand << endl;
		}
};

class Armor : public Item {
        private:
                int sub_damage;
        public:
		Armor(string name,int value,int l_h,int s): Item(name,value,l_h),
		sub_damage(s) { }
		~Armor() { }

		int get_sub_damage()const { return sub_damage; }

		void print()const {
                        Item::print();
                        cout << ",  Sub_damage: " << sub_damage << endl;
                }
};

class Potion : public Item {
        private:
		int stat;
                int increase_statistics;
        public:
		Potion(string name,int value,int l_h,int i_s,int s): Item(name,value,l_h),
		increase_statistics(i_s),stat(s) { }
		~Potion() { }

		int get_increase_statistics()const { return increase_statistics; }
		int get_stat()const { return stat; }

		void print()const {
                        Item::print();
			if(stat == 1) cout << ",  strength++ " << increase_statistics << endl;
			else if(stat == 2) cout << ",  agility++ " << increase_statistics << endl;
			else if(stat == 3) cout << ",  dexterity++ " << increase_statistics << endl;
                }
};
#endif

