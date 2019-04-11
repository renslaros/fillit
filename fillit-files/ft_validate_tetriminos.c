/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate_tetriminos.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 03:42:18 by rlaros         #+#    #+#                */
/*   Updated: 2019/04/11 05:45:30 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc -
** @param -
** @var -
*/

static int	ft_get_x_connections(int t[8], int x, int y)
{
	int x_connections;
	int i;

	x_connections = 0;
	i = 0;
	while (i <= 6)
	{
		if (t[i] == x && t[i + 1] == y)
		{
			i += 2;
		}
		else
		{
			if ((t[i] == x || t[i] == (x + 1)) ||
				(t[i] == (x - 1) && (x - 1) >= 0))
			{
				if (t[i + 1] == y)
					x_connections++;
			}
			i += 2;
		}
	}
	return (x_connections);
}

/*
** @desc -
** @param -
** @var -
*/

static int	ft_get_y_connections(int t[8], int x, int y)
{
	int y_connections;
	int i;

	y_connections = 0;
	i = 0;
	while (i <= 6)
	{
		if (t[i] == x && t[i + 1] == y)
		{
			i += 2;
		}
		else
		{
			if ((t[i + 1] == y || t[i + 1] == (y + 1)) ||
				(t[i + 1] == (y - 1) && (y - 1) >= 0))
			{
				if (t[i] == x)
					y_connections++;
			}
			i += 2;
		}
	}
	return (y_connections);
}

/*
** @desc -
** @param -
** @var -
*/

static int	ft_get_side_count(int t[8], int x, int y)
{
	int sides;

	sides = ft_get_x_connections(t, x, y);
	sides += ft_get_y_connections(t, x, y);
	return (sides);
}

/*
** @desc -
** @param -
** @var -
*/

int			ft_validate_tetriminos(int t[26][8], int tcount)
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
		while (j < 7)
		{
			hash_nbr = ((j + 1) / 2) + 1;
			sides += ft_get_side_count(t[i], t[i][j], t[i][j + 1]);
			j += 2;
		}
		if (sides != 6 && sides != 8)
			return (0);
		sides = 0;
		j = 0;
		i++;
	}
	return (1);
}
