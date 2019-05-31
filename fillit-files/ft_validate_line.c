/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:48:59 by renslaros         #+#    #+#             */
/*   Updated: 2019/05/07 13:44:21 by abumbier         ###   ########.fr       */
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

/*
** Start with a static hashcount of 0
** Loop over the tetrimino line and increase the hashcount if an # occurs
** Calculate the amount of hashes based on the lines we've currently read
** Check if we didn't receive enough #'s based on lines we've currently read
** Check if we don't exceed the maximum amount of hashes
** Return 0 if one of the checks fail or 1 otherwise
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
	if (hashcount < ((lines / 5) * 4) || hashcount > max_hashes)
		return (0);
	return (1);
}

/*
** @desc - Validates the t_line length.
** @param char *t_line - single line part of tetrimino
** @param int lines - number of lines
** return int 1 if valid
** return int 0 if invalid
*/

/*
** Return 1 if t_line length is 4
** Return 1 if t_line is empty and is supposed to be so
** Return 0 in any other case
*/

static int	ft_validate_line_length(char *t_line, int lines)
{
	if ((ft_strlen(t_line) == 4) || (lines % 5 == 0 && *t_line == '\0'))
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

/*
** Check if the line isn't supposed to be empty and return 0 if is
** Check if the line is supposed to be empty and return 0 if it's not
** Loop over t_line using I and return 0 if something other than # or . is found
** Return 1 if we successfully looped over t_line
*/

static int	ft_validate_line_chars(char *t_line, int lines)
{
	int i;

	i = 0;
	if ((lines % 5 != 0 && *t_line == '\0') ||
		(lines % 5 == 0 && *t_line != '\0'))
		return (0);
	while (t_line[i])
	{
		if (t_line[i] != '#' && t_line[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

/*
** @desc - Validates the given t_line based on current row
** @param char *t_line -
** @param int y -
** return int 1 if valid
** return int 0 if invalid
*/

/*
** Return 1 When all called functions are valid and return 1 return 0 otherwise
*/

int			ft_validate_line(char *t_line, int y)
{
	y++;
	if (ft_validate_line_length(t_line, y) &&
		ft_validate_line_hashes(t_line, y) && ft_validate_line_chars(t_line, y))
		return (1);
	return (0);
}
