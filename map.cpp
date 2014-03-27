#include "libtcod.hpp"
#include "map.h"
#include "engine.h"


Map::Map(int width, int height) : width(width),height(height) {
	map = NULL;

	// @ dla gracza
	// ? jako gniazdo
	// O jako ¿arówka

	static const char *smap[] = {
		"##############################################",
		"#######################      #################",
		"#####################    #     ###############",
		"######################  ###        ###########",
		"##################      #####             ####",
		"################       ########    ###### ####",
		"###############      #################### ####",
		"################    ######                  ##",
		"########   #######  ######   #     #     #  ##",
		"########   ######      ###                  ##",
		"########                @        ?      O   ##",
		"####       ######      ###   #     #     #  ##",
		"#### ###   ########## ####                  ##",
		"#### ###   ##########   ###########=##########",
		"#### ##################   #####          #####",
		"#### ###             #### #####          #####",
		"####           #     ####                #####",
		"########       #     #### #####          #####",
		"########       #####      ####################",
		"##############################################",
	};

	map = new TCODMap(width,height);

	for (int y=0; y < height; y++ ) {
		for (int x=0; x < width; x++ ) {
				 if	(smap[y][x] == ' ') map->setProperties(x,y,true,true);
			else if (smap[y][x] == '#') map->setProperties(x,y,false,false);
			else if (smap[y][x] == 'O') {engine.bulb_actor_list.push(new Bulb(x,y,'O',TCODColor::yellow)); map->setProperties(x,y,true,true);}
			else if (smap[y][x] == '@') {engine.pl_actor_list.push(new Player(x,y,'@',TCODColor::green)); map->setProperties(x,y,true,true);};
		}
	}

}

Map::~Map()
{
	delete [] map;
}

void Map::Render() const {
    static const TCODColor darkWall(0,0,100);
    static const TCODColor darkGround(50,50,150);
	for (int x=0; x < width; x++) {
		for (int y=0; y < height; y++) {
			if(!map->isWalkable(x,y) && !map->isTransparent(x,y))
			{
				TCODConsole::root->setChar(x,y,'#');
			}
		}
	}
}