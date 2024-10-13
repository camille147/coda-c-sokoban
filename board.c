#include "sokoban.h"

char ** init_board()
{
	char ** board;
	int i;
	int j;

	i= 0;
	board = malloc(10 * sizeof(*board)); //10 lignes

	while(i<10)
	{
		board[i] = malloc(10 *sizeof(char)); //chaque ligne=10 colonnes
		j = 0;
		while(j<10)
		{
			board[i][j] = ' '; //affiche case vide dans terminal
			j++;
		}
		i++;
	}
	return board;
}


void display_board(char **board)
{
	int i = 1;
	printf("\n");
	printf("##########\n");
	while (i<9)
	{
		printf("#%c%c%c%c%c%c%c%c#\n", board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6], board[i][7], board[i][8]);
		i++;
	}
	printf("##########\n");
	printf("\n");
}

void position(char **board, positio * p, char user)
{
	srand(time(NULL));
	//arret
	p->stop=0;

	//victory
	p->vic_i =1 + rand() % 7;
	p->vic_j =1 + rand() % 7;
	board[p->vic_i][p->vic_j]= '.';

	//box
	p->box_i = 2 + rand() % 5;
	p->box_j = 2 + rand() % 5;
	while (p->vic_i == p->box_i && p->vic_j == p->box_j )
	{
		p->box_i = 2 + rand() % 5;
        	p->box_j = 2 + rand() % 5;
	}
	board[p->box_i][p->box_j]='X';

	//user
	p->use_i = 1 + rand() % 7;
	p->use_j = 1 + rand() % 7;
	while((p->use_i == p->vic_i && p->use_j == p->vic_j)|| (p->use_i == p->box_i && p->use_j == p->box_j))
	{
		p->use_i = 1 + rand() % 7;
        	p->use_j = 1 + rand() % 7;
	}
	board[p->use_i][p->use_j]= user;
	display_board(board);
}
