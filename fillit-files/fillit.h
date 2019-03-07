/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 22:16:10 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/07 03:53:53 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "../libft/includes/libft.h"

/*
** ERROR MESSAGES
*/
# define DEFAULT_ERROR "error\n"
# define WRONG_USAGE "usage: ./fillit source_file\n"

void	ft_handle_error(int error_code);

#endif
