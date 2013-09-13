#ifndef _INVENTORY_H
#define _INVENTORY_H

#include <string>

class Renderer;

class Inventory{
public:
	Inventory();
	void        Render( Renderer *r );
	int         GetItemId( char *input );
	std::string GetItem( int pos );
	void        AddItem( std::string item, int x, int y );
private:
	std::string items_[4][4];
};

#endif
