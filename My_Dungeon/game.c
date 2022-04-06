#include "game.h"

// GERE LE CD DU HEAL (SINON TROP FACILE A ABUSER), IL EST DE DEUX COMBATS
int cooldown=0;
//TOUTES LES 5 BATAILLES LE JOUEUR VA AFFRONTER UN BOSS
int battle_count=0;
//UNE FOIS LE BOSS VAINCU LES STATISTIQUES DE TOUS LES MONSTRES VONT AUGMENTER
int monster_boost=0;

// VERIFIE SI LE MONSTRE EST MORT
int is_monster_dead(MONSTER *monstre){
  if(monstre->hp <= 0){
    printf("Bravo! Vous avez vaincu le monstre!\n");
    return 1;
  }

  else return 0;
}

// IDEM POUR LE BOSS 
int is_boss_dead(BOSS *boss){
  if(boss->hp <= 0){
    printf("Félicitations ! Vous avez battu le boss !\n");
    return 1;
  }

  else return 0;
}

// LA GROSSE FONCTION DU CODE QUI GERE LES BATAILLES
int battle(PLAYER *joueur){
  int dégâts;
  //ON DECIDE ICI DE LA VALEUR SELON LAQUELLE NOS STATS VONT AUGMENTER APRES CHAQUE   VICTOIRE (+1 PAR MONSTER ET +3 PAR BOSS)
  int up_monstre=1, up_boss=3;
  
  MONSTER *monstre = init_monster(monster_boost);
  BOSS *boss = init_boss(monster_boost);

  
  while(1){

    //TANT QU'ON A PAS BATTU 5 MONSTRES ON CONTINUE D'EN RENCONTRER
    if(battle_count<5){
      //LE JOUEUR EST PLUS RAPIDE
      if(joueur->spd >= monstre->spd){
        printf("%s attaque:\n", joueur->name);
        //ON CALCULE LES DEGATS DU JOUEUR
        dégâts = joueur->atk-monstre->def;
        printf("Le monstre prends %d points de dégâts\n", dégâts);
        // LE MONSTER PERD DE LA VIE
        monstre->hp-=dégâts;
        printf("Il reste au monstre %d PVs\n", monstre->hp);
        //SI LE MONSTRE MEURT:
        if(is_monster_dead(monstre) == 1){
          printf("Vous gagnez %d points dans toutes vos statistiques !\n", up_monstre);
          // ON AUGMENTE LES STATS DU JOUEUR
          stats_plus(joueur, up_monstre);
          // ON DIMINUE LE CD DU HEAL
          if(cooldown > 0) cooldown-=1;
          //ON S'APPROCHE DE LA BOSS BATTLE
          battle_count+=1;
          //ON ARRETE LE COMBAT
          return 1;
        }
  
        printf("Le monstre attaque\n");
        //MEME PRINCIPE ON CALCULE LES DEGATS DU MONSTRE
        dégâts = monstre->atk-joueur->def;
        printf("%s prends %d points de dégâts\n", joueur->name, dégâts);
        //ON BAISSE LA VIE DU JOUEUR
        joueur->hp -= dégâts;
        printf("Il vous reste %d points de vie\n", joueur->hp);
        //SI LE JOUEUR MEURT, ON ARRETE LE COMBAT
        if(is_player_dead(joueur) == 1){
          printf("GAME OVER\n");
          return 1;
        }
      }
  
      //LE MONSTRE EST PLUS RAPIDE
      else if(monstre->spd >= joueur->spd){
        printf("Le monstre attaque\n");
        dégâts = monstre->atk-joueur->def;
        printf("%s prends %d points de dégâts\n", joueur->name, dégâts);
        joueur->hp -= dégâts;
        printf("Il vous reste %d points de vie\n", joueur->hp);
        //SI LE JOUEUR MEURT, ON ARRETE LE COMBAT
        if(is_player_dead(joueur) == 1){
          printf("GAME OVER\n");
          return 1;
        }
  
        printf("%s attaque:\n", joueur->name);
        dégâts = joueur->atk-monstre->def;
        printf("Le monstre prends %d points de dégâts\n", dégâts);
        monstre->hp-=dégâts;
        printf("Il reste au monstre %d PVs\n", monstre->hp);
        //SI LE MONSTRE MEURT, ON ARRETE LE COMBAT
        if(is_monster_dead(monstre) == 1){
          printf("Vous gagnez %d points dans toutes vos statistiques !\n", up_monstre);
          stats_plus(joueur, up_monstre);
          if(cooldown > 0) cooldown-=1;
          battle_count+=1;
          return 1;
        }
      }
    }

    //LA BATAILLE CONTRE LES BOSS C'EST LE MEME PRINCIPE MAIS LE BOSS TAPE TOUJOURS EN DERNIER (POUR EQUILIBRER)

      //TOUTES LES 5 COMBATS = COMBAT DE BOSS
    else if(battle_count == 5){
        printf("%s attaque:\n", joueur->name);
        dégâts = joueur->atk-boss->def;
        printf("Le boss prends %d points de dégâts\n", dégâts);
        boss->hp-=dégâts;
        printf("Il reste au boss %d PVs\n", boss->hp);
        //SI LE BOSS MEURT:
        if(is_boss_dead(boss) == 1){
          printf("Vous gagnez %d points dans toutes vos statistiques !\n", up_boss);
          stats_plus(joueur, up_boss);
          //ON SOIGNE COMPLETEMENT LE JOUEUR
          joueur->hp = joueur->hp_max;
          //ON RESET LE CD DU HEAL
          cooldown=0;
          // ON REMET LE COMPTEUR DE BATAILLES A ZERO
          battle_count=0;
          //ON AUGMENTE LES STATS DE TOUS LES MONSTRES
          monster_boost += 5;
          //ON ARRETE LE COMBAT
          return 1;
        }
        printf("Le boss attaque\n");
          dégâts = boss->atk-joueur->def;
          printf("%s prends %d points de dégâts\n", joueur->name, dégâts);
          joueur->hp -= dégâts;
          printf("Il vous reste %d points de vie\n", joueur->hp);
          //SI LE JOUEUR MEURT, ON ARRETE LE COMBAT
          if(is_player_dead(joueur) == 1){
            printf("GAME OVER\n");
            return 1;
          }
    }
  }
  
  free(boss);
  free(monstre);
}

