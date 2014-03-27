#ifndef BULB_CLASS_HEADER
#define BULB_CLASS_HEADER
class Bulb {
public :
    int x,y; // position on map
    int ch; // ascii code
    TCODColor col; // color
 
    Bulb(int x, int y, int ch, const TCODColor &col);
    void Render() const;
	void SetPos(int x, int y);
};
#endif