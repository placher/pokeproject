//Bulbasaur Pokemon

//Include things. Not complete
#include <math.h>
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

class Bulbasaur: public Pokemon {
	public: 
		Bulbasaur();
		
	private:
		


};

Bulbasaur::Bulbasaur() {
	//Bulbasaur is a meduim slow pokemon
	//There is a glitch associated with meduim slow pokemon at level 1. Additionally
	//there's some really odd xp values for lvl 1 pokemon including fast having 1 xp to lvl up.
	int level=1;
	int m;
	if(level > 1) {
		m = (6/5*pow(level,3)) - 15*level*level + 100*level - 140
	}
	else {
		m = 5;
	}
	//Calculated with no IV with all decimals rounded down
	Pokemon::setmhealth(11);//Set max health
	Pokemon::setchealth(11);//Set curr health
	Pokemon::setlevel(1);//Set level
	Pokemon::setatt(5);//Set attack
	Pokemon::setdef(5);//Set defense
	Pokemon::setsatt(6);//Set special attack
	Pokemon::setsdef(6);//Set special defense
	Pokemon::setspeed(5);//Set speed
	Pokemon::setxp(0);//Set current xp(should default to 0)
	Pokemon::setmxp(m);//Set max xp for levelup


}