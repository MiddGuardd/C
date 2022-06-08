#include "fonctions.h"

int main(void) {
  MDP *mdp=init_mdp();

  print_mdp(mdp);
  
  free(mdp);
  
  return 0;
}