#include "libtcod.hpp"
#include "engine.h"
#include "map.h"
#include "player.h"

Engine::Engine()
{
	TCODConsole::setCustomFont("font.png", TCOD_FONT_LAYOUT_ASCII_INROW,16,16);
	TCODConsole::initRoot(50,25,"sok",false);

	gameArea = new Map(50,20); // najpierw za³aduj mapê

	pl_actor = pl_actor_list.get(0);

    //actors.push(new Actor(60,13,'@',TCODColor::yellow));
    
}
Engine::~Engine()
{
	pl_actor_list.clearAndDelete();
	bulb_actor_list.clearAndDelete();
	delete gameArea;
}

void Engine::Update()
{
	TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL);
    switch(key.vk) {
        case TCODK_UP : 
			if (gameArea->map->isWalkable(pl_actor->x,pl_actor->y-1)) {
                pl_actor->y--;   
            }
        break;
        case TCODK_DOWN : 
            if (gameArea->map->isWalkable(pl_actor->x,pl_actor->y+1)) {
                pl_actor->y++;
            }
        break;
        case TCODK_LEFT : 
            if (gameArea->map->isWalkable(pl_actor->x-1,pl_actor->y)) {
                pl_actor->x--;
				
            }
        break;
        case TCODK_RIGHT : 
            if (gameArea->map->isWalkable(pl_actor->x+1,pl_actor->y)) {
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
	gameArea->Render();
	//rysuj gniazda na zarowki

	//rysuj gracza
	pl_actor->Render();
	//rysuj zarowki
	for (Bulb **iterator=bulb_actor_list.begin(); 
    iterator != bulb_actor_list.end(); iterator++) {
    (*iterator)->Render();
}
}