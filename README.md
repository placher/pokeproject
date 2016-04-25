# The Pokémon Project

### Introduction

This repository represents the Notre Dame CSE 20212-01 final project of J. Patrick Lacher, Douglas Schmieder, and John Adams, which was designed and implemented in the Spring of 2016.

In a group formed through our mutual love of the game, we chose to create our own version of Nintendo's beloved Pokémon series. It would have been foolhardy for us to attempt to recreate in a few weeks the entirety of Junichi Masuda’s masterwork, so we scaled down our ambitions to create a game that functioned like Pokemon wherein the player could choose his team, defeat his rivals, and be crowned champion.

The Pokémon Project is coded in C++ and uses the SDL visual library to build a small recreation of this timeless videogame classic.

### Installation

You will need to clone our [repository](https://github.com/placher/pokeproject) to the machine on which you intend to run the game.

```sh
$ git clone https://github.com/placher/pokeproject.git
$ cd pokeproject/ThePokemonProject
$ make
```

This project was developed for the Notre Dame CSE student machines. If you are running the program somewhere else, you will need to download and configure SDL2, SDL2\_image, and SDL2\_mixer from [the developer](https://www.libsdl.org) or from the SDL folder on our repository.

### Gameplay

Once you have cloned the repository and compiled the source code, simply run the executable to begin playing the game.

```sh
$ pokeproject
```

You will be prompted to select six pokémon to serve as your team in the game. For each prompt, enter 1, 2, or 3 on the command line to select the corresponding pokémon from the provided list. These will be the pokémon that fight on your side during the battles throughout the game.

The controls are simple: use the arrow keys to move your character around the world. If you encounter another trainer who wishes to battle, battle will be automatically initiated. When in a battle, use QWAS to select your pokémon's moves from their respective moveset.

Once you have chosen your team, SDL will launch and the game will begin. Make sure to turn up the volume, and good luck becoming the new Pokémon League champion!

### Disclaimer

While we may have written a lot of code for this project, we don't own these characters. Pokémon and Pokémon character names are trademarks of Nintendo.

Our use of this material for nonprofit educational purposes is protected under 17 U.S. Code § 107.