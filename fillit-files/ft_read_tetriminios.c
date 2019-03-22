/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_tetriminios.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 17:15:57 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/22 06:37:55 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** @desc - Reads all the tetriminios from given fd
** @desc - Stores the tetriminios into received 3d tetriminios array
** @param - int **tetriminios 3D array storing tetriminios with X & Y values
** @param - int fd - Filedescriptor to read tetriminios from
** @var - char *tetri_line Used to hold each line when reading from the GNL function
** @var 
** return - int 0 if reading went unsuccessfull
** return - int 1 if reading was successfull
*/

#include "fillit.h"

int	ft_read_tetriminios(int fd, int **tetriminios, int *tetri_count)
{
	char	*tetri_line;
	int		tetri_count;
	int		x;
	int		y;

	tetri_count = 1;
	x = 0;
	y = 0;

	if (fd < 0 || BUFF_SIZE < 1 || !tetriminios)
		return (0);

	while (get_next_line(fd, &tetri_line) == 1)
	{
		if (tetri_line[0] == '\0')
			tetri_count++;
		y++;
		//tetriminios[0[x,y] = 
	}
	return (0);
}
