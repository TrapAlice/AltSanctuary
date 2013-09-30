#ifndef _WORLD_H
#define _WORLD_H

class Character;
class Game;
class Act;

class World{
public:
	World(Game *g);
	~World();
	Character* Player();
	void       SetPlayer( Character *c );
	void       End();
	Act*       GetCurrentAct();
private:
	Character  *player_;
	Game       *game_;
	Act        *_current_act;
};

#endif