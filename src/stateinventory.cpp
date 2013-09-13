#include "stateinventory.h"
#include "renderer.h"
#include "inventory.h"
#include "character.h"
#include "world.h"

void State_Inventory::Render(World *w, Renderer *r){
	r->prints(0, 0, "+-----------------------------------------------------------------------------+");
	w->Player()->Inv()->Render(r);
}

void State_Inventory::Update(Stack<iGameState*> *s, World *w, char c){
	int item_id;
	item_id = w->Player()->Inv()->GetItemId(&c);
	
	if( item_id == -1 ){
		s->Pop();
	}
	if( item_id == -2 ){
	//Invalid Position
		return;
	}
}