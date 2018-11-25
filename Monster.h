//File: Monster.h
#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <cstring>
#include "Living.h"

using namespace std;

class Monster : public Living {
	private:
		int damage;//poso zimias
		int defense;//psoo aminas
		int possibility_of_avoidance;//pithanotita apofigis
	public:
		Monster(string name,int level, int dam,int def,double p):Living(name,level),damage(dam),defense(def),
		possibility_of_avoidance(p) { }
		~Monster(){ }

		int get_damage()const { return damage; }
		int get_defense()const { return defense; }
		int get_possibility_of_avoidance()const { return possibility_of_avoidance; }

		void print()const {
			cout << "Monster  " << get_name() << endl;
			Living::print();
			cout << "damage " << damage << endl;
			cout << "defense " << defense << endl;
			cout << "possibility_of_avoidance " << possibility_of_avoidance << endl;
		}
};


class Dragon : public Monster {

	public:
		Dragon(string name,int level,int dam = 50,int def = 10,int p = 10):
		Monster(name,level,dam,def,p) { }
		~Dragon(){ }

		void print()const { Monster::print(); }
};


class Exoskeleton : public Monster {

	public:
		Exoskeleton(string name,int level,int dam = 30,int def = 20,int p = 10):
		Monster(name,level,dam,def,p) { }
		~Exoskeleton() { }

		void print()const { Monster::print(); }
};


class Spirit : public Monster {

	public:
		Spirit(string name,int level,int dam = 30,int def = 10,int p = 20):
		Monster(name,level,dam,def,p) { }
		~Spirit() { }

		void print()const { Monster::print(); }
};
#endif
