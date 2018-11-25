//File: Living.h
#ifndef LIVING_H
#define LIVING_H
#include <iostream>
#include <cstring>

using namespace std;


class Living {
        private:
                string name;
                int level;
                int healthPower;
        public:
		Living(string name,int l = 1){
			this->name = name;
			level = l;
			healthPower = 2000;
		}
		~Living(){   }

		void set_level(){ level++; }
		void set_healthPower(int k){ healthPower += k; }
		void set_health_h(){ healthPower = 1000; }

		int get_level()const { return level; }
		int get_healthPower()const { return healthPower; }
		string get_name()const { return name; }

		void print()const {
			cout << "Level is " << level << endl;
			if(healthPower >= 0) cout << "HealthPower is " << healthPower << endl;
			else cout << "HealthPower is 0" << endl;
		}
};
#endif
