#ifndef _WORLD_H
#define _WORLD_H

#include <memory>

class Character;
class Game;
class Act;

class World{
public:
	World();
	~World();
	Character& Player();
	void       SetPlayer( std::unique_ptr<Character> c );
	void       End();
	Act*       GetCurrentAct();
private:
	std::unique_ptr<Character> _player;
	//Game       *game_;
	Act        *_current_act;
};

#endif