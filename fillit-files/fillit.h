/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: renslaros <renslaros@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 22:16:10 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/29 04:35:46 by renslaros     ########   odam.nl         */
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

int		ft_setup(int argc, char **argv, int *tetri_count);

/*
** Fillit Tetriminio input file reading and validation
*/
int		ft_save_and_validate_tetriminios(int fd, int **tetriminios, int *tetri_count);

/*
** Input & Tetriminio Validation
*/
int		ft_validate_tetriminio_sides(int **tetriminios, int *tetri_count);
int		ft_validate_tetriminio_line(char *tetri_line, int y);


#endif
