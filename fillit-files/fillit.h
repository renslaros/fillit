/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 22:16:10 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/22 06:48:57 by rlaros        ########   odam.nl         */
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
** Fillit Tetriminio input file reading
*/
int		ft_read_tetriminios(int fd, int **tetriminios, int *tetri_count);

/*
** Input & Tetriminio Validation
*/
int		ft_validate_tetriminios(int **tetriminios, int *tetri_count);
int		ft_validate_line(char *tetri_line);


#endif
