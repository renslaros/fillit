/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate_line.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 13:48:59 by renslaros      #+#    #+#                */
/*   Updated: 2019/04/11 06:39:57 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Validates static hashcount against allowed_hashes
** @param char *t_line - single line part of tetrimino
** @param int lines - number of lines
** @var static int hashcount -
** @var int allowed_hashes -
** return int 1 if valid
** return int 0 if invalid
*/

static int	ft_validate_line_hashes(char *t_line, int lines)
{
	static int	hashcount;
	int			max_hashes;

	if (!hashcount)
		hashcount = 0;
	while (*t_line)
	{
		if (*t_line == '#')
			hashcount++;
		t_line++;
	}
	max_hashes = (lines % 5) > 0 ? (((lines / 5) + 1) * 4) : (lines / 5) * 4;

	if (hashcount < ((lines / 5) * 4))
		return (0);
	if (hashcount <= max_hashes)
		return (1);
	return (0);
}

/*
** @desc - Validates the t_line length.
** @param char *t_line - single line part of tetrimino
** @param int lines - number of lines
** return int 1 if valid
** return int 0 if invalid
*/

static int	ft_validate_line_length(char *t_line, int lines)
{
	if (ft_strlen(t_line) == 4)
		return (1);
	if (lines % 5 == 0 && *t_line == '\0')
		return (1);
	return (0);
}

/*
** @desc - Validates the t_line characters
** @param char *t_line - single line part of tetrimino
** @param int lines - number of lines
** return int 1 if valid
** return int 0 if invalid
*/

static int	ft_validate_line_chars(char *t_line, int lines)
{
	int i;

	i = 0;
	if (lines % 5 == 0 && t_line[0] == '\0')
		return (1);
	while (t_line[i] != '\0')
	{
		if (t_line[i] != '#' && t_line[i] != '.')
			return (0);
		i++;
	}
	if (t_line[i] == '\0' && t_line[0] != '\0')
		return (1);
	return (0);
}

/*
** @desc - Validates the given t_line based on current row
** @param char *t_line -
** @param int y -
** return int 1 if valid
** return int 0 if invalid
*/

int			ft_validate_line(char *t_line, int y)
{
	if (ft_validate_line_length(t_line, (y + 1)) &&
		ft_validate_line_hashes(t_line, (y + 1)) &&
		ft_validate_line_chars(t_line, (y + 1)))
	{
		return (1);
	}
	return (0);
}
