# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrea <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/20 16:19:36 by fgrea             #+#    #+#              #
#    Updated: 2017/03/26 22:02:28 by fgrea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

ifneq ($(shell make -q -C libft; echo $$?), 0)
	.PHONY: libft/libft.a
endif

NAME = fractol

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

cc = gcc
C_FLAGS = -Wall -Wextra -Werror
FRAM = -lmlx -framework OpenGL -framework AppKit
# FRAM = -framework OpenGL -framework AppKit minilibx/libmlx.a

OBJ_PATH = ./obj/
LFT_PATH = ./libft/
INC_PATH = ./includes/
SRC_PATH = ./srcs/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fractol.h
SRC_NAME = main.c fractol_image_gestion.c fractol_pixel_gestion.c \
		   fractol_inputs_gestion.c fractol_mandelbrot.c fractol_julia.c \
		   fractol_mandelbar.c fractol_burningship.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
			@make -C $(LFT_PATH)
			@$(CC) -o $(NAME) $(FRAM) -L $(LFT_PATH) $(MLX_PATH) -lft $^ -o $@
			@echo "$(OKC)FRACTOL:\tCOMPILED$(NOC)"
			@echo "***************************************"
			@echo "----------------__---------------------"
			@echo "--------------<(o )___.----------------"
			@echo "---------------( ._> /-----------------"
			@echo "----------------\`---'-------C.WC------"
			@echo "***************************************"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
			@mkdir -p $(OBJ_PATH) 2> /dev/null || true
			@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<

clean:
			@make -C $(LFT_PATH) clean
			@rm -rf $(OBJ_PATH)
			@echo "$(WAC)FRACTOL:\tCLEANING OBJS$(NOC)"
			@echo "***************************************"


fclean: clean
			@make -C $(LFT_PATH) fclean
			@rm -f $(NAME)
			@echo "$(WAC)FRACTOL:\tCOMPILATION TRACES REMOVED$(NOC)"
			@echo "***************************************"


re: fclean
			@$(MAKE) all
