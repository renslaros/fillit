/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_no_space.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 06:42:23 by rlaros         #+#    #+#                */
/*   Updated: 2019/05/31 06:42:25 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - If no space in board for any of the possible combinations: \
** resets board empty and increments board.
** @param t_tbox *tbox - ptr to t_tbox struct which will holds most of \
** the necessary variables for board manipulation.
*/

void	ft_no_space(t_tbox *tbox)
{
	if (tbox->tid == 0 && ((tbox->xy[0] >= tbox->end && \
	tbox->xy[1] >= tbox->end) || tbox->xy[0] > tbox->end))
	{
		ft_incr_board(tbox->board);
		tbox->end++;
		ft_reset_board(tbox);
		tbox->xy[0] = 0;
		tbox->xy[1] = 0;
	}
}
