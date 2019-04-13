/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_and_validate.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: renslaros <renslaros@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 08:11:51 by renslaros      #+#    #+#                */
/*   Updated: 2019/04/13 21:24:58 by renslaros     ########   odam.nl         */
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

/*
** Validate fd, buff size & received 2d tetrimino array. Return 0 if invalid
** Loop over each line from the received tetrimino input
** Update the tetri counter on each iteration
** If the line is invalid we return 0
** Otherwise we save the hashes in the line and increase y
** If we're done validating & reading all lines as well as saving the #'s
** We make sure the hashes we stored are valid tetriminos
** if so the validator returns 1 and we return 1, if not we return 0
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
		ft_update_tetri_count(tcount, y);
		if (!ft_validate_line(tetri_line, y))
			return (0);
		ft_save_hash_positions(t, tetri_line, y, *tcount);
		y++;
	}

	return (ft_validate_tetriminos(t, *tcount) ? 1 : 0);
}
