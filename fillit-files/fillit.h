/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 22:16:10 by rlaros         #+#    #+#                */
/*   Updated: 2019/04/05 03:35:52 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

/*
** Defenitions
*/
# define FILLIT_H
# define MAX_TETRIMINOS 26

/*
** Headers
*/
# include "../libft/includes/libft.h"
# include <fcntl.h>

/*
** ERROR MESSAGES
*/
# define WRONG_USAGE "usage: ./fillit source_file\n"

/*
** Errorr handlers
*/
void	ft_handle_error(int error_code);

/*
** Fillit Setup
*/

int		ft_setup(char **argv, int **tetriminos, int *tcount);

/*
** Fillit Tetriminio input saving and validation
*/
int		ft_save_and_validate(int fd, int **tetriminos, int *tcount);

int		ft_validate_line(char *tetri_line, int y);
int		ft_validate_tetriminos(int **tetriminos, int tcount);
int		ft_save_hash_positions(
	int **tetriminos,
	char *tetri_line,
	int y,
	int tcount
);

#endif
