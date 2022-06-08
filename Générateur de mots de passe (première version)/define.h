#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef DEFINE_H
#define DEFINE_H

//ON CREE LA STRUCTURE "MDP" donc mot de passe
typedef struct{
  //LA TAILLE VARIABLE DU MOT DE PASSE
  int taille;
  char texte[255];
  //DIFFERENTES OPTIONS POUR AFINER LA CREATION
  int min;
  int max;
  int chiffre;
  int spec;
}MDP;

extern MDP *init_mdp();

#endif
