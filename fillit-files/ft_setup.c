/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_setup.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 03:42:18 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/22 06:45:42 by rlaros        ########   odam.nl         */
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

int	ft_setup(int argc, char **argv, int *tetri_count)
{
	int fd;
	int	tetriminios[MAX_TETRIMINIOS + 1][9];

	if (argc != 2)
		ft_handle_error(1);
	fd = open(argv[1], O_RDONLY);
	if (ft_read_tetriminios(fd, tetriminios, tetri_count) &&
		ft_validate_tetriminios(tetriminios, tetri_count))
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

