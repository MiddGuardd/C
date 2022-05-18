#include <stdio.h>
#include <stdlib.h>
#include "char_array.h"
int score_j1=0, score_adv=0;

int init_game(void){
  char ordi = ' ';

  while (ordi != 'y' && ordi != 'n')
  {
    printf("Voulez-vous jouer contre l'ordinateur (y/n)?\n");
    scanf("%c", &ordi);
  }

  return ordi == 'y';
}

//ON REGARE SI LE JOUEUR A GAGNE
int test_win(char (*grid)[3], char c){
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(grid[i][j]==c){
        if(grid[i][j]==grid[i][j+1] && grid[i][j]==grid[i][j+2]){
          return 1;
          }
        else if(grid[i][j]==grid[i+1][j] && grid[i][j]==grid[i+2][j]){
          return 1;
        }
        else if(grid[i][j]==grid[i+1][j+1] && grid[i][j]==grid[i+2][j+2]){
          return 1;
        }
        else if(j==2 && grid[i][j]==grid[i+1][j-1] && grid[i][j]==grid[i+2][j-2]){
          return 1;
        }
        else return 0;
      }
    }
  }
}

//ON FAIT JOUER LE JOUEUR (TOUT LE TEMPS UP)
int tour_j1(char (*grid)[3], char c, char d){ 
  int x,y;
  
  printf("Tour du joueur 1\n");
  printf("Où voulez-vous jouer?\n");
  scanf(" %d %d", &x, &y);
  
  if(test_case(grid, c, x, y)==0 || test_case(grid, d, x, y)==0){
    printf("ERREUR\n");
    return 2;
  }
  update_grid(grid, c ,x ,y);
  display_grid(grid);

  if(test_win(grid, c)==1){
    printf("Victoire du joueur 1\n");
    score_j1+=1;
    printf("J1:%d J2:%d\n",score_j1, score_adv);
    return 1;
  }

  return 0;
}

//ON FAIT JOUER LE JOUEUR 2 (QUE EN JCJ)
int tour_j2(char (*grid)[3], char c, char d){
  int x,y;

  printf("Tour du joueur 2:\n");
  printf("Où voulez-vous jouer?\n");
  scanf(" %d %d", &x, &y);

  if(test_case(grid, c, x, y)==0 || test_case(grid, d, x, y)==0){
    printf("ERREUR\n");
    return 2;
  }
  update_grid(grid, d ,x ,y);
  display_grid(grid);

  if(test_win(grid, d)==1){
    printf("Victoire du joueur 2\n");
    score_adv+=1;
    printf("J1:%d J2:%d\n",score_j1, score_adv);
    return 1;
  }

  return 0;
}

//ON FATI JOUER L'ORDINATEUR (QUE EN PVE)
int tour_bot(char (*grid)[3], char c){
  int x, y;

  printf("Tour de l'ordinateur:\n");
  x=(rand()%(2-0+1)+0);
  y=(rand()%(2-0+1)+0);

  while(test_case(grid, c, x, y)==0 || test_case(grid, '-', x, y)==0){
    x=(rand()%(2-0+1)+0);
    y=(rand()%(2-0+1)+0);
  }

  update_grid(grid, '-' ,x ,y);
  printf("%d %d\n",x,y);
  display_grid(grid);

  if(test_win(grid, '-')==1){
    printf("Victoire de l'ordinateur\n");
    score_adv+=1;
    printf("J1:%d J2:%d\n",score_j1, score_adv);
    return 1;
  }

  return 0;
}

//ON RELANCE UNE PARTIE
int reset_game(char (*grid)[3]){
  char c;

  printf("Rejouer (y/n)?\n");
  scanf(" %c", &c);

  if(c=='y'){
    init_grid(grid);
    return 0;
  }
  else if(c=='n'){
    return 1;
  }
}
