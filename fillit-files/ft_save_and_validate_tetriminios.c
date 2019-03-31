/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_and_validate_tetriminios.c                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: renslaros <renslaros@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 16:03:58 by renslaros      #+#    #+#                */
/*   Updated: 2019/03/29 17:54:34 by renslaros     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** @desc - Reads and validates all the tetriminios from given input
** @desc - Stores the tetriminios into received 3d tetriminios array
** @param - int **tetriminios 3D array storing tetriminios with X & Y values
** @param - int fd - Filedescriptor to read tetriminios from
** @var - char *tetri_line Used to hold each line when reading from the GNL function
** @var 
** return - int 0 if reading went unsuccessfull
** return - int 1 if reading was successfull
*/

#include "fillit.h"

static void ft_update_tetri_count(int *tetri_count, int y)
{
	if ((y + 1) % 5 == 0 )
		*tetri_count = (y + 1) / 5;
	else
		*tetri_count = ((y + 1) / 5) + 1;
}

int	ft_save_and_validate_tetriminios(int fd, int **tetriminios, int *tetri_count)
{
	char	*tetri_line;
	int		y;

	y = 0;

	if (fd < 0 || BUFF_SIZE < 1 || !tetriminios)
		return (0);

	while (get_next_line(fd, tetri_line) == 1)
	{
		if (ft_validate_tetriminio_line(tetri_line, y))
		{
			if (ft_save_hash_positions(tetriminios, tetri_line, y, tetri_count))
				ft_update_tetri_count(tetri_count, y);
			else
				return (0);
		}
		else
			return (0);
		y++;
	}
	return (0);
}
	int **tetriminios, 
	char *tetri_line, 
	int y, 
	int *tetri_cou