/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: renslaros <renslaros@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 22:16:10 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/21 14:20:50 by renslaros     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
/*
** Defenitions
*/
# define FILLIT_H

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

int		ft_setup(int argc, char **argv);

/*
** Fillit Tetriminio input file reading
*/
int		ft_read_tetriminios(char **tetriminios, int fd);

/*
** Input & Tetriminio Validation
*/
int		ft_validate_tetriminios(char **tetriminios);
int		ft_validate_input_format(char **tetriminios);
int		ft_validate_hashcount(char **tetriminios);
int		ft_validate_tetriminio_sides(char **tetriminios);

#endif
