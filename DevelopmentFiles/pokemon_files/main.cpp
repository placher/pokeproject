//This is a test of the trainer and pokemon files
//
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Trainer.h"

using namespace std;


int main()
{
  int i;
  Trainer trainer(1);

  for(i = 0; i < 6; i++) 
    cout << trainer.getPokemon(i)->gettype2() << endl;

  cin >> i;
  cin.clear();
  cout << i << endl;
  int j = 'w';

  cout << j << endl;





}



