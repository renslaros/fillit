/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_hash_positions.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: renslaros <renslaros@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 19:37:48 by renslaros      #+#    #+#                */
/*   Updated: 2019/03/29 17:29:25 by renslaros     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_save_hash_positions(
	int **tetriminios, 
	char *tetri_line, 
	int y, 
	int *tetri_count
)
{
	int x;
	int i;
	
	x = 0;
	i = 0;
	while (tetri_line[x])
		{
			if (tetri_line[x] == '#' && tetriminios[*tetri_count - 1][i]
				&& tetriminios[*tetri_count - 1][i + 1])
			{
				tetriminios[*tetri_count - 1][i] = x;
				tetriminios[*tetri_count - 1][i + 1] = y;
				i += 2;
				x++;
			}
			else if (tetri_line[x] != '#')
				x++;
			else
				return (0);
		}
}