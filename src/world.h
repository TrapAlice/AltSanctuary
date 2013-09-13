#ifndef _WORLD_H
#define _WORLD_H

class Character;
class Game;

class World{
public:
	World(Game *g);
	~World();
  Character* Player();
  void       SetPlayer( Character *c );
	void       End();
private:
	Character  *player_;
	Game       *game_;
};

#endif