/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate_tetriminio_line.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: renslaros <renslaros@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 13:48:59 by renslaros      #+#    #+#                */
/*   Updated: 2019/03/31 19:06:32 by renslaros     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Validates static hashcount against allowed_hashes 
** @param char *tetri_line -
** @param int lines -
** @var static int hashcount -
** @var int allowed_hashes -
** return int 1 if valid
** return int 0 if invalid
*/

static int	ft_validate_tetriminio_line_hashes(char *tetri_line, int lines)
{
	static int	hashcount;
	int			allowed_hashes;

	if (!hashcount)
		hashcount = 0;
	while (*tetri_line)
	{
		if (*tetri_line == '#')
			hashcount++;
	}
	allowed_hashes = lines % 5 > 0 ? ((lines / 5) + 1 * 4 : (lines / 5) * 4;
	if (hashcount <= allowed_hashes)
		return (1);
	return (0);
}

/*
** @desc - Validates the tetri_line length. Taking \n Seperators into account
** @desc - Validates static hashcount against allowed_hashes 
** @param char *tetri_line -
** @param int lines -
** return int 1 if valid
** return int 0 if invalid
*/

static int	ft_validate_tetriminio_line_length(char *tetri_line, int lines)
{
	if (ft_strlen(tetri_line) == 4)
		return (1);
	if (lines % 5 == 0 && tetri_line[0] == '\0')
		return (1);
	return (0);
}

/*
** @desc - Validates the given tetri_line based on current row
** @param char *tetri_line -
** @param int y -
** return int 1 if valid
** return int 0 if invalid
*/

int			ft_validate_tetriminio_line(char *tetri_line, int y)
{
	if (ft_validate_tetriminio_line_length(tetri_line, (y + 1)) &&
		ft_validate_tetriminio_line_hashes(tetri_line, (y + 1)))
		return (1);
	return (0);
}
