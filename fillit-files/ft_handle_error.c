/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_handle_error.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 03:19:54 by rlaros         #+#    #+#                */
/*   Updated: 2019/04/11 08:33:52 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/includes/libft.h"

/*
** @desc - Prints usage or error message and exits the application accordingly.
** @param int error_code - Specifying the code of the occuring error.
*/

void	ft_handle_error(int error_code)
{
	if (error_code == 1)
		ft_putstr_fd(WRONG_USAGE, 1);
	else if (error_code == 2)
		ft_putstr_fd("error\n", 1);
	exit(1);
}
