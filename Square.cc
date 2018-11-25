//File: Square.cc
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "Square.h"

using namespace std;

	Square::Square(int r){
                        if(r == 1){// An to tetragono einai nonAccessible
                                weap = NULL; ice = NULL;
                                arm = NULL;  fire = NULL;
                                pot = NULL;  light = NULL;
                                dra = NULL; exo = NULL;
                                spi = NULL;
                        }else if(r == 2){// An to tetragono einai market
                                weap = new Weapon*[30];
                                arm = new Armor*[30];
                                pot = new Potion*[30];
                                ice = new IceSpell*[30];
                                fire = new FireSpell*[30];
                                light = new LightingSpell*[30];
                                dra = NULL; exo = NULL; spi = NULL;
                        }else if(r == 3){// An to tetragono einai commom
                                weap = NULL; ice = NULL;
                                arm = NULL;  fire = NULL;
                                pot = NULL;  light = NULL;
                                dra = new Dragon*[2]; dra[0] = NULL; dra[1] = NULL;
                                exo = new Exoskeleton*[2]; exo[0] = NULL; exo[1] = NULL;
                                spi = new Spirit*[2]; spi[0] = NULL; spi[1] = NULL;
                        }
         }


	Square::~Square(){
                        if(weap != NULL){
                                for(int i = 0 ; i < 30 ; i++){
                                        delete weap[i];
                                        delete arm[i];
                                        delete pot[i];
                                        delete ice[i];
                                        delete fire[i];
                                        delete light[i];
                                }
                                delete [] weap;
                                delete [] arm;
                                delete [] pot;
                                delete [] ice;
                                delete [] fire;
                                delete [] light;
                        }
                        if(dra != NULL){
                                delete dra[0];
                                delete dra[1];
                                delete [] dra;
                                delete exo[0];
                                delete exo[1];
                                delete [] exo;
                                delete spi[0];
                                delete spi[1];
                                delete [] spi;
                        }
	}


	void Square::set(){// Dimiourgei tin agora.Diavagei onmata gia ta antikeimena apo ta arxeia
                        ifstream file_f;
                        file_f.open("weapons.txt");
                        ifstream file_f2;
                        file_f2.open("armors.txt");
                        ifstream file_f3;
                        file_f3.open("potions.txt");
                        ifstream file_f4;
                        file_f4.open("spells.txt");

                        string str1,str2,str3,str4,str5,str6;
                        int i = 0, hand = 1, dam = 10;
                        int j = 0, damage = 40, magic = 100;
                        int sub_dam = 10, round = 1;
                        int r_damage = 10, r_defense = 10, r_possibility = 10;

                        while(file_f >> str1){
                                weap[i] = new Weapon(str1,200+i*30,j,damage+20*i,hand);
                                file_f2 >> str2;
                                arm[i] = new Armor(str2,200+i*30,j,i*8+sub_dam);
                                file_f3 >> str3;
                                pot[i] = new Potion(str3,230+i*30,j,3*i+10,(i%3)+1);
                                file_f4 >> str4;
                                ice[i] = new IceSpell(str4,200+i*30,j,r_damage+10*i,round,magic+i*15,dam); ///////////////////////
                                file_f4 >> str5;
                                fire[i] = new FireSpell(str5,200+i*30,j,r_defense+5*i,round,magic+i*15,dam);/////////////////////
                                file_f4 >> str6;
                                light[i] = new LightingSpell(str6,200+i*30,j,r_possibility+5*i,round,magic+i*15,dam);////////////////
                                if(i % 6 == 0) round++;
                                if(i % 4 == 0) j++;
                                if(i == 14) hand = 2;
                                if(i % 10 == 0) r_possibility += 15;
				dam += 10;
                                i++;
                        }
                        file_f.close();
                        file_f2.close();
                        file_f3.close();
                        file_f4.close();
                }

	void Square::set2(int level){// Dimiourgei ta terata me level idio me kapoion apo tous iroes

                        if(dra[0] != NULL){
                                delete dra[0]; delete dra[1];
                                delete exo[0]; delete exo[1];
                                delete spi[0]; delete spi[1];
                        }
                        dra[0] = new Dragon("Axe",level,50*level,20*level,11*level+20);
                        dra[1] = new Dragon("Razor",level,50*level,20*level,11*level+20);
                        exo[0] = new Exoskeleton("Roshan",level,30*level,35*level,11*level+20);
                        exo[1] = new Exoskeleton("Wolf",level,30*level,35*level,11*level+20);
                        spi[0] = new Spirit("Moradin",level,30*level,20*level,15*level+20);
                        spi[1] = new Spirit("Roykyn",level,30*level,20*level,15*level+20);
             }

	void Square::print_Statictics_Monsters()const{ // efanizei statistika gia ta terata

                        cout << "Dragon 1" << endl;
                        dra[0]->print();
                        cout << endl;
                        cout << "Dragon 2" << endl;
                        dra[1]->print();
                        cout << endl;
                        cout << "Exoskeleton 1" << endl;
                        exo[0]->print();
                        cout << endl;
                        cout << "Exoskeleton 2" << endl;
                        exo[1]->print();
                        cout << endl;
                        cout << "Spirit 1" << endl;
                        spi[0]->print();
                        cout << endl;
                        cout << "Spirit 2" << endl;
                        spi[1]->print();
                        cout << endl;
           }

