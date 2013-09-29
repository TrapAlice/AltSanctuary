#include "game.h"
#include "graphic.h"

int main(){
	Game *game = new Game();
	GRAPHIC_INIT();
	game->Start();
	delete game;
}
