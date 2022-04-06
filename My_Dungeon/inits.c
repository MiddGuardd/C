#include "inits.h"

//ON GERE ICI TOUTES LES FONCIONS RELATIVES AU ATTRIBUTIONS MEMOIRES

WARRIOR *init_warrior(){
  WARRIOR *war=malloc(sizeof(WARRIOR));
  war->hp_max = 130;
  war->atk = 100;
  war->def = 65;
  war->spd = 80;

  return war;
}

THIEF *init_thief(){
  THIEF *thief=malloc(sizeof(THIEF));
  thief->hp_max = 90;
  thief->atk = 140;
  thief->def = 30;
  thief->spd = 125;

  return thief;
}

HEALER *init_healer(){
  HEALER *heal=malloc(sizeof(HEALER));
  heal->hp_max = 100;
  heal->atk = 90;
  heal->def = 60;
  heal->spd = 110;

  return heal;
}

PLAYER *init_player(){
  PLAYER *j1=malloc(sizeof(PLAYER));

  //LE JOUEUR CHOISIT SON NOM
  printf("Quel est votre nom?\n");
  scanf(" %s", j1->name);

  //ET SA CLASSE
  printf("Vous êtes un ...\n");
  printf("1: Guerrier\n");
  printf("2: Voleur\n");
  printf("3: Guérisseur\n");
  printf("4: Explication des classes\n");
  scanf(" %d", &j1->classe);

  //ON EXPLIQUE LES CLASSES
  if(j1->classe==4){
    printf("Le guerrier possède beaucoup de PV et de Défense, mais est peu rapide. Attendez-vous à prendre des coups!\n");
    printf("Le voleur tape très fort et très vite mais il est très fragile. Faites attention à votre vie et tout ira bien.\n");
    printf("Le soigneur n'a pas de réelles particularités mis à part le fait qu'il se soigne beaucoup plus que les autres.\n");
  }

  //AU CAS OU LE JOUEUR FAIT LE MALIN ET RENTRE UN NOMBRE > 4
  while(j1->classe>=4){
    printf("Choissisez une classe:\n");
    printf("1: Guerrier\n");
    printf("2: Voleur\n");
    printf("3: Guérisseur\n");
    scanf(" %d", &j1->classe);
    }
  
  return j1;
}

MONSTER *init_monster(int a){
  MONSTER *monstre = malloc(sizeof(MONSTER));

  //LES STATS DES MONSTRES SONT ALEATOIRES
  // a ETANT LE BOOST DE STATS LEUR ETANT DONNE APRES CHAQUE BOSS
  monstre->hp_max = (rand()%(120-80+1)+80)+a;
  monstre->hp = monstre->hp_max;
  monstre->atk = (rand()%(100-75+1)+75)+a;
  monstre->def = (rand()%(50-30+1)+30)+a;
  monstre->spd = (rand()%(120-80+1)+80)+a;
  
  
  return monstre;
}

//MEME FONCTIONNEMENT POUR LES BOSS
BOSS *init_boss(int a){
  BOSS *boss = malloc(sizeof(BOSS));

  boss->hp_max = (rand()%(140-100+1)+100)+a;
  boss->hp = boss->hp_max;
  boss->atk = (rand()%(120-90+1)+90)+a;
  boss->def = (rand()%(75-60+1)+60)+a;
  //CEPENDANT IL ATTAQUE TOUJOURS APRES LE JOUEUR
  boss->spd = 0+a;

  return boss;
}