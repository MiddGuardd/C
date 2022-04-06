#include <stdio.h>
#include "game.h"

int main(void) {
  
//ON CREE LE JOUEUR
PLAYER *j1=start_game();

//LA BOUCLE DU JEU
while(1){
  play(j1);
  //SI LE JOUEUR MEURT ON ARRETE LE JEU
  if(is_player_dead(j1) == 1) return 0;
}
 
  free(j1);
  return 0;
}