#include "libtcod.hpp"
#include "bulb.h"
 
Bulb::Bulb(int x, int y, int ch, const TCODColor &col) :
    x(x),y(y),ch(ch),col(col) {
}
 
void Bulb::Render() const {
    TCODConsole::root->setChar(x,y,ch);
    TCODConsole::root->setCharForeground(x,y,col);
}

void Bulb::SetPos(int x, int y)
{
	this->x = x;
	this->y = y;
}