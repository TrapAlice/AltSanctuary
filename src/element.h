#ifndef _ELEMENT_H
#define _ELEMENT_H

#define ELEMENT_NORMAL    1<<0
#define ELEMENT_WATER     1<<1
#define ELEMENT_EARTH     1<<2
#define ELEMENT_FIRE      1<<3
#define ELEMENT_AIR       1<<4
#define ELEMENT_POISON    1<<5
#define ELEMENT_HOLY      1<<6
#define ELEMENT_DARK      1<<7
#define ELEMENT_SPIRITUAL 1<<8
#define ELEMENT_UNDEAD    1<<9

class Element{
public:
	Element();
	Element(unsigned long element);
	double Affect(Element*);
	unsigned long Get_Element();
private:
	unsigned long _element : 10;
};

#endif