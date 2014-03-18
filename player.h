#ifndef PLAYER_CLASS_HEADER
#define PLAYER_CLASS_HEADER
class Player {
public :
    int x,y; // position on map
    int ch; // ascii code
    TCODColor col; // color
 
    Player(int x, int y, int ch, const TCODColor &col);
    void Render() const;
};
#endif