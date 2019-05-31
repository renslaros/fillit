/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_index_inc.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 06:38:05 by rlaros         #+#    #+#                */
/*   Updated: 2019/05/31 06:38:15 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Checks if it's necessary to increment index to a new line.
** @param t_tbox *tbox - ptr to t_tbox struct which will holds most of \
** the necessary variables for board manipulation.
** @return 1 or 0 - yes or no.
*/

int		ft_check_index_inc(t_tbox *tbox)
{
	if (tbox->board[tbox->xy[0]][tbox->xy[1]] == '\n')
	{
		tbox->xy[0]++;
		tbox->xy[1] = 0;
		return (1);
	}
	else
		return (0);
}
