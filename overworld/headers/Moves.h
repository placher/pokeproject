//Create an initial Moves.h file

#ifndef MOVES_H
#define MOVES_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;


enum moveList{
	SLAM,          //0
	BODY_SLAM,     //1
	THUNDERBOLT,   //2
	ROCK_SMASH,    //3
	THUNDER,       //4
	ICE_BEAM,      //5
	FIRE_BLAST,    //6
	FLAMETHROWER,  //7
	FIRE_PUNCH,    //8 
	THUNDER_PUNCH, //9
	ICE_PUNCH,     //10
	TRI_ATTACK,    //11
	DRILL_PECK,    //12
	AERIAL_ACE,    //13
	HEADBUTT,      //14
	PSYCHIC,       //15
	CONFUSION,     //16
	RAZOR_LEAF,    //17
	VINE_WHIP,     //18
	WATER_GUN,     //19
	SURF,          //20
	WATERFALL,     //21
	SLASH,         //22
	EARTHQUAKE,    //23
	DRAGON_CLAW,   //24
	SHADOW_BALL,   //25
	ROCK_SLIDE,    //26
	WING_ATTACK,   //27
	SLUDGE_BOMB,   //28
	CRUNCH,        //29
	GUST,          //30
	BUG_BUZZ       //31
	
};

class Moves{
	public:
		Moves(int);
		int getmovenum();
		void setmovenum(int);
		int noMove();
    int getPower();
    int getTyping();//Returns typing
    int getAcc();//Returns accuracy
    string getType();//Returns type
    string getName();//Returns name

	private:
		int myMove;//Number of the move
		int power;//Power of the move
		int acc;//Accuracy
		string type;//Type
		string moveName;//Name
		int movenum;//Number of the move
		int typing;//1 is physical, 2 is special
};

