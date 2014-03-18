#ifndef MAP_CLASS_HEADER
#define MAP_CLASS_HEADER

struct Tile {
    bool canWalk; // can we walk through this tile?
    Tile() : canWalk(true) {}
};
 
class Map {
public :
    int width,height;
 
    Map(int width, int height);
    ~Map();
    bool isWall(int x, int y) const;
    void Render() const;
protected :
    Tile *tiles;
 
    void setWall(int x, int y);
};
#endif