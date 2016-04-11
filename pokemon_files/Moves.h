//Create an initial Moves.h file

#ifndef MOVES_H
#define MOVES_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;


enum moveList{
	TACKLE,        //0
	BODY_SLAM,
	THUNDERBOLT,
	THUNDERSHOCK,
	THUNDER,
	ICE_BEAM,
	FIRE_BLAST,
	FLAMETHROWER,
	FIRE_PUNCH,
	THUNDER_PUNCH,
	ICE_PUNCH,
	TRI_ATTACK,
	DRILL_PECK,
	PECK,
	HEADBUTT,
	PSYCHIC,
	CONFUSION,
	RAZOR_LEAF,
	VINE_WHIP,
	WATER_GUN,
	SURF,
	WATERFALL,
	SLASH,
	EARTHQUAKE,
	DRAGON_BREATH,
	
	
};

class Moves{
	public:
		Moves(int);
		int getmovenum();
		void setmovenum(int);
		int attack(int);
		void levelUp();
		int noMove();
		
	private:
		int myMove;//Number of the move
		int power;//Power of the move
		int acc;//Accuracy
		string type;//Type
		string moveName;//Name
		int movenum;//Number of the move
};

Moves::Moves(int myMove) { //using a int sets base stats for a move
	switch (myMove) {
		case TACKLE: //0
			moveName.assign("tackle");
			power = 35;
			setmovenum(0);
			type.assign("Normal"); //type of attack
			break;

		default:
			noMove();
			break;
	}
}

int Moves::getmovenum() {
	return movenum;
}

void Moves::setmovenum(int m) {
	movenum = m;
}

int Moves::noMove(){};

#endif