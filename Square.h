//File: Square.h
#include <iostream>
#include "Item.h"
#include "Hero.h"
#include "Spell.h"

 using namespace std;

 class Square {
 	private:
		Weapon** weap;
                Armor**  arm;
                Potion** pot;
                IceSpell**  ice;
                FireSpell** fire;
                LightingSpell** light;

		Dragon** dra;
		Exoskeleton** exo;
		Spirit** spi;
	public:

		Square(int r);
		~Square();

 		void set();//
		void set2(int level);//

		void show_Weapon()const{ for(int i = 0 ; i < 30 ; i++){ cout << i+1 << ". "; weap[i]->print();} }// emfanizei ta opla pou exei i agora
                void show_Armor()const{ for(int i = 0 ; i < 30 ; i++){ cout << i+1 << ". "; arm[i]->print();} }
                void show_Potion()const{ for(int i = 0 ; i < 30 ; i++){ cout << i+1 << ". "; pot[i]->print();} }
                void show_IceSpell()const{ for(int i = 0 ; i < 30 ; i++){ cout << i+1 << ". "; ice[i]->print();} }
                void show_FireSpell()const{ for(int i = 0 ; i < 30 ; i++){ cout << i+1 << ". "; fire[i]->print();} }
                void show_LightSpell()const{ for(int i = 0 ; i < 30 ; i++){ cout << i+1 << ". "; light[i]->print();} }// emfanizei ta lightingspell pou exei i agora

		Weapon* Weapon_buy(int k){ return new Weapon(*weap[k-1]); } // epistrefei to oplo pou agorase kapoiow iroas
		Armor& Armor_buy(int k)const{ return *this->arm[k-1]; }//
		Potion& Potion_buy(int k)const{ return *this->pot[k-1]; }//
		IceSpell& IceSpell_buy(int k)const{ return *this->ice[k-1]; }//
		FireSpell& FireSpell_buy(int k)const{ return *this->fire[k-1];}//
		LightingSpell& LightSpell_buy(int k)const{ return *this->light[k-1]; }// epistrefei to lighting spell pou agorase kapoios iroas

		int Weapon_value(int k)const { return weap[k-1]->get_value(); }// epistrefei tin timi enos oplou apo tin agora
		int Armor_value(int k)const { return arm[k-1]->get_value(); }
		int Potion_value(int k)const { return pot[k-1]->get_value(); }
		int IceSpell_value(int k)const { return ice[k-1]->get_value(); }
		int FireSpell_value(int k)const { return fire[k-1]->get_value(); }
		int LightingSpell_value(int k)const { return light[k-1]->get_value(); }// epistrefei tin timi enos lightingspell apo tin agora

		int gD_damage(int k)const { return dra[k]->get_damage(); }// epistrefei to damage pou kanei o k dragon
		int gE_damage(int k)const { return exo[k]->get_damage(); }//
		int gS_damage(int k)const { return spi[k]->get_damage(); }// epistrefei to damage pou kanei o k spirit

		int gD_defense(int k)const { return dra[k]->get_defense(); }// epistrefei to defense tou k dragon
		int gE_defense(int k)const { return exo[k]->get_defense(); }//
		int gS_defense(int k)const { return spi[k]->get_defense(); }// epistrefei to defense tou k spirit

		int gD_possibility_of_avoidance(int k){ return dra[k]->get_possibility_of_avoidance(); }// epistrefei tin pithanotita apofigis tou k dragon
		int gE_possibility_of_avoidance(int k){ return exo[k]->get_possibility_of_avoidance(); }//
		int gS_possibility_of_avoidance(int k){ return spi[k]->get_possibility_of_avoidance(); }// epistrefei tin pithanotita apofigis tou k apirit

		void print_Statictics_Monsters()const;// emfanizei statistika gia ta terata

		void set_D_health(int k,int l){ dra[k]->set_healthPower(l); }// allazei tin zotiki energeia kata l tou k dragon
		void set_E_health(int k,int l){ exo[k]->set_healthPower(l); }// allazei tin zotiki energeia kata l tou k exoskeleton
		void set_S_health(int k,int l){ spi[k]->set_healthPower(l); }// allazei tin zotiki energeia kata l tou k spirit

		int get_D_health(int k){ return dra[k]->get_healthPower(); }// epistrefei tin zotiki energeia tou k dragon
		int get_E_health(int k){ return exo[k]->get_healthPower(); }// epistrefei tin zotiki energeia tou k exoskeleton
		int get_S_health(int k){ return spi[k]->get_healthPower(); }// epistrefei tin zotiki energeia tou k spirit
 };
