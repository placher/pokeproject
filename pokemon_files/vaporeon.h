//Vaporeon Pokemon

#ifndef VAPOREON_H
#define VAPOREON_H

//Include things. Not complete
#ifndef VAPOREON_H
#define VAPOREON_H
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

class Vaporeon: public Pokemon {
	public: 
		Vaporeon();
		
	private:		
		int bhp;
		int batt;
		int bdef;
		int bsatt;
		int bsdef
		int bspeed;
		int levelspeed;

};

Vaporeon::Vaporeon() {
	//There is a glitch associated with meduim slow pokemon at level 1. Additionally
	//there's some really odd xp values for lvl 1 pokemon including fast having 1 xp 
	//to lvl up.
	int level=50;
	levelspeed=2;//Medium fast Pokemon
	bhp = 130;
	batt = 65;
	bdef = 60;
	bsatt = 110;
	bsdef = 95;
	bspeed = 65;
	int m, hp, att, def, satt, sdef, speed;
	//This xp determining algorithm determines MAX xp, not levelup xp
	if(level > 1) {
		m = pow(level, 3)
	}
	else {
		m = 4;
	}
	hp = ((bhp*2)*(level)/100)+level+(rand()%6)+26;//Determine hp
	att = (((batt*2)*level)/100)+(rand()%3)+6;//Determine att
	def = (((bdef*2)*level)/100)+(rand()%3)+6;//Determine def
	satt = (((bsatt*2)*level)/100)+(rand()%3)+11;//Determine satt
	sdef = (((bsdef*2)*level)/100)+(rand()%3)+9;//Determine sdef
	speed = (((bspeed*2)*level)/100)+(rand()%3)+6;//Determine speed
	
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
	Pokemon::settype1("Water");//Sets first type
	Pokemon::settype2("");//Sets second type
	Pokemon::setMoves(19, 20, 5, 14);//Set up moves for pokemon
	Pokemon::setNum(38);

}

#endif