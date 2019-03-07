/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_handle_error.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 03:19:54 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/07 03:54:26 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** @desc - Prints usage or error message and exits the application accordingly.
** @param int error_code - Used to identify the type of error currently occuring
*/

#include "fillit.h"
#include "../libft/includes/libft.h"

void	ft_handle_error(int error_code)
{
	if (error_code == 1)
		ft_putstr_fd(WRONG_USAGE, 1);
	else if (error_code == 2)
		ft_putstr_fd(DEFAULT_ERROR, 1);
	exit(1);
}
