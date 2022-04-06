#include <stdio.h>
#include <stdlib.h>

#ifndef INITS_H
#define INITS_H

// ON CREE LA STRUCTURE "JOUEUR"
typedef struct{
  char name[255];
  int classe;
  int hp;
  int hp_max;
  int atk;
  int def;
  int spd;
}PLAYER;

// ON DEFINIT NOS TROIS CLASSES JOUABLES ICI

// LE GUERRIER EST PLUS TANKY MAIS MOINS RAPIDE
typedef struct{
  int hp;
  int hp_max;
  int atk;
  int def;
  int spd;
}WARRIOR;

// LE VOLEUR TAPE VITE ET FORT MAIS EST TRES FRAGILE
typedef struct{
  int hp;
  int hp_max;
  int atk;
  int def;
  int spd;
}THIEF;

// LA PARTICULARITE DU SOIGNEUR EST QU'IL SE SOIGNE DE 50% DE SES PV AU LIEU DE 30%
typedef struct{
  int hp;
  int hp_max;
  int atk;
  int def;
  int spd;
}HEALER;

// ON CREE LES MONSTRES (LEURS STATS SERONT ALEATOIRES)
typedef struct{
  int hp;
  int hp_max;
  int atk;
  int def;
  int spd;
}MONSTER;

// ON CREE LES BOSS (TOUS LES 5 ENNEMIS)
typedef struct{
  int hp;
  int hp_max;
  int atk;
  int def;
  int spd;
}BOSS;

extern WARRIOR *init_warrior();
extern THIEF *init_thief();
extern HEALER *init_healer();;
extern PLAYER *init_player();
extern MONSTER *init_monster(int a);
extern BOSS *init_boss(int a);

#endif