/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_setup.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 03:42:18 by rlaros         #+#    #+#                */
/*   Updated: 2019/04/13 03:42:57 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Handles the program setup and prepares everything before solving
** @param char **argv - Arguments the program received
** @param int t[][8] - 2d tetrimino array holding the X & Y positions for all #
** @param int *tcount - pointer to tetrimino counter
** @var int fd - filedescriptor pointing to received tetrimino input file
*/

/*
** Open file and assign it to fd
** Call Save & Validate and return 1 if function returns 1 (Successfull / Valid)
** Return 0 if Save & Validate returns 0. ( invalid )
** Close input file in both cases
*/

int	ft_setup(char **argv, int t[][8], int *tcount)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (ft_save_and_validate(fd, t, tcount))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
