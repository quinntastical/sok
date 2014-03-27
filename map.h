#ifndef MAP_CLASS_HEADER
#define MAP_CLASS_HEADER
#include <libtcod.hpp>
 
class Map {
public:
    int width,height;
	TCODMap *map;
    Map(int width, int height);
    ~Map();
    void Render() const;
};
#endif