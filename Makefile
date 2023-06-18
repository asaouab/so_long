# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 12:31:40 by asaouab           #+#    #+#              #
#    Updated: 2023/06/18 15:30:47 by asaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

HEADER = so_long.h

SRC = so_long.c parcsing.c valid_path.c ft_Pposition.c other.c ft_magic.c  get_next_line.c get_next_line_utils.c

OBJS = so_long.o parcsing.o  other.o ft_magic.o valid_path.o ft_Pposition.o  get_next_line.o get_next_line_utils.o

FLAGS = -Wall

all: $(NAME)

$(NAME) : $(OBJS) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -lmlx -framework OpenGL -framework AppKit

%.o : %.c $(HEADER)
	 $(CC) -c $< 

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
.PHONY: clean fclean