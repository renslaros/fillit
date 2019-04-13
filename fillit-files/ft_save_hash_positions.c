/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_hash_positions.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 08:11:23 by renslaros      #+#    #+#                */
/*   Updated: 2019/04/13 02:53:11 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Saves the X & Y positions of each hash found in t_line
** @param int t[][8] - 2d tetrimino array holding all X & Y positions
** @param int tcount - Amount of valid tetrimino's currently read
** @var int x - iterator looping over char *t_line to store x pos.
** @var static int i - iterator used to identify correct index to store X & Y
*/

/*
** Assign 0 to static int i if !i
** Exit program and return an error if the y index is to high. (MAX_TETRIMINOS)
** Convert Y to represent the real y index of a tetrimino # ( Row 0 / 3 )
** Loop over tetrimino line read by GNL using int X
** Store the X & Y positions if a # is found based on the tcount & i values
** Handle the I edge case to make sure we start at 0 again when needed
*/

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
		}
		x++;
	}
}
