//Dugtrio Pokemon

//Include things. Not complete
#ifndef DUGRIO_H
#define DUGRIO_H
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

http://bulbapedia.bulbagarden.net/wiki/Experience
Four exp groups in Gen I:Fast, Medium Fast, Medium Slow, Slow
Fast = 4n^3/5
Meduim Fast = n^3
Medium Slow = 6/5n^3 - 15n^2 + 100n - 140
Slow = 5n^3/4
*/

class Dugtrio: public Pokemon {
	public: 
		Dugtrio();
		
	private:		
		int bhp;
		int batt;
		int bdef;
		int bsatt;
		int bsdef;
		int bspeed;
		int levelspeed;

};

Dugtrio::Dugtrio() {
	//There is a glitch associated with meduim slow pokemon at level 1. Additionally
	//there's some really odd xp values for lvl 1 pokemon including fast having 1 xp 
	//to lvl up.
	int level=52;
	levelspeed=2;//Medium fast Pokemon
  //Makes base stats
	bhp = 35;
	batt = 80;
	bdef = 50;
	bsatt = 50;
	bsdef = 70;
	bspeed = 120;
	int m, hp, att, def, satt, sdef, speed;
	//This xp determining algorithm determines MAX xp, not levelup xp
	if(level > 1) {
		m = pow(level, 3);
	}
	else {
		m = 4;
	}
	hp = ((bhp*2)*(level)/100)+level+(rand()%8)+7;//Determine hp
	att = (((batt*2)*level)/100)+(rand()%4)+8;//Determine att
	def = (((bdef*2)*level)/100)+(rand()%4)+5;//Determine def
	satt = (((bsatt*2)*level)/100)+(rand()%4)+5;//Determine satt
	sdef = (((bsdef*2)*level)/100)+(rand()%4)+7;//Determine sdef
	speed = (((bspeed*2)*level)/100)+(rand()%4)+12;//Determine speed
	
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
	Pokemon::settype1("Ground");//Sets first type
	Pokemon::settype2("");//Sets second type
	Pokemon::setMoves(22,23,26,3);//Sets moves
	Pokemon::setNum(12);//Twelth Pokemon

}

#endif
