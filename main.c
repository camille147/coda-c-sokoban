#include "sokoban.h"

int main()
{
	char **board;
	char user='o';
	char dir;
	int i = 0;
	positio p;
	board = init_board();
	position(board,&p, user);

	while(p.stop==0)
	{
		printf("Joueur: %d, %d\nBoite: %d, %d\n Victoire: %d, %d\n", p.use_i, p.use_j, p.box_i, p.box_j, p.vic_i, p.vic_j);
		printf("Choisissez un mouvement: haut(w), bas(s), gauche(a), droite(d)\n");
		scanf(" %c", &dir);
		move(board, dir, &p, user);
	}
	for (i = 0; i < 10; i++)
	{
		free(board[i]);
	}
	free(board);
	return 0;
}