// C'EST LE MENU PRINCIPAL DU JEU
int choix(){
  int choix=0;
  
  printf("Que souhaitez-vous faire?\n");
  //ON DECIDE DE LANCER UN COMBAT
  printf("1: Avancer à la pièce suivante ?\n");
  //SI LA PROCHAINE BATAILLE EST CONTRE UN BOSS ON PREVIENT LE JOUEUR
  if(battle_count == 5){
    printf("Vous sentez venir un grand danger...\n");
  }
  //ON DECIDE DE SE HEAL
  printf("2: Vous reposer?\n");
  //OU D'AFFICHER LES STATISTIQUES
  printf("3: Afficher vos statistiques?\n");
  
  scanf(" %d", &choix);

  return choix;
}

void play(PLAYER *joueur){
  int action = choix();
  //SI LE JOUEUR VEUT SE BATTRE ON LANCE LE COMBAT
  if(action == 1){
    while(battle(joueur) != 1);
  }

  //SI LE JOUEUR VEUT SE SOIGNER
  if(action == 2){
    //ET SI LE SOIN EST DISPONIBLE
    if(cooldown==0){
      //ALORS ON LE SOIGNE ET ON AFFICHE SES STATS
      player_heal(joueur);
      afficher_stats(joueur);
      //ET ON REMET LE CD DU HEAL AU MAX
      cooldown=2;
      }
      //SI LE HEAL N'EST PAS DISPONIBLE ON AFFICHE UN MESSAGE D'ERREUR
    else{
      printf("Vous devez attendre %d tours avant de pouvoir vous soigner à nouveau\n", cooldown);
      }
  }

  //SI LE JOUEUR VEUT AFFICHER SES STATISTIQUE ON LES AFFICHE
  if(action == 3){
    afficher_stats(joueur);
  }
}