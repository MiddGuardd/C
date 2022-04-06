#ifndef GAME_H
#define GAME_H
extern int init_game(char (*grid)[3]);
extern int test_win(char (*grid)[3], char c);
extern int tour_j1(char (*grid)[3], char c, char d);
extern int tour_j2(char (*grid)[3], char c, char d);
extern int tour_bot(char (*grid)[3], char c);
int reset_game(char (*grid)[3]);
#endif