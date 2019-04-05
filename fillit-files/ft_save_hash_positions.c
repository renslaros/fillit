/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_hash_positions.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 19:37:48 by renslaros      #+#    #+#                */
/*   Updated: 2019/04/05 03:58:05 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_save_hash_positions(
	int **tetriminos,
	char *tetri_line,
	int y,
	int tcount
)
{
	int x;
	int i;

	x = 0;
	i = 0;
	if (y >= 129)
		return (0);
	y = y % 5;
	while (tetri_line[x])
	{
		if (tetri_line[x] == '#' && tetriminos[tcount - 1][i]
			&& tetriminos[tcount - 1][i + 1])
		{
			tetriminos[tcount - 1][i] = x;
			tetriminos[tcount - 1][i + 1] = y;
			i += 2;
			x++;
		}
		else if (tetri_line[x] != '#' && tetri_line[x] == '.')
			x++;
		else
			return (0);
	}
}
