#include "define.h"

//DIFFERENTES FONCTIONS QUI VONT PERMETTRE DE DECIDER LES DIFFERENTES COMPOSANTES DE NOTRE MOT DE PASSE (MAJUSCULES/MINUSCULES/CHIFFRES/CARACTERES SPECIAUX

void min(MDP *mot){
  char test;
    printf("Votre mot de passe doit-il contenir des lettres minuscules ? (y/n)\n");
    scanf(" %c", &test);

    if(test=='y') mot->min = 1;
    else mot->min = 0;
}

void max(MDP *mot){
  char test;

    printf("Votre mot de passe doit-il contenir des lettres majuscules ? (y/n)\n");
    scanf(" %c", &test);

    if(test=='y') mot->max = 1;
    else mot->max = 0;
}

void chiffre(MDP *mot){
  char test;

  printf("Votre mot de passe doit-il contenir des chiffres ? (y/n)\n");
    scanf(" %c", &test);
  
    if(test=='y') mot->chiffre = 1;
    else mot->chiffre = 0;
}

void spec(MDP *mot){
  char test;

  printf("Votre mot de passe doit-il contenir des caractères spéciaux? (y/n)\n");
    scanf(" %c", &test);

    if(test=='y') mot->spec = 1;
    else mot->spec = 0;
}

// LA FONCTION PERMETTANT D'INITIALISER LA STRUCTURE DU MOT DE PASSE
// L'UTILISATEUR Y DEFINIT LA TAILLE SOUHAITEE

MDP *init_mdp(){
  MDP *mot=malloc(sizeof(MDP));
  printf("La taille de votre mot de passe ?\n");
  scanf(" %d", &mot->taille);

  min(mot);
  max(mot);
  chiffre(mot);
  spec(mot);
  
  return mot;
}
