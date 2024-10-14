#include "sokoban.h"

void move_use_box_d(char **board, char dir, positio *p, char user)
{
	if ((board[(p->box_i)-1][(p->box_j)+1]=='.' && ((p->box_j)+2)==9) || (board[(p->box_i)+1][(p->box_j)+1]=='.' && ((p->box_j)+2)==9))
	{
		board[p->use_i][p->use_j]=' ';
                p->use_j= (p->use_j) +1;
		p->box_j= (p->box_j)+1;
                board[p->use_i][p->use_j]=user;
		board[p->box_i][p->box_j]='X';
	}
	else if (((p->box_j)+1)==p->vic_j && p->box_i == p->vic_i)
	{
		printf("C'est gagné !\n");
		p->stop=(p->stop)+1;
		exit (0);
	}
	else if (((p->box_j)+2)==9)
        {
                printf("C'est perdu !\n");
                p->stop=(p->stop)+1;
                exit (0);
        }
	else
        {
                board[p->use_i][p->use_j]=' ';
                p->use_j= (p->use_j) +1;
                p->box_j= (p->box_j)+1;
                board[p->use_i][p->use_j]=user;
                board[p->box_i][p->box_j]='X';
        }
display_board(board);
}
