/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reset_board.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 06:43:59 by rlaros         #+#    #+#                */
/*   Updated: 2019/05/31 06:44:07 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - resets the board to only dots.
** @param t_tbox *tbox - structure with board and tindex values.
** @var int i and j - to loop through the board.
*/

void	ft_reset_board(t_tbox *tbox)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tbox->board[i])
	{
		while (tbox->board[i][j] != '\n')
		{
			if (tbox->board[i][j] != '.')
				tbox->board[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	tbox->tid = 0;
	tbox->xy[0] = 0;
	tbox->xy[1] = 0;
}
