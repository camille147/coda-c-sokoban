# Makefile

NAME = sokoban 

SRCS = main.c \
	board.c\
	moves.c\
	move_u_b_d.c\
	move_u_b_g.c\
	move_u_b_h.c\
	move_u_b_b.c

all :  $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean: 
	rm -f $(NAME)

re: fclean all
