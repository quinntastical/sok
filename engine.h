#ifndef ENGINE_CLASS_HEADER
#define ENGINE_CLASS_HEADER
#include "libtcod.hpp"
#include "map.h"
#include "player.h"
#include "bulb.h"

class Engine {
public:
    TCODList<Player *> pl_actor_list;
	TCODList<Bulb *> bulb_actor_list;
    Player *pl_actor;
	Bulb *bulb_actor;
    Map *gameArea;
 
    Engine();
    ~Engine();
    void Update();
    void Render();
};
 
extern Engine engine;
#endif