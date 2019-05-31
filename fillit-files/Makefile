# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abumbier <abumbier@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/17 09:42:33 by lskrauci       #+#    #+#                 #
#    Updated: 2019/05/31 06:54:18 by rlaros        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = "fillit"
FLAGS = -Wall -Wextra -Werror -g
LIBRARY = -L ../libft/ -lft
OPTIONS = -o $(NAME)
LIB_BUILD_CMD = -C ../libft/ fclean && make -C ../libft/ && make clean -C ../libft
PROGRAM_BUILD_CMD = $(SRCS) $(OPTIONS) $(FLAGS) $(LIBRARY)
SRCS = fillit.c ft_check_board_inc.c ft_check_index_inc.c ft_convert.c \
ft_find_coordinates.c ft_find_place.c \
ft_handle_error.c ft_inc_board.c \
ft_locate_tetri_space.c ft_make_board.c ft_make_tbox.c \
ft_no_space.c ft_print_board.c ft_put_tetri.c \
ft_remove_tetri.c ft_reset_board.c ft_save_and_validate.c \
ft_save_hash_positions.c ft_setup.c ft_solve_fillit.c \
ft_validate_line.c ft_validate_tetriminos.c

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