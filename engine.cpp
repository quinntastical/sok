#include "libtcod.hpp"
#include "engine.h"
#include "map.h"
#include "player.h"

Engine::Engine()
{
	TCODConsole::setCustomFont("font.png", TCOD_FONT_LAYOUT_ASCII_INROW,16,16);
	TCODConsole::initRoot(40,25,"sok",false);

    pl_actor = new Player(20,10,'@',TCODColor::white);
	pl_actor_list.push(pl_actor);
    //actors.push(new Actor(60,13,'@',TCODColor::yellow));
    map = new Map(40,25);
}
Engine::~Engine()
{
	//actors.clearAndDelete();
	delete map;
}

void Engine::Update()
{
	TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL);
    switch(key.vk) {
        case TCODK_UP : 
            if ( ! map->isWall(pl_actor->x,pl_actor->y-1)) {
                pl_actor->y--;   
            }
        break;
        case TCODK_DOWN : 
            if ( ! map->isWall(pl_actor->x,pl_actor->y+1)) {
                pl_actor->y++;
            }
        break;
        case TCODK_LEFT : 
            if ( ! map->isWall(pl_actor->x-1,pl_actor->y)) {
                pl_actor->x--;
            }
        break;
        case TCODK_RIGHT : 
            if ( ! map->isWall(pl_actor->x+1,pl_actor->y)) {
                pl_actor->x++;
            }
        break;
        default:break;
    }
}
void Engine::Render()
{
	TCODConsole::root->clear();

	//rysuj mape gry
	map->Render();
	//rysuj gniazda na zarowki

	//rysuj gracza
	pl_actor->Render();
	//rysuj zarowki
}