#include <stdio.h>
#include "char_array.h"
#include "game.h"


int main(void) {
  
  //VARIABLES
  char tab[3][3]={{'O','O','O'}, {'O','O','O'}, {'O','O','O'}};
  int j1=0, j2=0, ordi=0;
  char char_j1, char_j2;

  //VARIABLE POUR VOIR SI ON FAIT DU JCJ OU PAS
  int deb=init_game(tab); 
  
  //CODE
  printf("Début de la partie...\n");
  
  init_grid(tab);

  if(deb==0){
    printf("Joueur 1, veuillez choisir votre signe:\n");
    scanf(" %c", &char_j1);
    printf("Joueur 2, veuillez choisir votre signe:\n");
    scanf(" %c", &char_j2);
    
    while(1){
      if(j1==0 && j2==0){
        j1=tour_j1(tab, char_j1, char_j2);
      }
      if(j1==0 && j2==0){
        j2=tour_j2(tab, char_j1, char_j2);
      }
      else{
        j1=reset_game(tab);
        j2=j1;
        if(j1==1) return 0;
        }
    }
  }

  else if(deb==1){
    printf("Joueur 1, veuillez choisir votre signe:\n");
    scanf(" %c", &char_j1);
    
    while(1){
      if(j1==0 && ordi==0){
        j1=tour_j1(tab, char_j1, '-');
      }
      if(j1==0 && ordi==0){
        ordi=tour_bot(tab, char_j1);
      }      
      else{
        j1=reset_game(tab);
        ordi=j1;
        if(j1==1) return 0;
        }
    }
  }
  
  else{
    printf("Erreur\n");
    return 0;
    }
}
