/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_setup.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 03:42:18 by rlaros         #+#    #+#                */
/*   Updated: 2019/04/01 21:35:31 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** @desc - Handles the program setup and makes everything ready before solving
** @param int argc -
** @param char **argv -
** @var int fd - fd pointing to tetriminio input received as argument
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
