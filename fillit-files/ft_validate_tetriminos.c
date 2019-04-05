/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate_tetriminos.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: renslaros <renslaros@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 03:42:18 by rlaros         #+#    #+#                */
/*   Updated: 2019/04/05 09:17:42 by renslaros     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc -
** @param -
** @var -
*/

static int	ft_get_x_connections(int *t, int x, int y, int hashnbr)
{
	int x_connections;
	int i;

	x_connections = 0;
	i = 0;
	while (t[i] && i <= 6)
	{
		if ((i / 2) + 1 != hashnbr && t[i + 1] == y)
		{
			if ((t[i] == x || t[i] == (x + 1)) ||
				(t[i] == (x - 1) && (x - 1) >= 0))
				x_connections++;
		}
		i += 2;
	}
	return (x_connections);
}

/*
** @desc -
** @param -
** @var -
*/

static int	ft_get_y_connections(int *tetriminos, int x, int y, int hashnbr)
{
	int y_connections;
	int i;

	y_connections = 0;
	i = 0;
	while (t[i] && i <= 6)
	{
		if ((i / 2) + 1 != hashnbr && t[i] == x)
		{
			if ((t[i + 1] == y || t[i + 1] == (y + 1)) || 
				(t[i + 1] == (y - 1) && (y - 1) >= 0))
				y_connections++;
		}
		i += 2;
	}
	return (y_connections);
}

/*
** @desc -
** @param -
** @var -
*/

static int	ft_get_side_count(int *tetriminos, int x, int y, int hashnbr)
{
	int sides;

	sides = ft_get_x_connections(tetriminos, x, y, hashnbr);
	sides += ft_get_y_connections(tetriminos, x, y, hashnbr);
	if (sides == 0)
		ft_handle_error(2);
	return (sides);
}

/*
** @desc -
** @param - int **t 2d Array representing all stored tetrimino's & it's positions
** @var -
*/

int			ft_validate_tetriminos(int **t, int tcount)
{
	int i;
	int j;
	int hash_nbr;
	int sides;

	i = 0;
	j = 0;
	hash_nbr = 0;
	sides = 0;

	while (t[i] && i < tcount)
	{
		while (t[i][j] && j <= 6)
		{
			hash_nbr = ((j + 1) / 2) + 1;
			sides += ft_get_side_count(t[i], t[i][j], t[i][j + 1], hash_nbr);
			j += 2;
		}

		if (sides != 6 && sides != 8)
			ft_handle_error(2);
		sides = 0;
		j = 0;
		i++;
	}
	if ((i + 1) == tcount)
		return (1);
	return (0);
}
