#include "sokoban.h"

void move(char **board,char dir, positio *p, char user)
{
        if (dir=='d')
        {
		if (board[p->use_i][(p->use_j)+1]=='X')
		{
			move_use_box_d(board, dir, p, user);
			return;
		}
		else if(((p->use_j)+1)==9)
		{
			printf("Vous êtes dans un mur !\n");
			return;
		}
		else if(((p->use_j)+1)==p->vic_j && p->use_i == p->vic_i)
		{
			printf("Vous ne pouvez pas passer par là\n");
			return;
		}
		else
		{
			board[p->use_i][p->use_j]=' ';
			p->use_j= (p->use_j) +1;
			board[p->use_i][p->use_j]=user;
		}
        }
	else if(dir=='a')
	{
		if (board[p->use_i][(p->use_j)-1]=='X')
                {
                        move_use_box_g(board, dir, p, user);
			return;
                }
                else if(((p->use_j)-1)==0)
                {
                        printf("Vous êtes dans un mur !\n");
			return;
                }
		else if(((p->use_j)-1)==p->vic_j && p->use_i == p->vic_i)
		{
			printf("Vous ne pouvez pas passer par là\n");
			return;
		}
		else
		{
	                board[p->use_i][p->use_j]=' ';
        	        p->use_j= (p->use_j) -1;
                	board[p->use_i][p->use_j]=user;
		}
        }
	else if(dir=='w')
	{
		if (board[(p->use_i)-1][p->use_j]=='X')
                {
                        move_use_box_h(board, dir, p, user);
			return;
                }
                else if(((p->use_i)-1)==0)
                {
                        printf("Vous êtes dans un mur !");
			return;
                }
		else if(((p->use_i)-1)==p->vic_i && p->use_j == p->vic_j)
		{
			printf("Vous ne pouvez pas passer par là\n");
			return;
		}
		else
		{
                	board[p->use_i][p->use_j]=' ';
                	p->use_i= (p->use_i)-1;
                	board[p->use_i][p->use_j]=user;
		}
        }
	else if(dir=='s')
        {
                if (board[(p->use_i)+1][p->use_j]=='X')
                {
                        move_use_box_b(board, dir, p, user);
			return;
                }
                else if(((p->use_i)+1)==9)
                {
                        printf("Vous êtes dans un mur !\n");
			return;
                }
		else if(((p->use_i)+1)==p->vic_i && p->use_j == p->vic_j)
		{
			printf("Vous ne pouvez pas passer par là\n");
			return;
		}
		else
		{
                	board[p->use_i][p->use_j]=' ';
                	p->use_i= (p->use_i)+1;
                	board[p->use_i][p->use_j]=user;
		}
        }
	else
	{
		printf("Mauvaise commande");
		return;
	}

display_board(board);
}
