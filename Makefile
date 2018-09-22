# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 09:12:18 by rsharipo          #+#    #+#              #
#    Updated: 2018/09/03 16:25:15 by rsharipo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME2 = checker

LIB = libft.a

LIBDIR = ./libft

SHR_SRC = exit_prog.c push_func.c sort_small.c find_func.c list_func.c \
		  split_func.c check_args.c free_list.c op_func.c rot_func.c \
		  swap_func.c pop_func.c rrot_func.c init_data.c print_func.c \
		  sort_big.c

SRC = push_swap.c 

SRC2 = checker.c dispatch.c

OBJ = $(SRC:.c=.o)

OBJ2 = $(SRC2:.c=.o)

SHR_OBJ = $(SHR_SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@cd $(LIBDIR) && $(MAKE)
	@gcc -c $(CFLAGS) $(SHR_SRC)
	@gcc -c $(CFLAGS) $(SRC)
	@gcc $(CFLAGS) $(OBJ) $(SHR_OBJ) $(LIBDIR)/$(LIB) -o $(NAME)
	@gcc -c $(CFLAGS) $(SRC2)
	@gcc $(CFLAGS) $(OBJ2) $(SHR_OBJ) $(LIBDIR)/$(LIB) -o $(NAME2)

f:
	@gcc $(CFLAGS) $(SRC) $(SHR_SRC) $(LIBDIR)/$(LIB) -o $(NAME)
	@gcc $(CFLAGS) $(SRC2) $(SHR_SRC) $(LIBDIR)/$(LIB) -o $(NAME2)
	@/bin/rm -f $(OBJ) $(OBJ2) $(SHR_OBJ)

d:
	@cd $(LIBDIR) && $(MAKE) d
	@gcc -g -fsanitize=address $(CFLAGS) $(SRC) $(SHR_SRC) $(LIBDIR)/$(LIB) -o $(NAME)
	@gcc -g -fsanitize=address $(CFLAGS) $(SRC2) $(SHR_SRC) $(LIBDIR)/$(LIB) -o $(NAME2)
	@/bin/rm -f $(OBJ) $(OBJ2) $(SHR_OBJ)

clean:
	@cd $(LIBDIR) && $(MAKE) clean
	@/bin/rm -f $(OBJ) $(OBJ2) $(SHR_OBJ)

fclean: clean
	@cd $(LIBDIR) && $(MAKE) fclean
	@/bin/rm -f $(NAME) $(NAME2)

re: fclean all
