//Include things. Not complete

#ifndef POKEMON_H
#define POKEMON_H

#include <ctime>
#include <string>
#include <iostream>
#include <vector>
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
		void setMoves(int, int, int, int);//Set four moves for the pokemon
		void setNum(int);//Sets the number of the pokemon
		int getmhealth();//Set max health
		int getchealth();//Set curr health
		int getlevel();//Set level
		int getatt();//Set attack
		int getdef();//Set defense
		int getsatt();//Set special attack
		int getsdef();//Set special defense
		int getspeed();//Set speed
		int getxp();//Set current xp(should default to 0)
		int getmxp();//Set max xp for levelup
		string gettype1();//Sets the type1
		string gettype2();//Sets the type2
		//Moves getMoves(int);//Set four moves for the pokemon
		int getNum();//Sets the number of the pokemon
		
		
		
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
		int num;;//Identify each pokemon
		string type1;//First type
		string type2;//Second type/Set to Null if there is no second type
		string name;//Name of the pokemon
		vector <Moves> moves;
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

void Pokemon::setMoves(int mv1, int mv2, int mv3, int mv4) {

	Moves move1(mv1), move2(mv2), move3(mv3), move4(mv4); // assign moves based on enum values

	moves.push_back(move1); // push moves into myMoves
	moves.push_back(move2);
	moves.push_back(move3);
	moves.push_back(move4); // last usable move slot
}

void Pokemon::setNum(int number) {
	num = number;
}

int Pokemon::getmhealth() {
	return maxhealth;
}

int Pokemon::getchealth() {
	return currhealth;
}

int Pokemon::getlevel() {
	return level;
}

int Pokemon::getatt() {
	return att;
}

int Pokemon::getdef() {
	return def;
}

int Pokemon::getsatt() {
	return satt;
}

int Pokemon::getsdef() {
	return sdef;
}

int Pokemon::getspeed() {
	return speed;
}

int Pokemon::getxp() {
	return xp;
}

int Pokemon::getmxp() {
	return maxxp;
}

string Pokemon::gettype1() {
	return type1;
}

string Pokemon::gettype2() {
	return type2;
}

Moves Pokemon::getMoves(int n) {
	return moves[n];
}

int Pokemon::getnum() {
	return num;
}


#endif
