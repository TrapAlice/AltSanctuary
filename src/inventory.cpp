#include "inventory.h"
#include "renderer.h"
#include "dbg.h"

Inventory::Inventory(){
	items_[2][3] = "Sword";
}

void Inventory::Render(Renderer *r){
	r->prints(10, 1, "1");
	r->prints(20, 1, "2");
	r->prints(30, 1, "3");
	r->prints(40, 1, "4");
	r->prints(0,  3, "Q");
	r->prints(0,  6, "W");
	r->prints(0,  9, "E");
	r->prints(0, 12, "R");
	
	for( int y=0; y < 4; y++ ){
		for( int x=0; x < 4; x++ ){
			r->prints(x*10 + 10, y*3 + 3, items_[x][y]);	
		}
	}
}

int Inventory::GetItemId(char *input){
	int x, y, a, b;
	bool flag=0;

	a = input[0]-'1';
	
	if( a > 3 ){
		flag=1;
		switch( a ){
			case 'q':
			case 'Q':
				a = 0;
				break;
			case 'w':
			case 'W':
				a = 1;
				break;
			case 'e':
			case 'E':
				a = 2;
				break;
			case 'r':
			case 'R':
				a = 3;
				break;
			case 'a':
				return( -1 );
			default:
				return( -2 );
		}
	}
	b= input[1]-'1';
	if( !flag ){
		switch( b ){
			case 'q':
			case 'Q':
				b = 0;
				break;
			case 'w':
			case 'W':
				b = 1;
				break;
			case 'e':
			case 'E':
				b = 2;
				break;
			case 'r':
			case 'R':
				b = 3;
				break;
			default:
				return( -2 );
		}
	}

	if( flag ){
		x=b;
		y=a;
	} else {
		x=a;
		y=b;
	}

	if( x < 0 || x > 3 ||
	    y < 0 || y > 3 ){
		return( -2 );
	}

	return( x+(y*4) );	
}

std::string Inventory::GetItem(int pos){
	std::string item = items_[pos%4][pos/4];
	items_[pos%4][pos/4].clear();
	return item;
} 
