NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS2 = -framework OpenGL -framework AppKit
MLX = mlx
INCLUDES = includes
LIB = libft
SRCS = srcs/main.c\
	   srcs/flags.c\
	   srcs/draw.c\
	   srcs/hooks.c\
	   srcs/create_map.c\
	   srcs/calculation.c\
	   srcs/rotation.c\
	   srcs/ft_surface.c\
	   srcs/colors.c
OBJS = main.o\
	   flags.o\
	   draw.o\
	   hooks.o\
	   create_map.o\
	   calculation.o\
	   rotation.o\
	   ft_surface.o\
	   colors.o

all: $(NAME)

$(NAME):
	make -C $(LIB)
	make -C $(MLX)
	$(CC) $(FLAGS) -c $(SRCS) -I $(INCLUDES) -I $(LIB)/includes
	$(CC) $(FLAGS) $(FLAGS2) -o $(NAME) -I $(INCLUDES) -I $(LIB)/includes $(OBJS) $(MLX)/libmlx.a $(LIB)/libft.a

.PHONY: clean norme re all

clean:
	make -C $(LIB) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIB) fclean
	rm -f $(NAME)

norme:
	norminette $(SRCS) $(INCLUDES)/fdf.h

re: fclean $(NAME)
