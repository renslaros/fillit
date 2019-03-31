/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_setup.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: renslaros <renslaros@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 03:42:18 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/31 07:57:31 by renslaros     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** @desc - Handles the program setup and makes everything ready before solving
** @param int argc - 
** @param char **argv - 
** @var int fd - filedescriptor pointing to tetriminio input received as argument
** @var int **tetriminios - 2d Array storing the tetriminios X & Y positions
*/

#include "fillit.h"

int	ft_setup(char **argv, int **tetriminios, int *tcount)
{
	int fd;
	
	fd = open(argv[1], O_RDONLY);
	if (ft_save_and_validate_tetriminios(fd, tetriminios, tcount))
	{
		close(fd);
		return (1);
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

