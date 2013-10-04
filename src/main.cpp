#include "game.h"
#include "graphic.h"
#include "renderer.h"
#include "world.h"
#include "input.h"

#include <memory>

int main(){
	std::unique_ptr<Renderer> r(new Renderer());
	std::unique_ptr<World> w(new World());
	std::unique_ptr<Input> i(new Input());
	Game game(r, w, i);
	GRAPHIC_INIT();
	game.Start();
}
