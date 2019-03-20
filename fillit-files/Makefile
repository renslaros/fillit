# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rlaros <rlaros@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/17 09:42:33 by lskrauci       #+#    #+#                 #
#    Updated: 2019/03/07 06:39:21 by rlaros        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = "fillit"
FLAGS = -Wall -Wextra -Werror
LIBRARY = -L ../libft/ -lft
OPTIONS = -o $(NAME)
LIB_BUILD_CMD = -C ../libft/ fclean && make -C ../libft/
PROGRAM_BUILD_CMD = $(SRCS) $(OPTIONS) $(FLAGS) $(LIBRARY)
SRCS = fillit.c ft_validate_input.c ft_setup.c ft_start.c ft_configure.c \
ft_handle_error.c

all: $(NAME)

$(NAME):
	@echo —————————————————————————————————
	@echo [\#] Compiling $(NAME)
	@echo —————————————————————————————————
	@make $(LIB_BUILD_CMD)
	gcc $(PROGRAM_BUILD_CMD)

clean:
	@echo —————————————————————————————————
	@echo [\#] Cleaning $(NAME)
	@echo —————————————————————————————————
	rm -f ./*.o

fclean: clean
	@echo —————————————————————————————————
	@echo [\#] Removing $(NAME) Executable
	@echo —————————————————————————————————
	rm -f $(NAME)

re: fclean all