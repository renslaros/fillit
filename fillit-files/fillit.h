/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: renslaros <renslaros@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 22:16:10 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/31 07:57:37 by renslaros     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
/*
** Defenitions
*/
# define FILLIT_H
# define MAX_TETRIMINIOS 26

/*
** Headers
*/
#include "../libft/includes/libft.h"
#include <fcntl.h>

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

int		ft_setup(char **argv, int *tcount);

/*
** Fillit Tetriminio input file reading and validation
*/
int		ft_save_and_validate_tetriminios(int fd, int **tetriminios, int *tcount);

/*
** Input & Tetriminio Validation
*/
int		ft_validate_tetriminio_sides(int **tetriminios);
int		ft_validate_tetriminio_line(char *tetri_line, int y);


#endif
