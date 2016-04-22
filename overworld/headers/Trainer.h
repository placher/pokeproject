// Makes the trainer stuff for the class things

#ifndef TRAINER_H
#define TRAINER_H
#include <vector>
#include <string>
#include <iostream>

#include "Pokemon.h"
#include "aerodactyl.h"
#include "alakazam.h"
#include "arbok.h"
#include "arcanine.h"
#include "blastoise.h"
#include "bulbasaur.h"
#include "butterfree.h"
#include "chansey.h"
#include "charizard.h"
#include "dodrio.h"
#include "dragonite.h"
#include "dugtrio.h"
#include "electabuzz.h"
#include "electrode.h"
#include "fearow.h"
#include "gengar.h"
#include "golbat.h"
#include "golduck.h"
#include "golem.h"
#include "graveler.h"
#include "gyrados.h"
#include "hitmonchan.h"
#include "jigglypuff.h"
#include "kadabra.h"
#include "kingler.h"
#include "lapras.h"
#include "magmar.h"
#include "marowak.h"
#include "ninetales.h"
#include "onix.h"
#include "pidgeot.h"
#include "pikachu.h"
#include "raichu.h"
#include "rhydon.h"
#include "rhyhorn.h"
#include "shuckle.h"
#include "snorlax.h"
#include "vaporeon.h"
#include "venusaur.h"

using namespace std;

class Trainer {
  public:
    Trainer(int); // constructor
    Pokemon* getPokemon(int);//returns the pokemon

  private:
    string tname;//Name of the trainer
    vector <Pokemon*> pokemon; //Pokemon team

};

Trainer::Trainer(int trainer){
  Pokemon *poke1;
  Pokemon *poke2;
  Pokemon *poke3;
  Pokemon *poke4;
  Pokemon *poke5;
  Pokemon *poke6;




  switch(trainer) {
    case 1: //This is the player
      {
        int n, m, o, p, q, r;

        cout << "Please type the number corresponding to the pokemon you want." << endl;
        cout << "Venusaur(1), Charizard(2), Blastoise(3)" << endl;
        cin >> n;
        cout << "Butterfree(1), Golbat(2), Dodrio(3)" << endl;
        cin >> m;
        cout << "Golduck(1), Alakazam(2), Electabuzz(3)" << endl;
        cin >> o;
        cout << "Golem(1), Marowak(2), Arbok(3)" << endl;
        cin >> p;
        cout << "Fearow(1), Gyrados(2), Kingler(3)" << endl;
        cin >> q;
        cout << "Arcanine(1), Snorlax(2), Magmar(3)" << endl;
        cin >> r;

        if (n == 1)
          poke1 = new Venusaur;
        else if (n == 2)
          poke1 = new Charizard;
        else 
          poke1 = new Blastoise;

        if (m == 1)
          poke2 = new Butterfree;
        else if (m == 2)
          poke2 = new Golbat;
        else
          poke2 = new Dodrio;

        if (o == 1)
          poke3 = new Golduck;
        else if (o == 2)
          poke3 = new Alakazam;
        else
          poke3 = new Electabuzz;

        if (p == 1)
          poke4 = new Golem;
        else if (p == 2)
          poke4 = new Marowak;
        else
          poke4 = new Arbok;

        if (q == 1)
          poke5 = new Fearow;
        else if (q == 2)
          poke5 = new Gyrados;
        else
          poke5 = new Kingler;

        if (r == 1)
          poke6 = new Arcanine;
        else if (r == 2)
          poke6 = new Snorlax;
        else
          poke6 = new Magmar;




        /*
        tname = "Red";
        poke1 = new Charizard;
        poke2 = new Alakazam;
        poke3 = new Electabuzz;
        poke4 = new Golem;
        poke5 = new Arbok;
        poke6 = new Dodrio;
        */

        pokemon.push_back(poke1);
        pokemon.push_back(poke2);
        pokemon.push_back(poke3);
        pokemon.push_back(poke4);
        pokemon.push_back(poke5);
        pokemon.push_back(poke6);
        break;
      }

    case 2: //This is the player
      {
        tname = "Blue";
        poke1 = new Blastoise;
        poke2 = new Golbat;
        poke3 = new Electabuzz;
        poke4 = new Marowak;
        poke5 = new Alakazam;
        poke6 = new Fearow;

        pokemon.push_back(poke1);
        pokemon.push_back(poke2);
        pokemon.push_back(poke3);
        pokemon.push_back(poke4);
        pokemon.push_back(poke5);
        pokemon.push_back(poke6);
        break;
      }
    case 3: //This is the player
      {
        tname = "Green";
        poke1 = new Venusaur;
        poke2 = new Butterfree;
        poke3 = new Fearow;
        poke4 = new Golem;
        poke5 = new Alakazam;
        poke6 = new Golduck;

        pokemon.push_back(poke1);
        pokemon.push_back(poke2);
        pokemon.push_back(poke3);
        pokemon.push_back(poke4);
        pokemon.push_back(poke5);
        pokemon.push_back(poke6);
        break;
      }      
    case 4: //This is Doug(aerodactyl, dugtrio, hitmonchan, ninetales, raichu, vaporeon)
      {
        tname = "Douglas";
        poke1 = new Aerodactyl;
        poke2 = new Dugtrio;
        poke3 = new Hitmonchan;
        poke4 = new Ninetales;
        poke5 = new Raichu;
        poke6 = new Vaporeon;

        pokemon.push_back(poke1);
        pokemon.push_back(poke2);
        pokemon.push_back(poke3);
        pokemon.push_back(poke4);
        pokemon.push_back(poke5);
        pokemon.push_back(poke6);
        break;
      }

    case 5: //This is John
      {
        tname = "John";
        poke1 = new Electrode;
        poke2 = new Jigglypuff;
        poke3 = new Lapras;
        poke4 = new Onix;
        poke5 = new Pikachu;
        poke6 = new Shuckle;

        pokemon.push_back(poke1);
        pokemon.push_back(poke2);
        pokemon.push_back(poke3);
        pokemon.push_back(poke4);
        pokemon.push_back(poke5);
        pokemon.push_back(poke6);
        break;
      }

    case 6: //This is Pat
      {
        tname = "Patrick";
        poke1 = new Chansey;
        poke2 = new Dragonite;
        poke3 = new Gengar;
        poke4 = new Lapras;
        poke5 = new Pidgeot;
        poke6 = new Rhydon;

        pokemon.push_back(poke1);
        pokemon.push_back(poke2);
        pokemon.push_back(poke3);
        pokemon.push_back(poke4);
        pokemon.push_back(poke5);
        pokemon.push_back(poke6);
        break;
      }
  }
}

Pokemon* Trainer::getPokemon(int n) {//returns the pokemon
  return pokemon[n];
}



#endif
