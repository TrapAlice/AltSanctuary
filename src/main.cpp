#include "game.h"
#include "graphic.h"
#include "input.h"
#include "renderer.h"
#include <memory>

int main(){
	std::unique_ptr<Renderer> r(new Renderer());
	std::unique_ptr<Input> i(new Input());
	Game game(r, i);
	GRAPHIC_INIT();
	game.Start();
}
