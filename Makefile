#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 08:42:30 by vsydorch          #+#    #+#              #
#    Updated: 2017/04/19 10:10:10 by vsydorch         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = RT
CC = gcc 
CFLAGS 	= -F./libraries/SDL
SDL_FLAGS = -framework SDL2 \
			-framework SDL2_image \
			-framework SDL2_ttf \
			-framework SDL2_mixer

FLAG = -Wall -Werror -Wextra

DSRC = ./
SRC = 		srcs/main.c \
			srcs/tools.c \
			srcs/camera.c \
			srcs/mtx_op.c \
			srcs/errors.c \
			srcs/after_action.c \
			srcs/after_action2.c \
			srcs/after_action3.c \
			srcs/events.c \
			srcs/events2.c \
			srcs/init.c \
			srcs/init2.c \
			srcs/init_menu.c \
			srcs/init_menu2.c \
			srcs/additional_func.c \
			srcs/rgb.c \
			srcs/intersections.c \
			srcs/raytracing.c \
			srcs/color.c \
			srcs/tortus.c \
			srcs/cylinder_cone.c \
			srcs/scene.c \
			srcs/polynomials.c \
			srcs/parsing.c \
			srcs/parsing2.c \
			srcs/extra.c \
			srcs/recurtion.c \
			srcs/operations.c \
			srcs/hyperboloid.c \
			srcs/fill_data.c \
			srcs/fill_data2.c \
			srcs/additional_sphere.c \
			srcs/sphere_menu.c \
			srcs/additional_cyl.c \
			srcs/cylinder_menu.c \
			srcs/additional_conus.c \
			srcs/conus_menu.c \
			srcs/additional_torus.c \
			srcs/torus_menu.c \
			srcs/additional_par.c \
			srcs/parab_menu.c \
			srcs/additional_dsk.c \
			srcs/disk_menu.c \
			libft/ft_bzero.c \
			libft/ft_putstr.c \
			libft/ft_strdup.c \
			libft/ft_strjoin.c \
			libft/ft_memcpy.c \
			libft/ft_putchar.c \
			libft/ft_strlen.c \
			libft/ft_strnew.c \
			libft/ft_memalloc.c \
			libft/ft_memset.c \
			libft/ft_atoi.c \
			libft/ft_itoa.c \
			libft/ft_strcpy.c \
			libft/ft_strcmp.c

OBJ = $(addprefix $(DSRC)/,$(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(SDL_FLAGS) $(OBJ) -o $(NAME)


%.o: %.cpp
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "Compiling.."  $<

clean:
	@echo "Cleaning.."
	@rm -rf $(OBJ)

fclean: clean
	@echo "Cleaning.."
	@rm -rf $(NAME)

re: fclean all

sdl2:
	cp -r libraries/SDL/SDL2_image.framework ~/Library/Frameworks/
	cp -r libraries/SDL/SDL2.framework ~/Library/Frameworks/
	cp -r libraries/SDL/SDL2_ttf.framework ~/Library/Frameworks/
	cp -r libraries/SDL/SDL2_mixer.framework ~/Library/Frameworks/
