#include "inits.h"

#ifndef CHARACTER_H
#define CHARACTER_H

extern PLAYER *start_game();
extern int player_heal(PLAYER *j);
extern int is_player_dead(PLAYER *joueur);
void afficher_stats(PLAYER *joueur);
extern void stats_plus(PLAYER *joueur, int up);

#endif