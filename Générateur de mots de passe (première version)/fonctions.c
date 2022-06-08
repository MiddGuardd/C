#include "fonctions.h"

// ON CREE DES "TABLES" CONTENANT LES DIFFERENTS CARACTERES POUVANT ETRE UTILISES LORS DE LA GENERATION DU MOT DE PASSE
// CHAQUE FONCTION VA RENVOYER UN CARACTERE ALEATOIRE DE LA TABLE

char gen_min(){
  char renv;
  char min[26]="abcdefghijklmnopqrstuvwxyz";

  renv = min[rand()%(25-0+1)+0];

  return renv;
}

char gen_max(){
  char renv;
  char max[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  renv = max[rand()%(25-0+1)+0];

  return renv;
}

char gen_chif(){
  char renv;
  char chif[10]="0123456789";

  renv = chif[rand()%(9-0+1)+0];

  return renv;
}

char gen_spec(){
  char renv;
  char spec[14]="%_-!$^&#()[]=@";

  renv = spec[rand()%(13-0+1)+0];

  return renv;
}

// LA FONCTION PRINCIPALE QUI PERMET LA GENERATION

void gen(MDP *mot){

  
  for(int i=0; i<mot->taille; i++){
    // ON DECIDE ALEATOIREMENT LA NATURE DE CHAQUE CARACTRE DU MOT DE PASSE (SI C'EST UN CHIFFRE, UNE LETTRE, ETC...)
    int random=rand()%(4-0+1)+0;
    
    // A CHAQUE FOIS ON REGARDE SI L'UTLISATEUR SOUHAITE BIEN QU'IL Y AIT CETTE CATEGORIE DE CARACTERES DANS SON MDP
    if(random==1 && mot->min==1) mot->texte[i] = gen_min();
    else if(random==2 && mot->max==1) mot->texte[i] = gen_max();
    else if(random==3 && mot->chiffre==1) mot->texte[i] = gen_chif();
    else if(random==4 && mot->spec==1)mot->texte[i] = gen_spec();
    // ON REFAIT UN TOUR DE BOUCLE SINON (EXEMPLE: SI ALEATOIREMENT LE CARACTERE N°5 EST CENSE ETRE UN CHIFFRE MAIS QUE L'UTILISATEUR NE SOUAHITE PAS
    // DE CHIFFRES DANS SON MDP ALORS ON REFAIT UN TOUR DE BOUCLE ET ON "TIRE" A NOUVEAU UNE CATEGORIE DE CARACTERES)
    else i--;
  }
}
// ON AFFICHE TOUT SIMPLEMENT LE MOT DE PASSE
void print_mdp(MDP *mot){
  gen(mot);
  for(int i=0; i<mot->taille; i++){
    printf("%c", mot->texte[i]);
  }
  printf("\n");
}
