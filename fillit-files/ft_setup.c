/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_setup.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: renslaros <renslaros@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 03:42:18 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/21 14:09:07 by renslaros     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** @desc - Handles the program setup and makes everything ready before solving
** @param int argc - 
** @param char **argv - 
** @var int fd - filedescriptor pointing to tetriminio input received as argument
** @var char **tetri_input - 3d Array storing the tetriminio input
*/

#include "fillit.h"

int	ft_setup(int argc, char **argv)
{
	int 	fd;
	char	***tetri_input;

	fd = open(argv[1], O_RDONLY);
	
	if (argc != 2)
	{
		ft_handle_error(1);
	}
	if (ft_read_tetriminios(tetri_input, fd))
	{
		if (ft_validate_tetriminios(tetri_input))
		{
			close(fd);
			return (1);
		}
	}
	close(fd);
	return (0);
}

// ft_read_tetriminios.c
	// 4Lines for each tetriminio. If tetriminio isn't the last one, a newline will be used to seperate between new tetriminios
// ft_validate_input
	// 4 chars & new line.
	// Dots & Hashes
// ft_prepare

