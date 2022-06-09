#include <stdio.h>
#include <stdlib.h>

char init='O';

//AFFICHE LA GRILLE
void display_grid(char (*grid)[3]){
     for(int j=0; j<3; j++){
       printf("_____________\n");
       printf("\n| %c | %c | %c |\n", grid[j][0], grid[j][1], grid[j][2]);
     }
  printf("_____________\n");
}

//RESET LA GRILLE
void init_grid(char (*grid)[3]){
 for(int i=0; i<3; i++){
   for(int j=0; j<3; j++){
     grid[i][j]='O';
   }
 }
}

//JOUER SUR UNE CASE
void update_grid(char (*grid)[3], char c, int x, int y){
   grid[x][y]=c;
}

//VERIFIER SI LA CASE EST NON-UTILISEE
int test_case(char (*grid)[3], char c, int x, int y){
     return grid[x][y]!=c;
}
