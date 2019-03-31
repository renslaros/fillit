/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate_tetriminio_line.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: renslaros <renslaros@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 13:48:59 by renslaros      #+#    #+#                */
/*   Updated: 2019/03/29 04:34:48 by renslaros     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc -
** @param -
** @var -
*/

static int ft_validate_tetriminio_line_hashes(char *tetri_line, int line_count)

/*
** @desc -
** @param -
** @var -
*/

static int ft_validate_tetriminio_line_length(char *tetri_line, int line_count)
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

int ft_validate_tetriminio_line(char *tetri_line, int y)
{
	int	i;
	int	x;

	int i = 0;
	int x = 0;
	
	if (ft_validate_tetriminio_line_length(tetri_line, (y + 1)) &&
		ft_validate_tetriminio_line_hashes(tetri_line, (y + 1)) )
		return (1);
	return (0);
}
