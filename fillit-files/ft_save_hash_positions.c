/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_hash_positions.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 08:11:23 by renslaros      #+#    #+#                */
/*   Updated: 2019/04/07 06:20:48 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_save_hash_positions(
	int t[26][8],
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
		ft_handle_error(2);
	y = y % 5;
	while (tetri_line[x])
	{
		if (tetri_line[x] == '#' && t[tcount - 1][i]
			&& t[tcount - 1][i + 1])
		{
			t[tcount - 1][i] = x;
			t[tcount - 1][i + 1] = y;
			i += 2;
			x++;
		}
		else if (tetri_line[x] != '#' && tetri_line[x] == '.')
			x++;
		else
			ft_handle_error(2);
	}
}