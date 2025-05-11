NAME = fractol

LIBFTDIR = libft/

SRC = main.c math.c render.c utils.c init.c events.c
OBJ = $(SRC:%.c=%.o)
CC = cc
CFLAGS = -g -I/minilibx-linux -Wall -Wextra -Werror -I$(LIBFTDIR)
LDFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -L$(LIBFTDIR) -lft

LIBFT = $(LIBFTDIR)libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFTDIR)
$(NAME): $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)
clean:
				rm -f $(OBJ)
				$(MAKE) -C $(LIBFTDIR) clean
fclean: clean
				rm -f $(NAME)
				$(MAKE) -C $(LIBFTDIR) fclean
re: fclean all
