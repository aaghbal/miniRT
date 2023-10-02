# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 15:13:12 by aaghbal           #+#    #+#              #
#    Updated: 2023/10/02 11:43:23 by aaghbal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
CMLX = -L $(shell brew --prefix glfw)/lib -lglfw -LMLX42/ -lmlx42  -framework OpenGL -framework AppKit
NAME = minirt

SRC = main.c create_vec_point.c add_vector_point.c sub_vector_point.c \
		operation_vect_point.c operation_vect_point2.c color.c canvas.c \
		operation_matrice.c operation_mat2.c transformation.c \
		rotation.c utils.c ray.c sphere.c intersect.c transform.c normal_at.c \
		light.c word.c prepare_computations.c color_at.c view_transformation.c \
		camera.c shadow.c inverse_matrix.c shape.c inverse_matrix_1.c \
		intersect_cyl.c intersect_cube.c intersect_cones.c free.c

OB_SRC = $(SRC:.c=.o)
RM = rm -rf

all : $(NAME)

$(NAME) : $(OB_SRC) MLX42/libmlx42.a minirt.h 
	$(CC) $(CFLAGS) $(CMLX) $(OB_SRC) -o $(NAME)
	
MLX42/libmlx.a:
	make -C MLX42/

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OB_SRC)

fclean : clean
	$(RM) $(NAME) 


re : fclean all

norm :
	norminette $(SRC)

.PHONY: all clean re


