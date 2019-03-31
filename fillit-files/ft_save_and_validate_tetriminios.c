/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_and_validate_tetriminios.c                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 16:03:58 by renslaros      #+#    #+#                */
/*   Updated: 2019/03/31 04:38:00 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc -
** @param -
** @var -
*/

static void ft_update_tetri_count(int *tetri_count, int y)
{
	if ((y + 1) % 5 == 0 )
		*tetri_count = (y + 1) / 5;
	else
		*tetri_count = ((y + 1) / 5) + 1;
}
/*
** @desc - Reads and validates all the tetriminios from given input
** @desc - Stores the tetriminios into received 3d tetriminios array
** @param - int **tetriminios 3D array storing tetriminios with X & Y values
** @param - int fd - Filedescriptor to read tetriminios from
** @var char *tetri_line - line holder passed to GNL
** @var int y - row counter
** return - int 0 if reading went unsuccessfull
** return - int 1 if reading was successfull
*/

int	ft_save_and_validate_tetriminios(int fd, int **tetriminios, int *tcount)
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
			if (ft_save_hash_positions(tetriminios, tetri_line, y, tcount))
				ft_update_tetri_count(tcount, y);
			else
				return (0);
		}
		else
			return (0);
		y++;
	}
	if (ft_validate_tetriminio_sides(tetriminios))
		return (1);
	return (0);
}
