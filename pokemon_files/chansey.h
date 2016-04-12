//Chansey Pokemon

//Include things. Not complete
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

class Chansey: public Pokemon {
	public: 
		Chansey();
		
	private:		
		int bhp;
		int batt;
		int bdef;
		int bsatt;
		int bsdef
		int bspeed;
		int levelspeed;

};

Chansey::Chansey() {
	//There is a glitch associated with meduim slow pokemon at level 1. Additionally
	//there's some really odd xp values for lvl 1 pokemon including fast having 1 xp 
	//to lvl up.
	int level=1;
	levelspeed=1;//Fast Pokemon
	bhp = 250;
	batt = 5;
	bdef = 5;
	bsatt = 35;
	bsdef = 105;
	bspeed = 50;
	int m, hp, att, def, satt, sdef, speed;
	//This xp determining algorithm determines MAX xp, not levelup xp
	if(level > 1) {
		m = 4.0*pow(level, 3)/5.0;
	}
	else {
		m = 2;
	}
	hp = ((bhp*2)*(level)/100)+level+(rand()%10)+50;//Determine hp
	att = (((batt*2)*level)/100)+(rand()%5)+1;//Determine att
	def = (((bdef*2)*level)/100)+(rand()%5)+1;//Determine def
	satt = (((bsatt*2)*level)/100)+(rand()%5)+3;//Determine satt
	sdef = (((bsdef*2)*level)/100)+(rand()%5)+10;//Determine sdef
	speed = (((bspeed*2)*level)/100)+(rand()%5)+5;//Determine speed
	
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
	Pokemon::settype1("Normal");//Sets first type
	Pokemon::settype2("");//Sets second type

}

