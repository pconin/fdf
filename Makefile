NAME = mlx

HEAD = fdf.h

PATH_LIB = ./libft/

FLAGS = -Wall -Wextra -Werror

SRC = tools.c	file.c	error.c	test.c	event.c		draw.c

HOMEPATH = -lm -L libft/ -lft -L./minilibx_macos -I./minilibx_macos -lmlx -framework OpenGL -framework AppKit

SCHPATH = -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(SRC) -I $(HEAD) $(HOMEPATH)

clean :
	make -C libft/ clean

fclean :
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
