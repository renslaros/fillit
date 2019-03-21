/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_tetriminios.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 17:15:57 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/21 12:47:36 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** @desc - Reads all the tetriminios from given fd
** @desc - Stores the tetriminios read into received 3d tetriminios array
** @param - char ***tetriminios 3D array storing tetriminios with X & Y values
** @param - int fd - Filedescriptor to read tetriminios from
** @var - char *line Used to hold each line when reading from the GNL function
*/

#include "fillit.h"

int	ft_read_tetriminios(char ***tetriminios, int fd)
{
	char	*tetri_line;
	int		x;
	int		y;
	int		tetri_count;

	x = 0;
	y = 0;
	tetri_count = 1;

	if (fd < 0 || BUFF_SIZE < 1 || !tetriminios)
		return (0);
	while (get_next_line(fd, &tetri_line) == 1)
	{
		if (tetri_line[0] == '\0')
			tetri_count++;
		y++;
	}
	return (0);
}
