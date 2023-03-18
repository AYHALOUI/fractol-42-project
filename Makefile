# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 13:32:32 by ahaloui           #+#    #+#              #
#    Updated: 2023/03/17 17:53:36 by ahaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# name of the executable
NAME = fractol

# name of the library
NAME_FRAME_WORK = -lmlx -framework OpenGL -framework AppKit

# source files
SRC = main.c mandelbrot.c utils.c julia.c utils1.c utils2.c burningship.c

# object files
OBJ = $(SRC:.c=.o)

# compiler
CC = cc

# compiler flags
FLAGS = -Wall -Wextra -Werror

#remove command
RM = rm -f

# rules to build the executable
all: $(NAME)

# rules to build the object files
%.o: %.c fractol.h
	$(CC) $(FLAGS) -c $< -o $@

# rules to build the executable
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(NAME_FRAME_WORK) -o $(NAME) $(OBJ)

# rules to clean the object files
clean:
	$(RM) $(OBJ)

# rules to clean the executable and the object files
fclean: clean
	$(RM) $(NAME) $(OBJ)

# rules to clean the executable and the object files and rebuild the executable
re: fclean all
	