//Shuckle Pokemon

//Include things. Not complete
#ifndef SHUCKLE_H
#define SHUCKLE_H
#include <cmath>
#include <string>
#include "Moves.h"
#include "Pokemon.h"


using namespace std;

/*
http://bulbapedia.bulbagarden.net/wiki/Statistic
Gen I and II formula:
HP = [(((Base+IV)x2+(root(EV)/4))xLevel)/100]+level+10
Others = [((base+IV)x2+[root(EV)/4]xLevel)/100]+5
IV range from 0-31. Generate average IV and give to every pokemon?
Ignore EVs?

http://bulbapedia.bulbagarden.net/wiki/Experience
Four exp groups in Gen I:Fast, Medium Fast, Medium Slow, Slow
Fast = 4n^3/5
Meduim Fast = n^3
Medium Slow = 6/5n^3 - 15n^2 + 100n - 140
Slow = 5n^3/4
*/

class Shuckle: public Pokemon {
	public: 
		Shuckle();
		
	private:		
		int bhp;
		int batt;
		int bdef;
		int bsatt;
		int bsdef;
		int bspeed;
		int levelspeed;

};

Shuckle::Shuckle() {
	//There is a glitch associated with meduim slow pokemon at level 1. Additionally
	//there's some really odd xp values for lvl 1 pokemon including fast having 1 xp 
	//to lvl up.
	int level=50;
	levelspeed=3;//Medium slow Pokemon
	bhp = 20;
	batt = 10;
	bdef = 230;
	bsatt = 10;
	bsdef = 230;
	bspeed = 5;
	int m, hp, att, def, satt, sdef, speed;
	//This xp determining algorithm determines MAX xp, not levelup xp
	if(level > 1) {
		m = (6.0/5.0*pow(level,3)) - 15.0*level*level + 100*level - 140;
	}
	else {
		m = 6;
	}
	hp = ((bhp*2)*(level)/100)+level+(rand()%10)+4;//Determine hp
	att = (((batt*2)*level)/100)+(rand()%5)+1;//Determine att
	def = (((bdef*2)*level)/100)+(rand()%5)+23;//Determine def
	satt = (((bsatt*2)*level)/100)+(rand()%5)+1;//Determine satt
	sdef = (((bsdef*2)*level)/100)+(rand()%5)+23;//Determine sdef
	speed = (((bspeed*2)*level)/100)+(rand()%5)+1;//Determine speed
	
	//Calculated with no IV with all decimals rounded down
	Pokemon::setmhealth(hp);//Set max health
	Pokemon::setchealth(hp);//Set curr health
	Pokemon::setlevel(level);//Set level
	Pokemon::setatt(att);//Set attack
	Pokemon::setdef(def);//Set defense
	Pokemon::setsatt(satt);//Set special attack
	Pokemon::setsdef(sdef);//Set special defense
	Pokemon::setspeed(speed);//Set speed
	Pokemon::setxp(0);//Set current xp(should default to 0)
	Pokemon::setmxp(m);//Set max xp for levelup
	Pokemon::settype1("Bug");//Sets first type
	Pokemon::settype2("Rock");//Sets second type
	Pokemon::setMoves(10, 21, 24, 16);//Set up moves for pokemon
	Pokemon::setNum(36);

}

#endif