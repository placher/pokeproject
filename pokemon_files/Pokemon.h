//Include things. Not complete

#include <ctime>
#include <string>
#include <iostream>
#include "Moves.h"

using namespace std;


/*
HP = [(((Base+IV)x2+(root(EV)/4))xLevel)/100]+level+10
Others = [((base+IV)x2+[root(EV)/4]xLevel)/100]+5
IV range from 0-31. Generate average IV and give to every pokemon?
Ignore EVs?
Level up is 1/50 the base stat value. How do we do that?
*/

class Pokemon{
	public:
		Pokemon();//Default constructor
		//Get functions for all stats?
		void setmhealth(int);//Set max health
		void setchealth(int);//Set curr health
		void setlevel(int);//Set level
		void setatt(int);//Set attack
		void setdef(int);//Set defense
		void setsatt(int);//Set special attack
		void setsdef(int);//Set special defense
		void setspeed(int);//Set speed
		void setxp(int);//Set current xp(should default to 0)
		void setmxp(int);//Set max xp for levelup
		void settype1(string);//Sets the type1
		void settype2(string);//Sets the type2
		void levelup();//The level up function for a pokemon
		
		
		
	private:
		/*
		int bhealth;//Base Health
		int batt;//Base Attack
		int bdef;//Base Defense
		int bsatt;//Base Special Attack
		int bsdef;//Base Special Defense
		int bspeed;//Base Speed*///Was trying to set up a personal levelup
		//Current levelup is simple random number generator for reasonable stat increase
		int maxhealth;
		int currhealth;
		int level;
		int att;//Attack stat
		int def;//Defense stat
		int satt;//Special Attack Stat
		int sdef;//Special Defense Stat
		int speed;//Speed stat
		int xp;//Current xp
		int maxxp;//Max xp
		string type1;//First type
		string type2;//Second type/Set to Null if there is no second type
		string name;//Name of the pokemon
};

Pokemon::Pokemon() {
	//Does a thing
	srand(time(NULL));	
}

void Pokemon::setmhealth(int n) {
	maxhealth = n;
}

void Pokemon::setchealth(int n) {
	currhealth = n;
}

void Pokemon::setlevel(int n) {
	level = n;
}

void Pokemon::setatt(int n) {
	att = n;
}

void Pokemon::setdef(int n) {
	def = n;
}

void Pokemon::setsatt(int n) {
	satt = n;
}

void Pokemon::setsdef(int n) {
	sdef = n;
}

void Pokemon::setspeed(int n) {
	speed = n;
}		

void Pokemon::setxp(int n) {
	xp = n;
}

void Pokemon::setmxp(int n) {
	maxxp = n;
}

void Pokemon::settype1(string n) {
	type1 = n;//Don't think these are right
}

void Pokemon::settype2(string n) {
	type2 = n;//Don't think these are right
}

void Pokemon::levelup(int levelspeed) {
	//With current algorithm, do not reset maxxp or curr xp
	level++;
	int chp, catt, cdef, csatt, csdef, cspeed;//Change stats
	chp = (rand()%4)+2;
	catt = (rand()%3)+1;
	cdef = (rand()%3)+1;
	csatt = (rand()%3)+1;
	csdef = (rand()%3)+1;
	cspeed = (rand()%3)+1;
	maxhealth+=chp;
	currhealth+=chp;
	att+=catt;
	def+=cdef;
	satt+=csatt;
	sdef+=csdef;
	speed+=cspeed;
	/*Don't know if this is going to work
	if (levelspeed == 1) {//Signifies a Fast pokemon
		maxxp = 6/5*pow(level,3)) - 15*level*level + 100*level - 140;
	}
	if (levelspeed == 2) {//Signifies a Medium Fast pokemon
		maxxp = 6/5*pow(level,3)) - 15*level*level + 100*level - 140;
	}
	if (levelspeed == 3) {//Signifies a Medium Slow pokemon
		maxxp = 6/5*pow(level,3)) - 15*level*level + 100*level - 140;
	}
	if (levelspeed == 4) {//Signifies a Slow pokemon
		maxxp = 6/5*pow(level,3)) - 15*level*level + 100*level - 140;
	}*/
		
}		
