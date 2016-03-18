//Include things. Not complete

#include "Moves.h"

using namespace std;


/*
HP = [(((Base+IV)x2+(root(EV)/4))xLevel)/100]+level+10
Others = [((base+IV)x2+[root(EV)/4]xLevel)/100]+5
IV range from 0-31. Generate average IV and give to every pokemon?
Ignore EVs?
*/

class Pokemon{
	public:
		Pokemon();//Default constructor
		//Get functions for all stats
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
		
		
		
	private:
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
};

Pokemon::Pokemon() {
	//Does a thing
	
	
}

void Pokemon::setmhealth(int n) {
	maxhealth = n;
}
		