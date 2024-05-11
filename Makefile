NAME = fractol
CCFLGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
CC = cc
SRC_FILE =main.c \
		 mandelbort.c \
		 julia.c \
		 utils.c \
		 printstr.c \
		 hooks.c
OBJ = $(SRC_FILE : .o:.c)

%.o: %.c
	#$(CC)   $(CCFLGS) -Imlx -c $< -o $@
	 $(CC) $(CCFLGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME):  $(SRC_FILE) $(OBJ)
	#$(CC)  $(CCFLGS) $(SRC_FILE) $(OBJ)  -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	 $(CC) $(CCFLGS) $(SRC_FILE) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean: $(OBJ)
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re:fclean all