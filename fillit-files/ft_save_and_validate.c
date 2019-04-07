/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_and_validate.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 08:11:51 by renslaros      #+#    #+#                */
/*   Updated: 2019/04/07 06:15:54 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc -
** @param -
** @var -
*/

static void	ft_update_tetri_count(int *tetri_count, int y)
{
	if ((y + 1) % 5 == 0)
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

int			ft_save_and_validate(int fd, int tetriminos[26][8], int *tcount)
{
	char	*tetri_line;
	int		y;

	y = 0;

	if (fd < 0 || BUFF_SIZE < 1 || !tetriminos)
		return (0);

	while (ft_get_next_line(fd, &tetri_line) == 1)
	{
		if (ft_validate_line(tetri_line, y))
		{
			ft_save_hash_positions(tetriminos, tetri_line, y, *tcount);
			ft_update_tetri_count(tcount, y);
		}
		else
			return (0);
		y++;
	}
	if (ft_validate_tetriminos(tetriminos, *tcount))
		return (1);
	return (0);
}
