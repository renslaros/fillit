/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_and_validate.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 08:11:51 by renslaros      #+#    #+#                */
/*   Updated: 2019/04/13 03:43:11 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Updates the tetrimino counter based on y index.
** @param int *tcount - pointer to tetrimino counter
** @param int y - current y index used as iterator while reading t_lines
*/

static void	ft_update_tetri_count(int *t_count, int y)
{
	y++;
	if (y % 5 == 0)
		*t_count = y / 5;
	else
		*t_count = (y / 5) + 1;
}

/*
** @desc - Saves and validates the given tetrimino input
** @param int fd - Filedescriptor to read tetriminios from
** @param int t[][8] - 2d tetrimino array holding # X & Y positions
** @param int *tcount - pointer to tetrimino counter
** @var char *tetri_line - line holder passed to GNL
** @var int y - row counter
** return - int 0 if reading went unsuccessfull
** return - int 1 if reading was successfull
*/

int			ft_save_and_validate(int fd, int t[][8], int *tcount)
{
	char	*tetri_line;
	int		y;

	y = 0;
	if (fd < 0 || BUFF_SIZE < 1 || !t)
		return (0);
	while (ft_get_next_line(fd, &tetri_line) == 1)
	{
		if (ft_validate_line(tetri_line, y))
		{
			ft_update_tetri_count(tcount, y);
			ft_save_hash_positions(t, tetri_line, y, *tcount);
		}
		else
			return (0);
		y++;
	}
	if (ft_validate_tetriminos(t, *tcount))
		return (1);
	return (0);
}
