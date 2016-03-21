#OBJS specifies which files to compile as part of the project
OBJS = les26.cpp

#CC specifies which compiler we're using
CC = g++

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#potential flag -lSDL_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = thingy

#This is the target that compiles our executable
all : $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
