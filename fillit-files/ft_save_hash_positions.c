/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_hash_positions.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: renslaros <renslaros@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 19:37:48 by renslaros      #+#    #+#                */
/*   Updated: 2019/04/04 23:27:35 by renslaros     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_save_hash_positions(
	int **tetriminios,
	char *tetri_line,
	int y,
	int *tcount
)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (tetri_line[x])
	{
		if (tetri_line[x] == '#' && tetriminios[*tcount - 1][i]
			&& tetriminios[*tcount - 1][i + 1])
		{
			tetriminios[*tcount - 1][i] = x;
			tetriminios[*tcount - 1][i + 1] = y;
			i += 2;
			x++;
		}
		else if (tetri_line[x] != '#' && tetri_line[x] == '.')
			x++;
		else
			return (0);
	}
}