/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_hash_positions.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 08:11:23 by renslaros      #+#    #+#                */
/*   Updated: 2019/04/11 06:59:45 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_save_hash_positions(int t[][8], char *t_line, int y, int tcount)
{
	int			x;
	static int	i;

	x = 0;
	if (!i)
		i = 0;
	if (y >= 129)
		ft_handle_error(2);
	y = y % 5;
	while (t_line[x])
	{
		if (t_line[x] == '#')
		{
			t[tcount - 1][i] = x;
			t[tcount - 1][i + 1] = y;
			i += 2;
			if (i == 8)
				i = 0;
			x++;
		}
		else if (t_line[x] != '#' && t_line[x] == '.')
			x++;
		else
			ft_handle_error(2);
	}
}
