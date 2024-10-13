#ifndef __SOKOBAN__
#define __SOKOBAN__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
// board.c
char ** init_board();
void display_board(char **board);
struct s_pos
{
	int vic_i;
	int vic_j;
	int box_i;
	int box_j;
	int use_i;
	int use_j;
	int stop;
};               // ATTENTION: mettre les fonctions appelant la structure après sa création

typedef struct s_pos positio;
void position(char **board, positio *p, char user);

void move(char **board, char dir, positio *p, char user);
void move_use_box_d(char **board, char dir, positio *p, char user);

void move_use_box_g(char **board, char dir, positio *p, char user);
void move_use_box_b(char **board, char dir, positio *p, char user);
void move_use_box_h(char **board, char dir, positio *p, char user);
#endif
