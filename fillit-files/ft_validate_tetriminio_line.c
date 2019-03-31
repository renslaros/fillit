/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate_tetriminio_line.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 13:48:59 by renslaros      #+#    #+#                */
/*   Updated: 2019/03/31 04:50:14 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc -
** @param -
** @var -
*/

static int	ft_validate_tetriminio_line_hashes(char *tetri_line, int line_count)
{
	static int	hashcount;

	if (!hashcount)
		hashcount = 0;
	while (*tetri_line)
	{
		if (*tetri_line == '#')
		{
			// increase hashcount. Check if hashcount is < MAX_HASHES depending on received linecount input
		}
	}	
	return (0);
}

/*
** @desc -
** @param -
** @var -
*/

static int	ft_validate_tetriminio_line_length(char *tetri_line, int line_count)
{
	if (ft_strlen(tetri_line) == 4)
		return (1);
	if (line_count % 5 == 0 && tetri_line[0] == '\0')
		return (1);
	return (0);
}

/*
** @desc -
** @param -
** @var -
*/

int			ft_validate_tetriminio_line(char *tetri_line, int y)
{
	if (ft_validate_tetriminio_line_length(tetri_line, (y + 1)) &&
		ft_validate_tetriminio_line_hashes(tetri_line, (y + 1)))
		return (1);
	return (0);
}
