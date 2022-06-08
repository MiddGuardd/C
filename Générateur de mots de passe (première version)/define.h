#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef DEFINE_H
#define DEFINE_H

typedef struct{
  int taille;
  char texte[255];
  int min;
  int max;
  int chiffre;
  int spec;
}MDP;

extern MDP *init_mdp();

#endif