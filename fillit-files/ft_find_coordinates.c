/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_coordinates.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 06:25:39 by rlaros         #+#    #+#                */
/*   Updated: 2019/05/31 06:26:18 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Finds the coordinates.
** @param t_tbox *tbox - ptr to t_tbox struct which will hold \
** the necessary variables for board manipulation.
** @return 1 or 0 - yes or no.
*/

int		ft_find_coordinates(t_tbox *tbox)
{
	tbox->xy[0] = 0;
	tbox->xy[1] = 0;
	while (tbox->board[tbox->xy[0]])
	{
		while (tbox->board[tbox->xy[0]][tbox->xy[1]] != '\n')
		{
			if (tbox->board[tbox->xy[0]][tbox->xy[1]] == 'A' + tbox->tid)
				return (1);
			tbox->xy[1]++;
		}
		tbox->xy[0]++;
		tbox->xy[1] = 0;
	}
	return (0);
}
