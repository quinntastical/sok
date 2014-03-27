#include "libtcod.hpp"
#include "player.h"
 
Player::Player(int x, int y, int ch, const TCODColor &col) :
    x(x),y(y),ch(ch),col(col) {
}
 
void Player::Render() const {
    TCODConsole::root->setChar(x,y,ch);
    TCODConsole::root->setCharForeground(x,y,col);
}

void Player::SetPos(int newX, int newY)
{
	this->x = newX;
	this->y = newY;
}