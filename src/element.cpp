#include "element.h"

double element_table[10][10] = {
// N     W     E     F     A     P     H     D     S     U
	{1,    1,    1,    1,    1,    1,    1,    1,    0,    1}, //Normal
	{1, -1.5,    1,    2,    0, 0.75,    0, 0.25,    1,  1.5}, //Water
	{1,    1,-1.25,    1,    2, 0.75,    0, 0.25,    1,  0.5}, //Earth
	{1,    0,    2, -1.5,    1, 0.75,    0, 0.25,    1,    2}, //Fire
	{1,    2,    0,    1, -1.5, 0.75,    0, 0.25,    1,    1}, //Air
	{1, 0.25, 0.75, 0.75, 0.75,    0,    0,-1.25, 0.25,   -1}, //Poison
	{1, 0.75, 0.75, 0.75, 0.75, 1.25,   -1,    2,    1,    2}, //Holy
	{1, 0.75, 0.75, 0.75, 0.75,-1.25,    2,   -1,    1,   -1}, //Dark
	{0, 0.25, 0.25, 0.25, 0.25, 0.25,    0,    0,    2, 1.75}, //Spiritual
	{1, 0.25, 0.25, 0.25, 0.25,-1.25,    2,    0,    1,    0}  //Undead
};

Element::Element(){
	_element = ELEMENT_NORMAL;
}

Element::Element(unsigned long element){
	_element = element;
}

double Element::Affect(Element *target){
	double damage_mod = 1;
	double heal = 0;
	for( int x = 0; x < 10; ++x){
		if( _element & 1<<x ){
			for( int y = 0; y < 10; ++y){
				if( target->Get_Element() & 1<<y ){
					if( element_table[x][y] < 0 ){
						heal += element_table[x][y];
					} else {
						damage_mod *= element_table[x][y];
					}
				}
			}
		}
	}
	return damage_mod + heal;
}

unsigned long Element::Get_Element(){ return( _element ); }