Moves::Moves(int myMove) {
	switch (myMove) {
		case SLAM: //0
			moveName.assign("Slam");
			power = 80;
			acc = 75;
			setmovenum(0);
			type.assign("Normal"); //type of attack
			typing = 1;
			break;
		case BODY_SLAM: //1
			moveName.assign("Body Slam");
			power = 85;
			acc = 100;
			setmovenum(1);
			type.assign("Normal"); //type of attack
			typing = 1;
			break;
		case THUNDERBOLT: //2
			moveName.assign("Thunderbolt");
			power = 90;
			acc = 100;
			setmovenum(2);
			type.assign("Electric"); //type of attack
			typing = 2;
			break;
		case ROCK_SMASH: //3
			moveName.assign("Rock Smash");
			power = 40;
			acc = 100;
			setmovenum(3);
			type.assign("Fighting"); //type of attack
			typing = 1;
			break;
		case THUNDER: //4
			moveName.assign("Thunder");
			power = 110;
			acc = 70;
			setmovenum(4);
			type.assign("Electric"); //type of attack
			typing = 2;
			break;
		case ICE_BEAM: //5
			moveName.assign("Ice Beam");
			power = 90;
			acc = 100;
			setmovenum(5);
			type.assign("Ice"); //type of attack
			typing = 2;
			break;
		case FIRE_BLAST: //6
			moveName.assign("Fire Blast");
			power = 110;
			acc = 85;
			setmovenum(6);
			type.assign("Fire"); //type of attack
			typing = 2;
			break;
		case FLAMETHROWER: //7
			moveName.assign("Flamethrower");
			power = 90;
			acc = 100;
			setmovenum(7);
			type.assign("Fire"); //type of attack
			typing = 2;
			break;
		case FIRE_PUNCH: //8
			moveName.assign("Fire Punch");
			power = 75;
			acc = 100;
			setmovenum(8);
			type.assign("Fire"); //type of attack
			typing = 1;
			break;
		case THUNDER_PUNCH: //9
			moveName.assign("Thunder Punch");
			power = 75;
			acc = 100;
			setmovenum(9);
			type.assign("Electric"); //type of attack
			typing = 1;
			break;
		case ICE_PUNCH: //10
			moveName.assign("Ice Punch");
			power = 75;
			acc = 100;
			setmovenum(10);
			type.assign("Ice"); //type of attack
			typing = 1;
			break;
		case TRI_ATTACK: //11 CONTINUE FROM THIS POINT
			moveName.assign("Tri Attack");
			power = 80;
			acc = 100;
			setmovenum(11);
			type.assign("Normal"); //type of attack
			typing = 2;
			break;
		case DRILL_PECK: //12
			moveName.assign("Drill Peck");
			power = 80;
			acc = 100;
			setmovenum(12);
			type.assign("Flying"); //type of attack
			typing = 1;
			break;
		case AERIAL_ACE: //13
			moveName.assign("Aerial Ace");
			power = 60;
			acc = 100;
			setmovenum(13);
			type.assign("Flying"); //type of attack
			typing = 1;
			break;
		case HEADBUTT: //14
			moveName.assign("Headbutt");
			power = 70;
			acc = 100;
			setmovenum(14);
			type.assign("Normal"); //type of attack
			typing = 1;
			break;
		case PSYCHIC: //15
			moveName.assign("Psychic");
			power = 90;
			acc = 100;
			setmovenum(15);
			type.assign("Psychic"); //type of attack
			typing = 2;
			break;
		case CONFUSION: //16
			moveName.assign("Confusion");
			power = 50;
			acc = 100;
			setmovenum(16);
			type.assign("Psychic"); //type of attack
			typing = 2;
			break;
		case RAZOR_LEAF: //17
			moveName.assign("Razer Leaf");
			power = 55;
			acc = 95;
			setmovenum(17);
			type.assign("Grass"); //type of attack
			typing = 1;
			break;
		case VINE_WHIP: //18
			moveName.assign("Vine Whip");
			power = 45;
			acc = 100;
			setmovenum(18);
			type.assign("Grass"); //type of attack
			typing = 1;
			break;
		case WATER_GUN: //19
			moveName.assign("Water Gun");
			power = 40;
			acc = 100;
			setmovenum(19);
			type.assign("Water"); //type of attack
			typing = 2;
			break;
		case SURF: //20
			moveName.assign("Surf");
			power = 90;
			acc = 100;
			setmovenum(20);
			type.assign("Water"); //type of attack
			typing = 2;
			break;
		case WATERFALL: //21
			moveName.assign("Waterfall");
			power = 80;
			acc = 100;
			setmovenum(21);
			type.assign("Water"); //type of attack
			typing = 1;
			break;
		case SLASH: //22
			moveName.assign("Slash");
			power = 70;
			acc = 100;
			setmovenum(22);
			type.assign("Normal"); //type of attack
			typing = 1;
			break;
		case EARTHQUAKE: //23
			moveName.assign("Earthquake");
			power = 100;
			acc = 100;
			setmovenum(23);
			type.assign("Ground"); //type of attack
			typing = 1;
			break;
		case DRAGON_CLAW: //24
			moveName.assign("Dragon Claw");
			power = 80;
			acc = 100;
			setmovenum(24);
			type.assign("Dragon"); //type of attack
			typing = 1;
			break;
		case SHADOW_BALL: //25
			moveName.assign("Shadow Ball");
			power = 80;
			acc = 100;
			setmovenum(25);
			type.assign("Ghost"); //type of attack
			typing = 2;
			break;
		case ROCK_SLIDE: //26
			moveName.assign("Rock Slide");
			power = 75;
			acc = 90;
			setmovenum(26);
			type.assign("Rock"); //type of attack
			typing = 1;
			break;
		case WING_ATTACK: //27
			moveName.assign("Wing Attack");
			power = 60;
			acc = 100;
			setmovenum(27);
			type.assign("Flying"); //type of attack
			typing = 1;
			break;
		case SLUDGE_BOMB: //28
			moveName.assign("Sludge Bomb");
			power = 90;
			acc = 100;
			setmovenum(28);
			type.assign("Poison"); //type of attack
			typing = 2;
			break;
		case CRUNCH: //29
			moveName.assign("Crunch");
			power = 80;
			acc = 100;
			setmovenum(29);
			type.assign("Dark"); //type of attack
			typing = 1;
			break;
		case GUST: //30
			moveName.assign("Gust");
			power = 40;
			acc = 100;
			setmovenum(30);
			type.assign("Flying"); //type of attack
			typing = 2;
			break;
		case BUG_BUZZ: //31
			moveName.assign("Bug Buzz");
			power = 70;
			acc = 75;
			setmovenum(31);
			type.assign("Bug"); //type of attack
			typing = 2;
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

/*
int Moves::attack(){
  power=power*2 + lever
  return power;
}*/

int Moves::getPower() {
  return power;
}


    int getTyping();//Returns typing
    int getAcc();//Returns accuracy
    string getType();//Returns type
    string getName();//Returns name

int Moves::getTyping() {
  return typing;
}

int Moves::getAcc() {
  return acc;
}

string Moves::getType() {
  return type;
}

string Moves::getName() {
  return moveName;
}



#endif
