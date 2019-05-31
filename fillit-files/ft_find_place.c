/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_solve_funct.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 17:55:30 by abumbier       #+#    #+#                */
/*   Updated: 2019/05/31 06:42:40 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Loops through board till the place for tetri is found or \
** till the end is reached.
** @param int tetri[][6] - int 2d array that holds representations of \
** validated tetriminos.
** @param t_tbox *tbox - ptr to t_tbox struct which will hold most of \
** the necessary variables for board manipulation.
*/

void	ft_find_place(int tetri[][6], t_tbox *tbox)
{
	while (!ft_locate_tetri_space(tetri, tbox))
	{
		if (tbox->xy[0] >= tbox->end && tbox->xy[1] >= tbox->end)
			break ;
		if (!ft_check_index_inc(tbox))
			tbox->xy[1]++;
	}
}
