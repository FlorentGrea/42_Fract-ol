# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrea <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 21:43:43 by fgrea             #+#    #+#              #
#    Updated: 2017/03/25 17:34:36 by fgrea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

GCFLAGS = gcc -Wall -Wextra -Werror

OBJ_PATH = ./obj/
INC_PATH = ./includes/
SRC_PATH = ./srcs/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = libft.h
SRC_NAME = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_atoi.c \
		   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		   ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
		   ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
		   ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
		   ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
		   ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
		   ft_lstdel.c ft_lstadd.c ft_lstmap.c ft_strncmp.c ft_lstiter.c \
		   ft_strnlen.c ft_printanswer.c ft_printquestion.c ft_sqrt.c \
		   ft_pow.c get_next_line.c


SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
				@ar rc $(NAME) $(OBJ)
				@ranlib $(NAME)
				@echo "$(OKC)LIBFT:\t\tCOMPILED$(NOC)"
				@echo "***************************************"



$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH) 2> /dev/null || true
				@$(GCFLAGS) $(INC) -o $@ -c $<

clean:
				@/bin/rm -rf $(OBJ_PATH)
				@echo "$(WAC)LIBFT:\t\tCLEANING OBJS$(NOC)"
				@echo "***************************************"


fclean: clean
				@/bin/rm -rf $(NAME)
				@echo "$(WAC)LIBFT:\t\tCOMPILATION TRACES REMOVED$(NOC)"
				@echo "***************************************"


re: fclean all

.PHONY: clean fclean re
