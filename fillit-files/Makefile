# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rlaros <rlaros@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/17 09:42:33 by lskrauci       #+#    #+#                 #
#    Updated: 2019/04/13 04:45:14 by rlaros        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = "fillit"
FLAGS = -Wall -Wextra -Werror
LIBRARY = -L ../libft/ -lft
OPTIONS = -o $(NAME)
LIB_BUILD_CMD = -C ../libft/ fclean && make -C ../libft/ && make clean -C ../libft
PROGRAM_BUILD_CMD = $(SRCS) $(OPTIONS) $(FLAGS) $(LIBRARY)
SRCS = fillit.c ft_handle_error.c ft_setup.c \
ft_save_and_validate.c ft_save_hash_positions.c ft_validate_line.c ft_validate_tetriminos.c

all: $(NAME)

$(NAME):
	@echo —————————————————————————————————
	@echo [\#] Compiling $(NAME)
	@echo —————————————————————————————————
	@make $(LIB_BUILD_CMD)
	@gcc $(PROGRAM_BUILD_CMD)
	@echo —————————————————————————————————
	@echo [\#] Done Compiling $(NAME)
	@echo —————————————————————————————————

clean:
	@echo —————————————————————————————————
	@echo [\#] Cleaning $(NAME)
	@echo —————————————————————————————————
	@rm -f ./*.o

fclean: clean
	@echo —————————————————————————————————
	@echo [\#] Removing $(NAME) Executable
	@echo —————————————————————————————————
	@rm -f $(NAME)

re: fclean all