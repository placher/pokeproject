//Rhyhorn Pokemon

//Include things. Not complete
#ifndef RHYHORN_H
#define RHYHORN_H
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

class Rhyhorn: public Pokemon {
	public: 
		Rhyhorn();
		
	private:		
		int bhp;
		int batt;
		int bdef;
		int bsatt;
		int bsdef;
		int bspeed;
		int levelspeed;

};

Rhyhorn::Rhyhorn() {
	//There is a glitch associated with meduim slow pokemon at level 1. Additionally
	//there's some really odd xp values for lvl 1 pokemon including fast having 1 xp 
	//to lvl up.
	int level=50;
	levelspeed=4;//Slow Pokemon
	bhp = 80;
	batt = 85;
	bdef = 95;
	bsatt = 30;
	bsdef = 30;
	bspeed = 25;
	int m, hp, att, def, satt, sdef, speed;
	//This xp determining algorithm determines MAX xp, not levelup xp
	if(level > 1) {
		m = 5.0*pow(level, 3)/4;
	}
	else {
		m = 8;
	}
	hp = ((bhp*2)*(level)/100)+level+(rand()%10)+26;//Determine hp
	att = (((batt*2)*level)/100)+(rand()%5)+8;//Determine att
	def = (((bdef*2)*level)/100)+(rand()%5)+8;//Determine def
	satt = (((bsatt*2)*level)/100)+(rand()%5)+8;//Determine satt
	sdef = (((bsdef*2)*level)/100)+(rand()%5)+9;//Determine sdef
	speed = (((bspeed*2)*level)/100)+(rand()%5)+6;//Determine speed
	
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
	Pokemon::settype2("Rock");//Sets second type
	Pokemon::setMoves(19, 27, 31, 12);//Set up moves for pokemon
	Pokemon::setNum(35);

}

#endif
