#include "fonctions.h"

char gen_min(){
  char renv;
  char min[26]="abcdefghijklmnopqrstuvwxyz";

  renv = min[rand()%(26-1)];

  return renv;
}

char gen_max(){
  char renv;
  char max[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  renv = max[rand()%(26-1)];

  return renv;
}

char gen_chif(){
  char renv;
  char chif[10]="0123456789";

  renv = chif[rand()%(10-1)];

  return renv;
}

char gen_spec(){
  char renv;
  char spec[14]="%_-!$^&#()[]=@";

  renv = spec[rand()%(14-1)];

  return renv;
}

void gen(MDP *mot){

  
  for(int i=0; i<mot->taille; i++){
    int random=rand()%(4-0+1)+0;

    if(random==1 && mot->min==1) mot->texte[i]=gen_min();
    else if(random==2 && mot->max==1) mot->texte[i]=gen_max();
    else if(random==3 && mot->chiffre==1) mot->texte[i]=gen_chif();
    else if(random==4 && mot->spec==1)mot->texte[i]=gen_spec();
    else i--;
  }
}

void print_mdp(MDP *mot){
  gen(mot);
  for(int i=0; i<mot->taille; i++){
    printf("%c", mot->texte[i]);
  }
  printf("\n");
}