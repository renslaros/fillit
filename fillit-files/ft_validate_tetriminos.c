/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate_tetriminos.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 03:42:18 by rlaros         #+#    #+#                */
/*   Updated: 2019/04/05 06:42:30 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc -
** @param -
** @var -
*/

static int	ft_get_h_connections(int *t, int x, int y, int hashnbr)
{
	int h_matches;
	int i;

	h_matches = 0;
	i = 0;
	while (t[i] && i <= 6)
	{
		if ((i / 2) + 1 != hashnbr)
		{
			if (t[i + 1] == y)
			{
				if (t[i] == x || t[i] == (x + 1))
				{
					h_matches++;
				}
				else if (t[i] == (x - 1) && (x - 1) >= 0)
				{
					h_matches++;
				}
			}
		}
		i += 2;
	}
	return (0);
}

/*
** @desc -
** @param -
** @var -
*/

static int	ft_get_v_side_count(int *tetriminos, int x, int y, int hashnbr)
{
	int v_matches;
	int i;

	v_matches = 0;
	i = 0;
	while (tetriminos[i])
		i += 2;
	return (0);
}

/*
** @desc -
** @param -
** @var -
*/

static int	ft_get_side_count(int *tetriminos, int x, int y, int hashnbr)
{
	int sides;

	sides = ft_get_h_connections(tetriminos, x, y, hashnbr);
	sides += ft_get_v_connections(tetriminos, x, y, hashnbr);
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
			return (0);
		i++;
	}
	return (0);
}
