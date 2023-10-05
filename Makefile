# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 09:51:25 by houmanso          #+#    #+#              #
#    Updated: 2023/10/05 21:16:51 by houmanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Werror -Wextra
LIBMLX	=	./MLX42/libmlx42.a -L ~/.brew/opt/glfw/lib -lglfw -ldl -lm -L ./Libft -lft
OPTIMZE	=	-O3 -Ofast -march=native -flto -funroll-loops -ffast-math
SRC = main.c create_vec_point.c add_vector_point.c sub_vector_point.c \
		operation_vect_point.c operation_vect_point2.c color.c canvas.c \
		operation_matrice.c operation_mat2.c transformation.c \
		rotation.c utils.c ray.c sphere.c intersect.c transform.c normal_at.c \
		light.c word.c prepare_computations.c color_at.c view_transformation.c \
		camera.c shadow.c inverse_matrix.c shape.c inverse_matrix_1.c \
		intersect_cyl.c intersect_cube.c intersect_cones.c free.c parsing.c \
		get_next_line.c get_next_line_utils.c parsing_am_light.c parsing_plan.c\
		parsing_sphere.c parsing_light.c parsing_camera.c orient.c
OBJ		=	$(SRC:.c=.o)
NAME	=	miniRT
OBJ		=	$(SRC:.c=.o)

CFLAGS += -g
CFLAGS += -I ./include -I ./MLX42/include -I ~/.brew/opt/glfw/include
CFLAGS += $(OPTIMZE)

all : mlx libft $(NAME)

libft :
	@make -C ./Libft

mlx :
	@make -C ./MLX42

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIBMLX)  -o $(NAME)

%.o : %.c ./include/*
	cc $(CFLAGS) -c $(INC) $< -o $@
clean :
	@make -C ./MLX42 clean
	@make -C ./Libft clean
	rm -rf $(OBJ)

fclean : clean
	@make -C ./MLX42 fclean
	@make -C ./Libft fclean
	rm -rf $(NAME)

re: fclean all

norm :
	@norminette $(SRC) include

.PHONY : all  clean  fclean mlx norm re libft
