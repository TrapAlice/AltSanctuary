#include "entity.h"

void ranger_poison(double *d, Entity* attacker, Entity* defender, int power){
	defender->TakeDamage(power*0.72); 
}

void ranger_healtier1(double *d, Entity* attacker, Entity* defender, int x){
	defender->TakeDamage(-100);
}

void ranger_healtier2(double *d, Entity* attacker, Entity* defender, int x){
	defender->TakeDamage(-200);
}

void ranger_healtier3(double *d, Entity* attacker, Entity* defender, int x){
	defender->TakeDamage(-300);
}

void ranger_healtier4(double *d, Entity* attacker, Entity* defender, int x){
	defender->TakeDamage(-400);
}

void ranger_cripplingshot(double *damage, Entity* attacker, Entity* defender, int x){
	*damage /= 2;
}

void ranger_preparation(double *damage, Entity* attacker, Entity* defender, int x){
	*damage *= 1.5;
}
