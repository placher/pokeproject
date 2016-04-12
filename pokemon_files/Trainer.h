// Makes the trainer stuff for the class things

#ifndef Trainer_H
#define Trainer_H
#include <vector>
#include <string>
#include "Pokemon.h"

using namespace std;

class Trainer {
	public:
		Trainer(int); // constructor
	
	private:
		string tname;//Name of the trainer
		vector <Pokemon*> pokemon; //Pokemon team

};

Trainer::Trainer(int trainer){
	switch(trainer) {
		case 1: //This is the player
			tname = "Red"
			Pokemon *poke1 = new Charizard;
			Pokemon *poke2 = new Alakazam;
			Pokemon *poke3 = new Electabuzz;
			Pokemon *poke4 = new Golem;
			Pokemon *poke5 = new Arbok;
			Pokemon *poke6 = new Dodrio;
			
			pokemon.push_back(poke1);
			pokemon.push_back(poke2);
			pokemon.push_back(poke3);
			pokemon.push_back(poke4);
			pokemon.push_back(poke5);
			pokemon.push_back(poke6);
			break;
		case 2: //This is the player
			tname = "Blue"
			Pokemon *poke1 = new Blastoise;
			Pokemon *poke2 = new Golbat;
			Pokemon *poke3 = new Electabuzz;
			Pokemon *poke4 = new Marowak;
			Pokemon *poke5 = new Alakazam;
			Pokemon *poke6 = new Dodrio;
			
			pokemon.push_back(poke1);
			pokemon.push_back(poke2);
			pokemon.push_back(poke3);
			pokemon.push_back(poke4);
			pokemon.push_back(poke5);
			pokemon.push_back(poke6);
			break;
		case 3: //This is the player
			tname = "Green"
			Pokemon *poke1 = new Venusaur;
			Pokemon *poke2 = new Butterfree;
			Pokemon *poke3 = new Fearow;
			Pokemon *poke4 = new Kingler;
			Pokemon *poke5 = new Alakazam;
			Pokemon *poke6 = new Golduck;
			
			pokemon.push_back(poke1);
			pokemon.push_back(poke2);
			pokemon.push_back(poke3);
			pokemon.push_back(poke4);
			pokemon.push_back(poke5);
			pokemon.push_back(poke6);
			break;			
		case 4: //This is Doug(aerodactyl, dugtrio, hitmonchan, ninetales, raichu, vaporeon)
			tname = "Douglas"
			Pokemon *poke1 = new Aerodactyl;
			Pokemon *poke2 = new Dugtrio;
			Pokemon *poke3 = new Hitmonchan;
			Pokemon *poke4 = new Ninetales;
			Pokemon *poke5 = new Raichu;
			Pokemon *poke6 = new Vaporeon;
			
			pokemon.push_back(poke1);
			pokemon.push_back(poke2);
			pokemon.push_back(poke3);
			pokemon.push_back(poke4);
			pokemon.push_back(poke5);
			pokemon.push_back(poke6);
			break;
			
		case 5: //This is John
			tname = "John"
			Pokemon *poke1 = new Electrode;
			Pokemon *poke2 = new Jigglypuff;
			Pokemon *poke3 = new Lapras;
			Pokemon *poke4 = new Onix;
			Pokemon *poke5 = new Pikachu;
			Pokemon *poke6 = new Shuckle;
			
			pokemon.push_back(poke1);
			pokemon.push_back(poke2);
			pokemon.push_back(poke3);
			pokemon.push_back(poke4);
			pokemon.push_back(poke5);
			pokemon.push_back(poke6);
			break;
		
		case 6: //This is Pat
			tname = "Patrick"
			Pokemon *poke1 = new Chansey;
			Pokemon *poke2 = new Dragonite;
			Pokemon *poke3 = new Gengar;
			Pokemon *poke4 = new Lapras;
			Pokemon *poke5 = new Pidgeot;
			Pokemon *poke6 = new Rhydon;
			
			pokemon.push_back(poke1);
			pokemon.push_back(poke2);
			pokemon.push_back(poke3);
			pokemon.push_back(poke4);
			pokemon.push_back(poke5);
			pokemon.push_back(poke6);
			break;
	}
}

#endif