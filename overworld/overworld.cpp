/* overworld.cpp

This .cpp file controls character movement in the overworld, background changes, and initiation of battles

Author: J. Patrick Lacher
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

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

//The target window
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Sprite Textures
LTexture gAshTexture; //player character
LTexture gDougTexture; //enemy 1
LTexture gJohnTexture; //enemy 2
LTexture gPatrickTexture; //enemy 3

//Background Textures
LTexture gBG1Texture; //exterior background
LTexture gBG2Texture; //interior background
LTexture gBG3Texture; //interior hallway backgrond
LTexture gBG4Texture; //room 1 background
LTexture gBG5Texture; //room 2 background
LTexture gBG6Texture; //room 3 background
LTexture gBG7Texture; //room 4 background

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

	//Load Ash texture
	if( !gAshTexture.loadFromFile( "images/ash.bmp" ) )
	{
		printf( "Failed to load ash texture!\n" );
		success = false;
	}
	
	//Load NPC Textures
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

	//Load background textures
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

	return success;
}

void close()
{
	//Free loaded images
	gAshTexture.free();
	
	gDougTexture.free();
	gJohnTexture.free();
	gPatrickTexture.free();
	
	gBG1Texture.free();
	gBG2Texture.free();
	gBG3Texture.free();
	gBG4Texture.free();
	gBG5Texture.free();
	gBG6Texture.free();
	gBG7Texture.free();

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{
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

			//Event handler
			SDL_Event e;

			//The player sprite that will be moving around on the screen
			Ash ash;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

					//Handle input for  ash
					ash.handleEvent( e );
				}

				//Move  ash
				ash.move();
				
				//Check for a collision with a door on current background
				bg = ash.changeScene( bg );
				
				//Check for a collision with a wall on current background
				ash.checkCollision( bg );

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render background
				switch ( bg )
				{
					case 1: 
						gBG1Texture.render( 0, 0 );
						break;
					case 2:
						gBG2Texture.render( 0, 0 );
						break;
					case 3:
						gBG3Texture.render( 0, 0 );
						break;
					case 4:
						gBG4Texture.render( 0, 0 );
						gDougTexture.render( 430, 290 );
						break;
					case 5:
						gBG5Texture.render( 0, 0 );
						gJohnTexture.render( 440, 350 );
						break;
					case 6:
						gBG6Texture.render( 0, 0 );
						gPatrickTexture.render( 430, 285 );
						break;
					case 7:
						gBG7Texture.render( 0, 0 );
				}
				
				//Render player sprite
				ash.render();

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}