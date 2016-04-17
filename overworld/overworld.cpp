/* overworld.cpp

This .cpp file controls character movement in the overworld, background changes, and initiation of battles

Author: J. Patrick Lacher
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "headers/Trainer.h"
#include "headers/Pokemon.h"


//Screen dimension constants
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 900;

//The player sprite that will move around on the screen
class Ash
{
    public:
		//The dimensions of Ash
		static const int ASH_WIDTH = 32;
		static const int ASH_HEIGHT = 32;

		//Maximum axis velocity of ash
		static const int ASH_VEL = 10;

		//Initializes the variables
		Ash();

		//Takes key presses and adjusts Ash's velocity
		void handleEvent( SDL_Event& e );

		//Moves Ash
		void move();

		//Shows Ash on the screen
		void render();
		
		//Checks if Ash has entered a door
		int changeScene( int bg );
		
		//Checks if Ash has collided with a wall
		void checkCollision( int bg );
		
		//Checks for a battle in the current room
		bool isBattle( int bg, int battle );

    private:
		//The X and Y offsets of Ash
		int mPosX, mPosY;

		//The velocity of Ash
		int mVelX, mVelY;
};

//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );
		
		#ifdef _SDL_TTF_H
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		#endif

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};

//Initializes SDL
bool init();

//Loads media
bool loadMedia();

//Ends SDL
void close();

//Event handler
SDL_Event e;

//The target window
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Trainer Sprite Textures
LTexture gAshTexture; //player character
LTexture gDougTexture; //enemy 1
LTexture gJohnTexture; //enemy 2
LTexture gPatrickTexture; //enemy 3

//NPC Textures
LTexture gOffficerTexture; //officer
LTexture gLassTexture; //lass
LTexture gLassPkmnTexture; //lass' pokemon
LTexture gProfTexture; //professor
LTexture gProfPkmnTexture; //professor's pokemon

//Background Textures
LTexture gBG1Texture; //exterior background
LTexture gBG2Texture; //interior background
LTexture gBG3Texture; //interior hallway backgrond
LTexture gBG4Texture; //room 1 background
LTexture gBG5Texture; //room 2 background
LTexture gBG6Texture; //room 3 background
LTexture gBG7Texture; //room 4 background

//Pokemon Textures
LTexture gAerodactylTexture; //1
LTexture gAlakazamTexture; //2
LTexture gArbokTexture; //3
LTexture gArcanineTexture; //4
LTexture gBlastoiseTexture; //5
LTexture gBulbasaurTexture; //6
LTexture gButterfreeTexture; //7
LTexture gChanseyTexture; //8
LTexture gCharizardTexture; //9
LTexture gDodrioTexture; //10
LTexture gDragoniteTexture; //11
LTexture gDugtrioTexture; //12
LTexture gElectabuzzTexture; //13
LTexture gElectrodeTexture; //14
LTexture gFearowTexture; //15
LTexture gGengarTexture; //16
LTexture gGolbatTexture; //17
LTexture gGolduckTexture; //18
LTexture gGolemTexture; //19
LTexture gGravelerTexture; //20
LTexture gGyaradosTexture; //21
LTexture gHitmonchanTexture; //22
LTexture gJigglypuffTexture; //23
LTexture gKadabraTexture; //24
LTexture gKinglerTexture; //25
LTexture gLaprasTexture; //26
LTexture gMagmarTexture; //27
LTexture gMarowakTexture; //28
LTexture gNinetalesTexture; //29
LTexture gOnixTexture; //30
LTexture gPidgeotTexture; //31
LTexture gPikachuTexture; //32
LTexture gRaichuTexture; //33
LTexture gRhydonTexture; //34
LTexture gRhyhornTexture; //35
LTexture gShuckleTexture; //36
LTexture gSnorlaxTexture; //37
LTexture gVaporeonTexture; //38
LTexture gVenusaurTexture; //39

//Battle Textures
LTexture gBattleScreenTexture; //background
LTexture gHighHealthTexture; //health bar
LTexture gMedHealthTexture; //50% depleted health bar
LTexture gLowHelathTexture; //80% depleted health bar

//Move Text Box Textures
LTexture gAerodactylMovesTexture; //1
LTexture gAlakazamMovesTexture; //2
LTexture gArbokMovesTexture; //3
LTexture gArcanineMovesTexture; //4
LTexture gBlastoiseMovesTexture; //5
LTexture gBulbasaurMovesTexture; //6
LTexture gButterfreeMovesTexture; //7
LTexture gChanseyMovesTexture; //8
LTexture gCharizardMovesTexture; //9
LTexture gDodrioMovesTexture; //10
LTexture gDragoniteMovesTexture; //11
LTexture gDugtrioMovesTexture; //12
LTexture gElectabuzzMovesTexture; //13
LTexture gElectrodeMovesTexture; //14
LTexture gFearowMovesTexture; //15
LTexture gGengarMovesTexture; //16
LTexture gGolbatMovesTexture; //17
LTexture gGolduckMovesTexture; //18
LTexture gGolemMovesTexture; //19
LTexture gGravelerMovesTexture; //20
LTexture gGyaradosMovesTexture; //21
LTexture gHitmonchanMovesTexture; //22
LTexture gJigglypuffMovesTexture; //23
LTexture gKadabraMovesTexture; //24
LTexture gKinglerMovesTexture; //25
LTexture gLaprasMovesTexture; //26
LTexture gMagmarMovesTexture; //27
LTexture gMarowakMovesTexture; //28
LTexture gNinetalesMovesTexture; //29
LTexture gOnixMovesTexture; //30
LTexture gPidgeotMovesTexture; //31
LTexture gPikachuMovesTexture; //32
LTexture gRaichuMovesTexture; //33
LTexture gRhydonMovesTexture; //34
LTexture gRhyhornMovesTexture; //35
LTexture gShuckleMovesTexture; //36
LTexture gSnorlaxMovesTexture; //37
LTexture gVaporeonMovesTexture; //38
LTexture gVenusaurMovesTexture; //39

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

#ifdef _SDL_TTF_H
bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor )
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface != NULL )
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	else
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}

	
	//Return success
	return mTexture != NULL;
}
#endif

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}
		
void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

Ash::Ash()
{
    //Initialize the offsets
    mPosX = 400;
    mPosY = 840;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Ash::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= ASH_VEL; break;
            case SDLK_DOWN: mVelY += ASH_VEL; break;
            case SDLK_LEFT: mVelX -= ASH_VEL; break;
            case SDLK_RIGHT: mVelX += ASH_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += ASH_VEL; break;
            case SDLK_DOWN: mVelY -= ASH_VEL; break;
            case SDLK_LEFT: mVelX += ASH_VEL; break;
            case SDLK_RIGHT: mVelX -= ASH_VEL; break;
        }
    }
}

void Ash::move()
{
    //Move Ash left or right
    mPosX += mVelX;

    //If Ash went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + ASH_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }

    //Move Ash up or down
    mPosY += mVelY;

    //If Ash went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + ASH_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}

void Ash::render()
{
    //Show Ash
	gAshTexture.render( mPosX, mPosY );
}

int Ash::changeScene( int bg )
{
	//Check if Ash has collided with a door on the current background
	
	int back = bg;
	
	if ( bg == 1 ) //exterior
	{
		if ( mPosY <= 510 && mPosX <= 410 && mPosX >= 390 ) 
		{
			back = 2;
			mPosY = 860;
			mPosX = 430;
		}
	}
	if ( bg == 2 ) //interior
	{
		if ( mPosY <= 180 && mPosX <= 450 && mPosX >= 410 )
		{
			back = 3;
			mPosX = 440;
			mPosY = 530;
		}
	}
	if ( bg == 3 ) //interior hallway
	{
		if ( mPosY <= 250 && mPosX <= 445 && mPosX >= 435 )
		{
			back = 4;
			mPosX = 430;
			mPosY = 480;
		}
	}
	if ( bg == 4 ) //room 1
	{
		if ( mPosY <= 200 && mPosX <= 435 && mPosX >= 425 )
		{
			back = 5;
			mPosX = 440;
			mPosY = 535;
		}
	}
	if ( bg == 5 ) //room 2
	{
		if ( mPosY <= 255 && mPosX <= 445 && mPosX >= 435 )
		{
			back = 6;
			mPosX = 430;
			mPosY = 480;
		}
	}
	if ( bg == 6 ) //room 3
	{
		if ( mPosY <= 190 && mPosX <= 435 && mPosX >= 425 )
		{
			back = 7;
			mPosX = 440;
			mPosY = 535;
		}
	}
	
	//return the destination background
	return back;
}

void Ash::checkCollision( int bg )
{
	//Checks collision with walls for each of the backgrounds and adjusts Ash's position accordingly
	
	if ( bg == 1) //exterior
	{
		if ( mPosX < 180 ) mPosX = 180; //left rock face
		if ( mPosX > 680 ) mPosX = 680; //right rock face
		if ( mPosY > 845 ) mPosY = 845; //bottom rock face
		if ( mPosY < 525 && ( ( mPosX > 410 && mPosX < 630 ) || mPosX < 390 )  ) mPosY = 525; //front of building
		if ( mPosY < 350 ) mPosY = 350; //right tounge of grass
	}
	if ( bg == 2 ) //interior
	{
		if ( mPosY < 180 && ( mPosX > 450 || mPosX < 410) ) mPosY = 180; //top wall
		if ( mPosY > 870 ) mPosY = 870; //bottom wall
	}
	if ( bg == 3 ) //interior hallway
	{
		if ( mPosX > 445 ) mPosX = 445; //right edge of carpet
		if ( mPosX < 435 ) mPosX = 435; //left edge of carpet
		if ( mPosY > 535 ) mPosY = 535; //bottom wall
	}
	if ( bg == 4 ) //room 1
	{
		if ( mPosY > 360 && mPosX > 445 ) mPosX = 445; //right side of lower "T"
		if ( mPosY > 360 && mPosX < 410 ) mPosX = 410; //left side of lower "T"
		if ( mPosX > 510 ) mPosX = 510; //right side of upper "T"
		if ( mPosX < 345 ) mPosX = 345; //left side of upper "T"
		if ( mPosY < 215 && ( mPosX > 435 || mPosX < 425) ) mPosY = 215; //top wall
		if ( mPosY > 485 ) mPosY = 485; //bottom wall
	}
	if ( bg == 5 ) //room 2
	{
		if ( mPosY > 410 && mPosX > 460 ) mPosX = 460; //right side of lower "T"
		if ( mPosY > 410 && mPosX < 420 ) mPosX = 420; //left side of lower "T"
		if ( mPosX > 525 ) mPosX = 525; //right side of upper "T"
		if ( mPosX < 355 ) mPosX = 355; //left side of upper "T"
		if ( mPosY < 265 && ( mPosX > 445 || mPosX < 435) ) mPosY = 265; //top wall
		if ( mPosY > 535 ) mPosY = 535; //bottom wall
	}
	if ( bg == 6 ) //room 3
	{
		if ( mPosY > 360 && mPosX > 445 ) mPosX = 445; //right side of lower "T"
		if ( mPosY > 360 && mPosX < 410 ) mPosX = 410; //left side of lower "T"
		if ( mPosX > 510 ) mPosX = 510; //right side of upper "T"
		if ( mPosX < 345 ) mPosX = 345; //left side of upper "T"
		if ( mPosY < 215 && ( mPosX > 435 || mPosX < 425) ) mPosY = 215; //top wall
		if ( mPosY > 485 ) mPosY = 485; //bottom wall
	}
	if ( bg == 7 ) // room 4
	{
		if ( mPosY > 440 && mPosX > 450 ) mPosX = 450; //right side of entryway
		if ( mPosY > 440 && mPosX < 430 ) mPosX = 430; //left side of entryway
		if ( mPosX < 263 ) mPosX = 263; //left wall
		if ( mPosX > 617 ) mPosX = 617; //right wall
		if ( mPosY < 260 ) mPosY = 260; //top wall
		if ( mPosY > 535 ) mPosY = 535; //bottom wall
	}
}

bool Ash::isBattle( int bg, int battle )
{
	
	//Checks if a battle should initiate in the room
	
	if ( battle == 1 )
	{
		switch ( bg )
		{
			case 1: //exterior has no battle
				return false;
				break;
			case 2: //interior has no battle
				return false;
				break;
			case 3: //interior hallway has no battle
				return false;
				break;
			case 4: //room 1
				if ( mPosY < 360 ) return true;
				break;
			case 5: //room 2
				if ( mPosY < 410 ) return true;
				break;
			case 6: //room 3
				if ( mPosY < 360 ) return true;
				break;
			case 7: //room 4 has no battle
				return false;
		}
	}
	
	return false;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "The Pokemon Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 255 );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load Ash Texture
	if( !gAshTexture.loadFromFile( "images/ash.bmp" ) )
	{
		printf( "Failed to load ash texture!\n" );
		success = false;
	}
	
	//Load Enemy Textures
	if( !gDougTexture.loadFromFile( "images/doug.bmp" ) )
	{
		printf( "Failed to load doug texture!\n" );
		success = false;
	}
	if( !gJohnTexture.loadFromFile( "images/captjohn.bmp" ) )
	{
		printf( "Failed to load captjohn texture!\n" );
		success = false;
	}
	if( !gPatrickTexture.loadFromFile( "images/patrick.bmp" ) )
	{
		printf( "Failed to load patrick texture!\n" );
		success = false;
	}
	
	//Load NPC Textures
	if( !gOffficerTexture.loadFromFile( "images/officer.bmp" ) )
	{
		printf( "Failed to load officer texture!\n" );
		success = false;
	}
	if( !gLassTexture.loadFromFile( "images/lass.bmp" ) )
	{
		printf( "Failed to load lass texture!\n" );
		success = false;
	}
	if( !gLassPkmnTexture.loadFromFile( "images/lasspkmn.bmp" ) )
	{
		printf( "Failed to load lasspkmn texture!\n" );
		success = false;
	}
	if( !gProfTexture.loadFromFile( "images/prof.bmp" ) )
	{
		printf( "Failed to load prof texture!\n" );
		success = false;
	}
	if( !gProfPkmnTexture.loadFromFile( "images/profpkmn.bmp" ) )
	{
		printf( "Failed to load profpkmn texture!\n" );
		success = false;
	}

	//Load Background Textures
	if( !gBG1Texture.loadFromFile( "images/exterior.bmp" ) )
	{
		printf( "Failed to load exterior texture!\n" );
		success = false;
	}
	if( !gBG2Texture.loadFromFile( "images/hallway.bmp" ) )
	{
		printf( "Failed to load hallway texture!\n" );
		success = false;
	}
	if( !gBG3Texture.loadFromFile( "images/interior_1.bmp" ) )
	{
		printf( "Failed to load interior_1 texture!\n" );
		success = false;
	}
	if( !gBG4Texture.loadFromFile( "images/room_1.bmp" ) )
	{
		printf( "Failed to load room_1 texture!\n" );
		success = false;
	}
	if( !gBG5Texture.loadFromFile( "images/room_2.bmp" ) )
	{
		printf( "Failed to load room_2 texture!\n" );
		success = false;
	}
	if( !gBG6Texture.loadFromFile( "images/room_3.bmp" ) )
	{
		printf( "Failed to load room_3 texture!\n" );
		success = false;
	}
	if( !gBG7Texture.loadFromFile( "images/room_4.bmp" ) )
	{
		printf( "Failed to load room_4 texture!\n" );
		success = false;
	}
	
	//Load Pokemon Textures
	if( !gAerodactylTexture.loadFromFile( "images/battle/aerodactyl.bmp" ) )
	{
		printf( "Failed to load aerodactyl texture!\n" );
		success = false;
	}
	if( !gAlakazamTexture.loadFromFile( "images/battle/alakazam.bmp" ) )
	{
		printf( "Failed to load alakazam texture!\n" );
		success = false;
	}
	if( !gArbokTexture.loadFromFile( "images/battle/arbok.bmp" ) )
	{
		printf( "Failed to load arbok texture!\n" );
		success = false;
	}
	if( !gArcanineTexture.loadFromFile( "images/battle/arcanine.bmp" ) )
	{
		printf( "Failed to load arcanine texture!\n" );
		success = false;
	}
	if( !gBlastoiseTexture.loadFromFile( "images/battle/blastoise.bmp" ) )
	{
		printf( "Failed to load blastoise texture!\n" );
		success = false;
	}
	if( !gBulbasaurTexture.loadFromFile( "images/battle/bulbasaur.bmp" ) )
	{
		printf( "Failed to load bulbasaur texture!\n" );
		success = false;
	}
	if( !gButterfreeTexture.loadFromFile( "images/battle/butterfree.bmp" ) )
	{
		printf( "Failed to load butterfree texture!\n" );
		success = false;
	}
	if( !gChanseyTexture.loadFromFile( "images/battle/chansey.bmp" ) )
	{
		printf( "Failed to load chansey texture!\n" );
		success = false;
	}
	if( !gCharizardTexture.loadFromFile( "images/battle/charizard.bmp" ) )
	{
		printf( "Failed to load charizard texture!\n" );
		success = false;
	}
	if( !gDodrioTexture.loadFromFile( "images/battle/dodrio.bmp" ) )
	{
		printf( "Failed to load dodrio texture!\n" );
		success = false;
	}
	if( !gDragoniteTexture.loadFromFile( "images/battle/dragonite.bmp" ) )
	{
		printf( "Failed to load dragonite texture!\n" );
		success = false;
	}
	if( !gDugtrioTexture.loadFromFile( "images/battle/dugtrio.bmp" ) )
	{
		printf( "Failed to load dugtrio texture!\n" );
		success = false;
	}
	if( !gElectabuzzTexture.loadFromFile( "images/battle/electabuzz.bmp" ) )
	{
		printf( "Failed to load electabuzz texture!\n" );
		success = false;
	}
	if( !gElectrodeTexture.loadFromFile( "images/battle/electrode.bmp" ) )
	{
		printf( "Failed to load electrode texture!\n" );
		success = false;
	}
	if( !gFearowTexture.loadFromFile( "images/battle/fearow.bmp" ) )
	{
		printf( "Failed to load fearow texture!\n" );
		success = false;
	}
	if( !gGengarTexture.loadFromFile( "images/battle/gengar.bmp" ) )
	{
		printf( "Failed to load gengar texture!\n" );
		success = false;
	}
	if( !gGolbatTexture.loadFromFile( "images/battle/golbat.bmp" ) )
	{
		printf( "Failed to load golbat texture!\n" );
		success = false;
	}
	if( !gGolduckTexture.loadFromFile( "images/battle/golduck.bmp" ) )
	{
		printf( "Failed to load golduck texture!\n" );
		success = false;
	}
	if( !gGolemTexture.loadFromFile( "images/battle/golem.bmp" ) )
	{
		printf( "Failed to load golem texture!\n" );
		success = false;
	}
	if( !gGravelerTexture.loadFromFile( "images/battle/graveler.bmp" ) )
	{
		printf( "Failed to load graveler texture!\n" );
		success = false;
	}
	if( !gGyaradosTexture.loadFromFile( "images/battle/gyarados.bmp" ) )
	{
		printf( "Failed to load gyarados texture!\n" );
		success = false;
	}
	if( !gHitmonchanTexture.loadFromFile( "images/battle/hitmonchan.bmp" ) )
	{
		printf( "Failed to load hitmonchan texture!\n" );
		success = false;
	}
	if( !gJigglypuffTexture.loadFromFile( "images/battle/jigglypuff.bmp" ) )
	{
		printf( "Failed to load jigglypuff texture!\n" );
		success = false;
	}
	if( !gKadabraTexture.loadFromFile( "images/battle/kadabra.bmp" ) )
	{
		printf( "Failed to load kadabra texture!\n" );
		success = false;
	}
	if( !gKinglerTexture.loadFromFile( "images/battle/kingler.bmp" ) )
	{
		printf( "Failed to load kingler texture!\n" );
		success = false;
	}
	if( !gLaprasTexture.loadFromFile( "images/battle/lapras.bmp" ) )
	{
		printf( "Failed to load lapras texture!\n" );
		success = false;
	}
	if( !gMagmarTexture.loadFromFile( "images/battle/magmar.bmp" ) )
	{
		printf( "Failed to load magmar texture!\n" );
		success = false;
	}
	if( !gMarowakTexture.loadFromFile( "images/battle/marowak.bmp" ) )
	{
		printf( "Failed to load marowak texture!\n" );
		success = false;
	}
	if( !gNinetalesTexture.loadFromFile( "images/battle/ninetales.bmp" ) )
	{
		printf( "Failed to load ninetales texture!\n" );
		success = false;
	}
	if( !gOnixTexture.loadFromFile( "images/battle/onix.bmp" ) )
	{
		printf( "Failed to load onix texture!\n" );
		success = false;
	}
	if( !gPidgeotTexture.loadFromFile( "images/battle/pidgeot.bmp" ) )
	{
		printf( "Failed to load pidgeot texture!\n" );
		success = false;
	}
	if( !gPikachuTexture.loadFromFile( "images/battle/pikachu.bmp" ) )
	{
		printf( "Failed to load pikachu texture!\n" );
		success = false;
	}
	if( !gRaichuTexture.loadFromFile( "images/battle/raichu.bmp" ) )
	{
		printf( "Failed to load raichu texture!\n" );
		success = false;
	}
	if( !gRhydonTexture.loadFromFile( "images/battle/rhydon.bmp" ) )
	{
		printf( "Failed to load rhydon texture!\n" );
		success = false;
	}
	if( !gRhyhornTexture.loadFromFile( "images/battle/rhyhorn.bmp" ) )
	{
		printf( "Failed to load rhyhorn texture!\n" );
		success = false;
	}
	if( !gShuckleTexture.loadFromFile( "images/battle/shuckle.bmp" ) )
	{
		printf( "Failed to load shuckle texture!\n" );
		success = false;
	}
	if( !gSnorlaxTexture.loadFromFile( "images/battle/snorlax.bmp" ) )
	{
		printf( "Failed to load snorlax texture!\n" );
		success = false;
	}
	if( !gVaporeonTexture.loadFromFile( "images/battle/vaporeon.bmp" ) )
	{
		printf( "Failed to load vaporeon texture!\n" );
		success = false;
	}
	if( !gVenusaurTexture.loadFromFile( "images/battle/venusaur.bmp" ) )
	{
		printf( "Failed to load venusaur texture!\n" );
		success = false;
	}
	
	//Load Battle Textures
	if( !gBattleScreenTexture.loadFromFile( "images/battle/battle_screen.bmp" ) )
	{
		printf( "Failed to load battle_screen texture!\n" );
		success = false;
	}
	if( !gHighHealthTexture.loadFromFile( "images/battle/high_health.bmp" ) )
	{
		printf( "Failed to load high_health texture!\n" );
		success = false;
	}
	if( !gMedHealthTexture.loadFromFile( "images/battle/med_health.bmp" ) )
	{
		printf( "Failed to load med_health texture!\n" );
		success = false;
	}
	if( !gLowHelathTexture.loadFromFile( "images/battle/low_health.bmp" ) )
	{
		printf( "Failed to load low_health texture!\n" );
		success = false;
	}
	
	//Load Moves Text Box Textures
	if( !gAerodactylMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Aerodactyl.bmp" ) )
	{
		printf( "Failed to load moves_aerodactyl texture!\n" );
		success = false;
	}
	if( !gAlakazamMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Alakazam.bmp" ) )
	{
		printf( "Failed to load moves_alakazam texture!\n" );
		success = false;
	}
	if( !gArbokMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Arbok.bmp" ) )
	{
		printf( "Failed to load moves_arbok texture!\n" );
		success = false;
	}
	if( !gArcanineMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Arcanine.bmp" ) )
	{
		printf( "Failed to load moves_arcanine texture!\n" );
		success = false;
	}
	if( !gBlastoiseMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Blastoise.bmp" ) )
	{
		printf( "Failed to load moves_blastoise texture!\n" );
		success = false;
	}
	if( !gBulbasaurMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Bulbasaur.bmp" ) )
	{
		printf( "Failed to load moves_bulbasaur texture!\n" );
		success = false;
	}
	if( !gButterfreeMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Butterfree.bmp" ) )
	{
		printf( "Failed to load moves_butterfree texture!\n" );
		success = false;
	}
	if( !gChanseyMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Chansey.bmp" ) )
	{
		printf( "Failed to load moves_chansey texture!\n" );
		success = false;
	}
	if( !gCharizardMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Charizard.bmp" ) )
	{
		printf( "Failed to load moves_charizard texture!\n" );
		success = false;
	}
	if( !gDodrioMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Dodrio.bmp" ) )
	{
		printf( "Failed to load moves_dodrio texture!\n" );
		success = false;
	}
	if( !gDragoniteMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Dragonite.bmp" ) )
	{
		printf( "Failed to load moves_dragonite texture!\n" );
		success = false;
	}
	if( !gDugtrioMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Dugtrio.bmp" ) )
	{
		printf( "Failed to load moves_dugtrio texture!\n" );
		success = false;
	}
	if( !gElectabuzzMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Electabuzz.bmp" ) )
	{
		printf( "Failed to load moves_electabuzz texture!\n" );
		success = false;
	}
	if( !gElectrodeMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Electrode.bmp" ) )
	{
		printf( "Failed to load moves_electrode texture!\n" );
		success = false;
	}
	if( !gFearowMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Fearow.bmp" ) )
	{
		printf( "Failed to load moves_fearow texture!\n" );
		success = false;
	}
	if( !gGengarMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Gengar.bmp" ) )
	{
		printf( "Failed to load moves_gengar texture!\n" );
		success = false;
	}
	if( !gGolbatMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Golbat.bmp" ) )
	{
		printf( "Failed to load moves_golbat texture!\n" );
		success = false;
	}
	if( !gGolduckMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Golduck.bmp" ) )
	{
		printf( "Failed to load moves_golduck texture!\n" );
		success = false;
	}
	if( !gGolemMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Golem.bmp" ) )
	{
		printf( "Failed to load moves_golem texture!\n" );
		success = false;
	}
	if( !gGravelerMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Graveler.bmp" ) )
	{
		printf( "Failed to load moves_graveler texture!\n" );
		success = false;
	}
	if( !gGyaradosMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Gyarados.bmp" ) )
	{
		printf( "Failed to load moves_gyarados texture!\n" );
		success = false;
	}
	if( !gHitmonchanMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Hitmonchan.bmp" ) )
	{
		printf( "Failed to load moves_hitmonchan texture!\n" );
		success = false;
	}
	if( !gJigglypuffMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Jigglypuff.bmp" ) )
	{
		printf( "Failed to load moves_jigglypuff texture!\n" );
		success = false;
	}
	if( !gKadabraMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Kadabra.bmp" ) )
	{
		printf( "Failed to load moves_kadabra texture!\n" );
		success = false;
	}
	if( !gKinglerMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Kingler.bmp" ) )
	{
		printf( "Failed to load moves_kingler texture!\n" );
		success = false;
	}
	if( !gLaprasMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Lapras.bmp" ) )
	{
		printf( "Failed to load moves_lapras texture!\n" );
		success = false;
	}
	if( !gMagmarMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Magmar.bmp" ) )
	{
		printf( "Failed to load moves_magmar texture!\n" );
		success = false;
	}
	if( !gMarowakMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Marowak.bmp" ) )
	{
		printf( "Failed to load moves_marowak texture!\n" );
		success = false;
	}
	if( !gNinetalesMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Ninetales.bmp" ) )
	{
		printf( "Failed to load moves_ninetales texture!\n" );
		success = false;
	}
	if( !gOnixMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Onix.bmp" ) )
	{
		printf( "Failed to load moves_onix texture!\n" );
		success = false;
	}
	if( !gPidgeotMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Pidgeot.bmp" ) )
	{
		printf( "Failed to load moves_pidgeot texture!\n" );
		success = false;
	}
	if( !gPikachuMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Pikachu.bmp" ) )
	{
		printf( "Failed to load moves_pikachu texture!\n" );
		success = false;
	}
	if( !gRaichuMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Raichu.bmp" ) )
	{
		printf( "Failed to load moves_raichu texture!\n" );
		success = false;
	}
	if( !gRhydonMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Rhydon.bmp" ) )
	{
		printf( "Failed to load moves_rhydon texture!\n" );
		success = false;
	}
	if( !gRhyhornMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Rhyhorn.bmp" ) )
	{
		printf( "Failed to load moves_rhyhorn texture!\n" );
		success = false;
	}
	if( !gShuckleMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Shuckle.bmp" ) )
	{
		printf( "Failed to load moves_shuckle texture!\n" );
		success = false;
	}
	if( !gSnorlaxMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Snorlax.bmp" ) )
	{
		printf( "Failed to load moves_snorlax texture!\n" );
		success = false;
	}
	if( !gVaporeonMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Vaporeon.bmp" ) )
	{
		printf( "Failed to load moves_vaporeon texture!\n" );
		success = false;
	}
	if( !gVenusaurMovesTexture.loadFromFile( "images/battle/MovesBMPs/Moves_Venusaur.bmp" ) )
	{
		printf( "Failed to load moves_venusaur texture!\n" );
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	
	//Player Sprite
	gAshTexture.free();
	
	//Enemy Sprites
	gDougTexture.free();
	gJohnTexture.free();
	gPatrickTexture.free();
	
	//NPC Sprites
	gOffficerTexture.free();
	gLassTexture.free();
	gLassPkmnTexture.free();
	gProfTexture.free();
	gProfPkmnTexture.free();
	
	//Backgrounds
	gBG1Texture.free();
	gBG2Texture.free();
	gBG3Texture.free();
	gBG4Texture.free();
	gBG5Texture.free();
	gBG6Texture.free();
	gBG7Texture.free();
	
	//Pokemon Sprites
	gAerodactylTexture.free();
	gAlakazamTexture.free();
	gArbokTexture.free();
	gArcanineTexture.free();
	gBlastoiseTexture.free();
	gBulbasaurTexture.free();
	gButterfreeTexture.free();
	gChanseyTexture.free();
	gCharizardTexture.free();
	gDodrioTexture.free();
	gDragoniteTexture.free();
	gDugtrioTexture.free();
	gElectabuzzTexture.free();
	gElectrodeTexture.free();
	gFearowTexture.free();
	gGengarTexture.free();
	gGolbatTexture.free();
	gGolduckTexture.free();
	gGolemTexture.free();
	gGravelerTexture.free();
	gGyaradosTexture.free();
	gHitmonchanTexture.free();
	gJigglypuffTexture.free();
	gKadabraTexture.free();
	gKinglerTexture.free();
	gLaprasTexture.free();
	gMagmarTexture.free();
	gMarowakTexture.free();
	gNinetalesTexture.free();
	gOnixTexture.free();
	gPidgeotTexture.free();
	gPikachuTexture.free();
	gRaichuTexture.free();
	gRhydonTexture.free();
	gRhyhornTexture.free();
	gShuckleTexture.free();
	gSnorlaxTexture.free();
	gVaporeonTexture.free();
	gVenusaurTexture.free();
	
	//Battle Textures
	gBattleScreenTexture.free();
	gHighHealthTexture.free();
	gMedHealthTexture.free();
	gLowHelathTexture.free();
	
	//Move Text Box Textures
	gAerodactylMovesTexture.free();
	gAlakazamMovesTexture.free();
	gArbokMovesTexture.free();
	gArcanineMovesTexture.free();
	gBlastoiseMovesTexture.free();
	gBulbasaurMovesTexture.free();
	gButterfreeMovesTexture.free();
	gChanseyMovesTexture.free();
	gCharizardMovesTexture.free();
	gDodrioMovesTexture.free();
	gDragoniteMovesTexture.free();
	gDugtrioMovesTexture.free();
	gElectabuzzMovesTexture.free();
	gElectrodeMovesTexture.free();
	gFearowMovesTexture.free();
	gGengarMovesTexture.free();
	gGolbatMovesTexture.free();
	gGolduckMovesTexture.free();
	gGolemMovesTexture.free();
	gGravelerMovesTexture.free();
	gGyaradosMovesTexture.free();
	gHitmonchanMovesTexture.free();
	gJigglypuffMovesTexture.free();
	gKadabraMovesTexture.free();
	gKinglerMovesTexture.free();
	gLaprasMovesTexture.free();
	gMagmarMovesTexture.free();
	gMarowakMovesTexture.free();
	gNinetalesMovesTexture.free();
	gOnixMovesTexture.free();
	gPidgeotMovesTexture.free();
	gPikachuMovesTexture.free();
	gRaichuMovesTexture.free();
	gRhydonMovesTexture.free();
	gRhyhornMovesTexture.free();
	gShuckleMovesTexture.free();
	gSnorlaxMovesTexture.free();
	gVaporeonMovesTexture.free();
	gVenusaurMovesTexture.free();

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void renderPokemon( int num, int x, int y )
{
	//render a specific pokemon sprite to the screen at coordinates (x,y)

	switch ( num )
	{
		case 1:
			gAerodactylTexture.render( x, y );
			break;
		case 2:
			gAlakazamTexture.render( x, y );
			break;
		case 3:
			gArbokTexture.render( x, y );
			break;
		case 4:
			gArcanineTexture.render( x, y );
			break;
		case 5:
			gBlastoiseTexture.render( x, y );
			break;
		case 6:
			gBulbasaurTexture.render( x, y );
			break;
		case 7:
			gButterfreeTexture.render( x, y );
			break;
		case 8:
			gChanseyTexture.render( x, y );
			break;
		case 9:
			gCharizardTexture.render( x, y );
			break;
		case 10:
			gDodrioTexture.render( x, y );
			break;
		case 11:
			gDragoniteTexture.render( x, y );
			break;
		case 12:
			gDugtrioTexture.render( x, y );
			break;
		case 13:
			gElectabuzzTexture.render( x, y );
			break;
		case 14:
			gElectrodeTexture.render( x, y );
			break;
		case 15:
			gFearowTexture.render( x, y );
			break;
		case 16:
			gGengarTexture.render( x, y );
			break;
		case 17:
			gGolbatTexture.render( x, y );
			break;
		case 18:
			gGolduckTexture.render( x, y );
			break;
		case 19:
			gGolemTexture.render( x, y );
			break;
		case 20:
			gGravelerTexture.render( x, y );
			break;
		case 21:
			gGyaradosTexture.render( x, y );
			break;
		case 22:
			gHitmonchanTexture.render( x, y );
			break;
		case 23:
			gJigglypuffTexture.render( x, y );
			break;
		case 24:
			gKadabraTexture.render( x, y );
			break;
		case 25:
			gKinglerTexture.render( x, y );
			break;
		case 26:
			gLaprasTexture.render( x, y );
			break;
		case 27:
			gMagmarTexture.render( x, y );
			break;
		case 28:
			gMarowakTexture.render( x, y );
			break;
		case 29:
			gNinetalesTexture.render( x, y );
			break;
		case 30:
			gOnixTexture.render( x, y );
			break;
		case 31:
			gPidgeotTexture.render( x, y );
			break;
		case 32:
			gPikachuTexture.render( x, y );
			break;
		case 33:
			gRaichuTexture.render( x, y );
			break;
		case 34:
			gRhydonTexture.render( x, y );
			break;
		case 35:
			gRhyhornTexture.render( x, y );
			break;
		case 36:
			gShuckleTexture.render( x, y );
			break;
		case 37:
			gSnorlaxTexture.render( x, y );
			break;
		case 38:
			gVaporeonTexture.render( x, y );
			break;
		case 39:
			gVenusaurTexture.render( x, y );
	}
}

void renderMoveBox( int num )
{
	//render a specific pokemon's move list to the battle screen
	
	int x = 225;
	int y = 545;

	switch ( num )
	{
		case 1:
			gAerodactylMovesTexture.render( x, y );
			break;
		case 2:
			gAlakazamMovesTexture.render( x, y );
			break;
		case 3:
			gArbokMovesTexture.render( x, y );
			break;
		case 4:
			gArcanineMovesTexture.render( x, y );
			break;
		case 5:
			gBlastoiseMovesTexture.render( x, y );
			break;
		case 6:
			gBulbasaurMovesTexture.render( x, y );
			break;
		case 7:
			gButterfreeMovesTexture.render( x, y );
			break;
		case 8:
			gChanseyMovesTexture.render( x, y );
			break;
		case 9:
			gCharizardMovesTexture.render( x, y );
			break;
		case 10:
			gDodrioMovesTexture.render( x, y );
			break;
		case 11:
			gDragoniteMovesTexture.render( x, y );
			break;
		case 12:
			gDugtrioMovesTexture.render( x, y );
			break;
		case 13:
			gElectabuzzMovesTexture.render( x, y );
			break;
		case 14:
			gElectrodeMovesTexture.render( x, y );
			break;
		case 15:
			gFearowMovesTexture.render( x, y );
			break;
		case 16:
			gGengarMovesTexture.render( x, y );
			break;
		case 17:
			gGolbatMovesTexture.render( x, y );
			break;
		case 18:
			gGolduckMovesTexture.render( x, y );
			break;
		case 19:
			gGolemMovesTexture.render( x, y );
			break;
		case 20:
			gGravelerMovesTexture.render( x, y );
			break;
		case 21:
			gGyaradosMovesTexture.render( x, y );
			break;
		case 22:
			gHitmonchanMovesTexture.render( x, y );
			break;
		case 23:
			gJigglypuffMovesTexture.render( x, y );
			break;
		case 24:
			gKadabraMovesTexture.render( x, y );
			break;
		case 25:
			gKinglerMovesTexture.render( x, y );
			break;
		case 26:
			gLaprasMovesTexture.render( x, y );
			break;
		case 27:
			gMagmarMovesTexture.render( x, y );
			break;
		case 28:
			gMarowakMovesTexture.render( x, y );
			break;
		case 29:
			gNinetalesMovesTexture.render( x, y );
			break;
		case 30:
			gOnixMovesTexture.render( x, y );
			break;
		case 31:
			gPidgeotMovesTexture.render( x, y );
			break;
		case 32:
			gPikachuMovesTexture.render( x, y );
			break;
		case 33:
			gRaichuMovesTexture.render( x, y );
			break;
		case 34:
			gRhydonMovesTexture.render( x, y );
			break;
		case 35:
			gRhyhornMovesTexture.render( x, y );
			break;
		case 36:
			gShuckleMovesTexture.render( x, y );
			break;
		case 37:
			gSnorlaxMovesTexture.render( x, y );
			break;
		case 38:
			gVaporeonMovesTexture.render( x, y );
			break;
		case 39:
			gVenusaurMovesTexture.render( x, y );
	}
}

int handleMove( SDL_Event& e, int move )
{
	//determines what move the player has entered
	
	int mover;
	if ( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_q: mover = 0; break;
			case SDLK_w: mover = 1; break;
			case SDLK_a: mover = 2; break;
			case SDLK_s: mover = 3; break;
			default: mover = 15; break;
		}
	}
	else mover = 15;
	return mover;
}

int main( int argc, char* args[] )
{	
	//Initialize Trainers
	Trainer Player(1);
	Trainer Douglas(4);
	Trainer John(5);
	Trainer Patrick(6);
	
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;
			
			//Background scene selector
			int bg = 1;
			
			//Allow for battle flag
			int battle = 1;
			
			//Test for Loss of Battle
			int result = 0;
			
			//Trainer Handlers
			Trainer enemy(5);
			Trainer player = Player;
			
			//Retained value of bg in previous frame
			int bg_backup;
			
			//batte continuation flag
			bool ended = false;
			
			//index of pokemon in trainers' pokemon array
			int ppkmn = 0; //player
			int epkmn = 0; //enemy
			
			//move entered by player
			int move = 15;
			
			//Key Released Event
			SDL_Event up;
			up.type = SDL_KEYUP;
			up.key.keysym.sym = SDLK_UP;

			//Driver for the player sprite that will be moving around on the screen
			Ash ash;

			//While application is running
			while( !quit )
			{
				move = 15;
				
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

					if ( ended ) move = handleMove( e, move );
					
					//Handle input for ash
					if ( !ended ) ash.handleEvent( e );
				}

				if ( !ended )
				{
					//Clear screen
					SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
					SDL_RenderClear( gRenderer );

					//Move ash
					ash.move();
					
					//Save old background for later comparisson
					bg_backup = bg;
					
					//Check for a collision with a door on current background
					bg = ash.changeScene( bg );
					
					//Allow for new battle in room if room has changed
					if ( bg != bg_backup )
					{
						battle = 1;
					}
					
					//Check for a collision with a wall on current background
					ash.checkCollision( bg );
					
					//Render background
					switch ( bg )
					{
						case 1: //exterior
							gBG1Texture.render( 0, 0 );
							break;
						case 2: //interior
							gBG2Texture.render( 0, 0 );
							
							//render NPC sprites in lobby
							gOffficerTexture.render( 370, 190 );
							gOffficerTexture.render( 495, 190 );
							gLassPkmnTexture.render( 273, 355 );
							gLassTexture.render( 250, 350 );
							gProfPkmnTexture.render( 683, 655 );
							gProfTexture.render( 650, 650 );
							
							break;
						case 3: //interior hallway
							gBG3Texture.render( 0, 0 );
							break;
						case 4: //room 1
							gBG4Texture.render( 0, 0 );
							if ( battle == 1 ) gDougTexture.render( 430, 290 );
							break;
						case 5: //room 2
							gBG5Texture.render( 0, 0 );
							if ( battle == 1 ) gJohnTexture.render( 440, 350 );
							break;
						case 6: //room 3
							gBG6Texture.render( 0, 0 );
							if ( battle == 1 ) gPatrickTexture.render( 430, 285 );
							break;
						case 7: //room 4
							gBG7Texture.render( 0, 0 );
					}
					
					//Render player sprite
					ash.render();

					//Update screen
					SDL_RenderPresent( gRenderer );
				}
				
				//Run battle if one occurs
				if ( ash.isBattle( bg, battle ) )
				{
					switch( bg )
					{
						case 4: //first battle
							enemy = Douglas;
							player = Player;
							ended = true;
							ppkmn = 0;
							epkmn = 0;
							break;
						case 5: //second battle
							enemy = John;
							player = Player;
							ended = true;
							ppkmn = 0;
							epkmn = 0;
							break;
						case 6: //third battle
							enemy = Patrick;
							player = Player;
							ended = true;
							ppkmn = 0;
							epkmn = 0;
							break;
					}
					battle = 0;
				}				
				
				if ( ended ) //while battle isn't over
				{
					//Clear screen
					SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
					SDL_RenderClear( gRenderer );
					
					//render background
					gBattleScreenTexture.render( 0, 0 );

					//render appropriate health bars
					//enemy
					if( ( double(enemy.getPokemon(epkmn)->getchealth())/double(enemy.getPokemon(epkmn)->getmhealth()) ) >= 0.8 ) gHighHealthTexture.render( 291, 277 );
					else if ( ( double(enemy.getPokemon(epkmn)->getchealth())/double(enemy.getPokemon(epkmn)->getmhealth()) ) >= 0.2 ) gMedHealthTexture.render( 291, 277 );
					else gLowHelathTexture.render( 291, 277 );
					
					//player
					if( ( double(player.getPokemon(ppkmn)->getchealth())/double(player.getPokemon(ppkmn)->getmhealth()) ) >= 0.8 ) gHighHealthTexture.render( 515, 478 );
					else if ( ( double(player.getPokemon(ppkmn)->getchealth())/double(player.getPokemon(ppkmn)->getmhealth()) ) >= 0.2 ) gMedHealthTexture.render( 515, 478 );
					else gLowHelathTexture.render( 515, 478 );
					
					//render pokemon sprites
					renderPokemon( enemy.getPokemon(epkmn)->getNum(), 555, 303 ); //enemy
					renderPokemon( player.getPokemon(ppkmn)->getNum(), 329, 453 ); //player
					
					//render moveset box
					renderMoveBox( player.getPokemon(ppkmn)->getNum() );
					
					//Update screen
					SDL_RenderPresent( gRenderer );
					
					if ( move != 15 ) //ensure that the user entered a valid move
					{
						//player attacks enemy pokemon
						enemy.getPokemon( epkmn )->takeDamage( player.getPokemon( ppkmn )->doDamage( move ) );
						
						//enemy pokemon attacks if not KO'd
						if ( enemy.getPokemon( epkmn )->getchealth() != 0 )
						{
							//enemy pokemon attacks
							player.getPokemon( ppkmn )->takeDamage( enemy.getPokemon( epkmn )->doDamage( rand() % 3 ) );
						}
						else //enemy pokemon KO'd
						{
							if ( epkmn == 5 ) //enemy is out of pokemon
							{
								result = 0; //battle won
								ended = false;
							}
							else epkmn++;
							
						}
						
						//check if player pokemon is KO'd
						if ( player.getPokemon( ppkmn )->getchealth() == 0 )
						{
							if ( ppkmn == 5 ) //player is out of pokemon
							{
								result = 1; //battle lost
								ended = false;
							}
							else ppkmn++;
						}
					}
				}
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}