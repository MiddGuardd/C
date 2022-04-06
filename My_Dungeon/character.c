#include "character.h"


//ON CREE LE JOUEUR CAD ON ATTRIBUE SES STATS EN FONCTION DE LA CLASSE QU'IL A CHOISI
PLAYER *start_game(){
  PLAYER *j1=init_player();

  if(j1->classe==1){ 
      WARRIOR *g = init_warrior();
      j1->hp_max = g->hp_max;
      j1->hp = g->hp_max;
      j1->atk = g->atk;
      j1->def = g->def;
      j1 ->spd = g->spd;
      free(g);
  }

    
  else if(j1->classe == 2){
      THIEF *t=init_thief();
      j1->hp_max = t->hp_max;
      j1->hp = t->hp_max;
      j1->atk = t->atk;
      j1->def = t->def;
      j1 ->spd = t->spd;
      free(t);
    }

    
  else if(j1->classe == 3){
      HEALER *h=init_healer();
      j1->hp_max = h->hp_max;
      j1->hp = h->hp_max;
      j1->atk = h->atk;
      j1->def = h->def;
      j1 ->spd = h->spd;
      free(h);
    }
  
  return j1;
}


//FONCTION QUI PERMET AU JOUER DE SE SOIGNER
int player_heal(PLAYER *j){

  //SI LE JOUEUR JOUE SOIGNEUR IL SE SOIGNE DE 50% DES PV MAX
  if(j->classe == 3){
    printf("Vous récupérez %d points de vie\n", j->hp_max/2);
    
    j->hp += j->hp_max/2;
    if(j->hp > j->hp_max){
      j->hp = j->hp_max;
    }
  }

  //SINON DE 30%
  else{
    printf("Vous récupérez %d points de vie\n", j->hp_max/3);
    j->hp += j->hp_max/3;
    if(j->hp > j->hp_max){
      j->hp = j->hp_max;
    }
  }

  return j->hp;
}

//FONCTION POUR VERIFIER SI LE JOUEUR N'A PLUS DE PV
int is_player_dead(PLAYER *joueur){
 
  if(joueur->hp <= 0){
    return 1;
  }

  else return 0;
}

//AFFICHE JUSTE LES STATISTIQUES DU JOUEUR
void afficher_stats(PLAYER *joueur){
  printf("HP: %d\n", joueur->hp);
  printf("HP MAXIMUM: %d\n", joueur->hp_max);
  printf("ATTAQUE: %d\n", joueur->atk);
  printf("DEFENSE: %d\n", joueur->def);
  printf("VITESSE: %d\n", joueur->spd);
}

//PERMET D'AUGMENTER LES STATISTIQUES DU JOUEUR APRES QU'IL AIT TUE UN MONSTRE
void stats_plus(PLAYER *joueur, int up){

  joueur->hp_max += up;
  joueur->atk += up;
  joueur->def += up;
  joueur->spd += up;
}