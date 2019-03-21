/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_setup.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 03:42:18 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/21 11:24:30 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** @desc -
** @param -
** @var -
*/

#include "fillit.h"

int	ft_setup(int argc, char **argv)
{
	char	***tetriminios;

	if (argc != 2)
	{
		ft_handle_error(1);
	}
	if (ft_read_tetriminios(tetriminios, open(argv[1], O_RDONLY)))
		ft_validate_tetriminios(tetriminios);
}

// ft_read_tetriminios.c
	// 4Lines for each tetriminio. If tetriminio isn't the last one, a newline will be used to seperate between new tetriminios
// ft_validate_input
	// 4 chars & new line.
	// Dots & Hashes
// ft_prepare

