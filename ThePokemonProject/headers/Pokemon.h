/*
Pokemon.h

This .h file is the base file for pokemon, controling stats and damage in battles.
All other pokemon files inherit from this class.

Author: Douglas Schmieder
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <ctime>
#include <time.h>
#include <stdlib.h>
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
		void levelup(int);//The level up function for a pokemon
		void setMoves(int, int, int, int);//Set four moves for the pokemon
		void setNum(int);//Sets the number of the pokemon
		int getmhealth();//Get max health
		int getchealth();//Get curr health
		int getlevel();//Get level
		int getatt();//Get attack
		int getdef();//Get defense
		int getsatt();//Get special attack
		int getsdef();//Get special defense
		int getspeed();//Get speed
		int getxp();//Get current xp(should default to 0)
		int getmxp();//Get max xp for levelup
		string gettype1();//Sets the type1
		string gettype2();//Sets the type2
		Moves getMoves(int);//Set four moves for the pokemon
		int getNum();//Sets the number of the pokemon
		int doDamage(int);//Determines damage		
		void takeDamage(int, int);//Take damage		
		string getName();//Returns name

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
		int num;//Identify each pokemon
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

int Pokemon::getNum() {
	return num;
}

string Pokemon::getName() {
	return name;
}


/*
int Pokemon::doDamage(int n) {//Determines damage		
  int thispower = moves[n].getPower();
  //Run algorithm
  double damages = (double(2*(level+10))/double(250))*att*thispower;
  return int(damages);
}
*/

int Pokemon::doDamage(int n) {//Determines damage		
  int thispower = moves[n].getPower();
  int typing = moves[n].getTyping();
  double damages;
  //Run algorithm
  if (typing == 1){
    damages = (double(2*(level+10))/double(250))*att*thispower;
  }
  else {
    damages = (double(2*(level+10))/double(250))*satt*thispower; 
  }
  return int(damages);
}


void Pokemon::takeDamage(int damage, int typing) {//Take damage		
  double mod = 1;
  double damages;

  //n = (rand()&100)+1;

  if (typing == 1){
    damages = damage/def;
  }
  else {
    damages = damage/sdef;
  }

  //damages*=(mod);

  if (damages < 1) {
    damages = 1;
  }
/*
  if (n > acc) {
    damages = 0;
  }
*/

  currhealth = currhealth - int(damages);
  if (currhealth < 0) {
    currhealth = 0;
  }
}



