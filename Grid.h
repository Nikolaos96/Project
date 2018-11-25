//File: Grid.h
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "Square.h"

 using namespace std;


 class Grid {
	private:
		int heros;   	// to plithos olon ton hrown
		int heros_w; 	// to plithos ton Warrior
		int heros_s; 	// to plithos ton Sorcecer
		int heros_p; 	// to plithos ton Paladin
		int length;  	// to mikos tou plegmatos
		int width;   	// to platos tou plegmatos
		int line;    	// h grammi  stin opoia vriskontai oi hroes
		int stele;   	// h stili stin opoia vriskontai oi hroes

		char ***map; 	// 2D pinakas xaraktiron pou dixnei ti einai to kathe tetragono
		Square ***S;	// ta tetragona tou plegmatos
		Warrior** war;	//
		Sorcecer** sor;	//
		Paladin** pal;	//
	public:
		Grid(int h, int l, int w, int h_w, int h_s, int h_p,string names[9]): length(l),width(w),heros(h),
		heros_w(h_w), heros_s(h_s),heros_p(h_p){

                	if(h_w == 1){
				war = new Warrior*[1];
				war[0] = new Warrior(names[0]);
			}else if(h_w == 2){
				war = new Warrior*[2];
                                war[0] = new Warrior(names[0]);
				war[1] = new Warrior(names[1]);
			}else if(h_w == 3){
				war = new Warrior*[3];
                                war[0] = new Warrior(names[0]);
                                war[1] = new Warrior(names[1]);
				war[2] = new Warrior(names[2]);
			}
			if(h_s == 1){
				sor = new Sorcecer*[1];
				sor[0] = new Sorcecer(names[3]);
			}else if(h_s == 2){
				sor = new Sorcecer*[2];
                                sor[0] = new Sorcecer(names[3]);
				sor[1] = new Sorcecer(names[4]);
			}else if(h_s == 3){
				sor = new Sorcecer*[3];
                                sor[0] = new Sorcecer(names[3]);
                                sor[1] = new Sorcecer(names[4]);
				sor[2] = new Sorcecer(names[5]);
			}
			if(h_p == 1){
				pal = new Paladin*[1];
				pal[0] = new Paladin(names[6]);
			}else if(h_p == 2){
				pal = new Paladin*[2];
                                pal[0] = new Paladin(names[6]);
				pal[1] = new Paladin(names[7]);
			}else if(h_p == 3){
				pal = new Paladin*[3];
                                pal[0] = new Paladin(names[6]);
                                pal[1] = new Paladin(names[7]);
				pal[2] = new Paladin(names[8]);
			}

			S = new Square**[l];
			map = new char**[l];
			for(int i = 0 ; i < l ; i++){
				S[i] = new Square*[w];
				map[i] = new char*[w];
				for(int j = 0 ; j < w ; j++){
					int r = (rand() % 3) + 1;
					if (r == 1){
						S[i][j] = new Square(1);
						map[i][j] = new char('n');
					}else if(r == 2){
						S[i][j] = new Square(2);
						map[i][j] = new char('m');
					}else if(r == 3){
						S[i][j] = new Square(3);
						map[i][j] = new char('c');
					}
				}
			}
			line  = 4; // arxika oi iroes vriskontai sti grammi kai stili 4
			stele = 4; // diladii vriskontai sti mesi tou plegmatos,sto kentriko tetragono

		}
		~Grid(){
			for(int i = 0 ; i < heros_w ; i++){ delete war[i]; if(i == heros_w-1) delete [] war; }
			for(int i = 0 ; i < heros_s ; i++){ delete sor[i]; if(i == heros_s-1) delete [] sor; }
			for(int i = 0 ; i < heros_p ; i++){ delete pal[i]; if(i == heros_p-1) delete [] pal; }
			for(int i = 0 ; i < length ; i++){
				for(int j = 0 ; j < width ; j++){
					delete map[i][j];
					delete S[i][j];
				}
				delete [] map[i];
				delete [] S[i];
			}
			delete [] map;
			delete []  S;
		}
		int move();
		void buy();

		void sell();
		void checkInventory();

		void equip(int);
		void use(int);

		void Hero_Info()const ;
		void displayMap()const;

		void square_set(int);
		void fight();
};
