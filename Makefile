NAME = fractol
CCFLGS = cc -Wall -Wextra -Werror

SRC_FILE =main.c \
		 mandelbort.c \
		 julia.c \
		 utils.c
OBJ = $(SRC_FILE : .o:.c)

%.o: %.c
	$(CC) -g -Wall -Wextra -Werror -Imlx -c $< -o $@
	# $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME):  $(SRC_FILE) $(OBJ)
	$(CC) -g $(SRC_FILE) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	# $(CC) $(SRC_FILE) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean: $(OBJ)
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re:fclean all