/*
void Pokemon::takeDamage(int damage, int typing, string mtype, int acc) {//Take damage		
  double mod = 1;
  
  switch(mtype):
    case "Grass":
      //Super effective
      if (type1 == "Water" || type1 == "Rock" || type1 == "Ground") {
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Grass" || type1 == "Electric" ||
        type1 == "Ground" || type1 == "Water") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Water" || type2 == "Rock" || type2 == "Ground") {
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Grass" || type2 == "Electric" ||
        type2 == "Ground" || type2 == "Water") {
        mod=mod/2;
      }
      break;

    case "Normal":
      //Super effective
      
      //Not very effective
      if (type1 == "Rock") {
        mod=mod/2;
      }

      //Not very effective
      if (type2 == "Rock") {
        mod=mod/2;
      }
      break;

    case "Fighting":
      //Super effective
      if (type1 == "Normal" || type1 == "Ice" || type1 == "Dark" || 
        type1 == "Rock" || type1 == "Steel") {
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Poison" || type1 == "Flying" ||
        type1 == "Bug" || type1 == "Psychic") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Normal" || type2 == "Ice" || type2 == "Dark" ||
        type1 == "Rock" || type1 == "Steel") {
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Poison" || type2 == "Flying" ||
        type2 == "Bug" || type2 == "Psychic") {
        mod=mod/2;
      }
      break;

    case "Flying":
      //Super effective
      if (type1 == "Bug" || type1 == "Fighting" || type1 == "Grass") { 
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Electric" || type1 == "Rock" ||
        type1 == "Steel") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Bug" || type2 == "Fighting" || type2 == "Grass") { 
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Electric" || type2 == "Rock" ||
        type2 == "Steel") {
        mod=mod/2;
      }
      break;

    case "Poison":
      //Super effective
      if (type1 == "Bug" || type1 == "Grass") { 
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Poison" || type1 == "Rock" ||
        type1 == "Ground" || type1 == "Ghost") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Bug" || type2 == "Grass") { 
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Poison" || type2 == "Rock" ||
        type2 == "Ground" || type2 == "Ghost") {
        mod=mod/2;
      }
      break;

    case "Ground":
      //Super effective
      if (type1 == "Electric" || type1 == "Fire" || 
          type1 == "Poison" || type1 == "Rock") { 
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Bug" || type1 == "Grass") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Electric" || type2 == "Fire" || 
          type2 == "Poison" || type2 == "Rock") { 
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Bug" || type2 == "Grass") {
        mod=mod/2;
      }
      break;

    case "Rock":
      //Super effective
      if (type1 == "Bug" || type1 == "Fire" || 
          type1 == "Flying" || type1 == "Ice") { 
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Fighting" || type1 == "Ground") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Bug" || type2 == "Fire" || 
          type2 == "Flying" || type2 == "Ice") { 
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Fighting" || type2 == "Ground") {
        mod=mod/2;
      }
      break;

    case "Bug":
      //Super effective
      if (type1 == "Grass" || type1 == "Poison" || 
          type1 == "Psychic") { 
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Fighting" || type1 == "Fire" || 
          type1 == "Flying" || type1 == "Ghost") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Grass" || type2 == "Poison" || 
          type2 == "Psychic") { 
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Fighting" || type2 == "Fire" || 
          type2 == "Flying" || type2 == "Ghost") {
        mod=mod/2;
      }
      break;

    case "Ghost":
      //Super effective
      if (type1 == "Ghost" || type1 == "Psychic") { 
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Dark") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Ghost" || type2 == "Psychic") { 
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Dark") {
        mod=mod/2;
      }
      break;

    case "Fire":
      //Super effective
      if (type1 == "Grass" || type1 == "Bug" || 
          type1 == "Ice") { 
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Dragon" || type1 == "Fire" || 
          type1 == "Rock" || type1 == "Water") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Grass" || type2 == "Bug" || 
          type2 == "Ice") { 
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Dragon" || type2 == "Fire" || 
          type2 == "Rock" || type2 == "Water") {
        mod=mod/2;
      }
      break;

    case "Water":
      //Super effective
      if (type1 == "Fire" || type1 == "Ground" || 
          type1 == "Rock") { 
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Dragon" || type1 == "Grass" || 
          type1 == "Water") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Fire" || type2 == "Ground" || 
          type2 == "Rock") { 
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Dragon" || type2 == "Grass" || 
          type2 == "Water") {
        mod=mod/2;
      }
      break;

    case "Electric":
      //Super effective
      if (type1 == "Flying" || type1 == "Water") { 
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Dragon" || type1 == "Grass" || 
          type1 == "Electric") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Flying" || type2 == "Water") { 
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Dragon" || type2 == "Grass" || 
          type2 == "Electric") {
        mod=mod/2;
      }
      break;

    case "Psychic":
      //Super effective
      if (type1 == "Fighting" || type1 == "Poison") { 
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Psychic") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Fighting" || type2 == "Poison") { 
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Psychic") {
        mod=mod/2;
      }
      break;

    case "Ice":
      //Super effective
      if (type1 == "Dragon" || type1 == "Flying" ||
          type1 == "Grass" || type1 == "Ground") { 
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Ice" || type1 == "Fire" || 
          type1 == "Water") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Dragon" || type2 == "Flying" ||
          type2 == "Grass" || type2 == "Ground") { 
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Ice" || type2 == "Fire" || 
          type2 == "Water") {
        mod=mod/2;
      }
      break;

    case "Dragon":
      //Super effective
      if (type1 == "Dragon") { 
        mod = mod*2;
      }
      //Not very effective
      
      //Super effective
      if (type2 == "Dragon") { 
        mod = mod*2;
      }
      //Not very effective
  
      break;

    case "Dark":
      //Super effective
      if (type1 == "Ghost" || type1 == "Psychic") { 
        mod = mod*2;
      }
      //Not very effective
      if (type1 == "Dark" || type1 == "Fighting") {
        mod=mod/2;
      }
      //Super effective
      if (type2 == "Ghost" || type2 == "Psychic") { 
        mod = mod*2;
      }
      //Not very effective
      if (type2 == "Dark" || type2 == "Fighting") {
        mod=mod/2;
      }
      break;
    default:
      break;
  }

  n = (rand()&100)+1;

  if (typing == 1){
    double damages = damage/def;
  }
  else {
    double damages = damage/sdef;
  }

  damages*=(mod);

  if (damages < 1) {
    damages = 1;
  }

  if (n > acc) {
    damages = 0;
  }
  currhealth = currhealth - int(damages);
  if (currhealth < 0) {
    currhealth = 0;
  }
}*/


#endif
