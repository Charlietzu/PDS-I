ALLEGRO_VERSION=5.0.10
MINGW_VERSION=4.7.0
FOLDER=C:

FOLDER_NAME=\allegro-$(ALLEGRO_VERSION)-mingw-$(MINGW_VERSION)
PATH_ALLEGRO=$(FOLDER)$(FOLDER_NAME)
LIB_ALLEGRO=\lib\liballegro-$(ALLEGRO_VERSION)-monolith-mt.a
INCLUDE_ALLEGRO=\include

all: candy.exe

candy.exe: candy.o
	gcc -o candy.exe candy.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

candy.o: candy.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c candy.c	
	
clean:
	del candy.o
	del candy.exe
