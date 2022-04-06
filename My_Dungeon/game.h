#include "character.h"

#ifndef GAME_H
#define GAME_H

extern int is_monster_dead(MONSTER *monstre);
extern int battle(PLAYER *joueur);
extern int choix();
void play(PLAYER *joueur);

#endif