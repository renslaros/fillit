/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_solve_fillit.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 17:51:45 by abumbier       #+#    #+#                */
/*   Updated: 2019/05/31 06:37:23 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

/*
** @desc - main function which finds the most efficient way to display number \
** of tetriminos on square board. Function loops through the board while \
** placing tetriminos. If all the tetriminos are placed the function exits. \
** If there is no place then tbox->board is incremented and funct start again.
** @param int tetri[][6] - int 2d array that holds representations of \
** validated tetriminos.
** @param t_tbox *tbox - ptr to t_tbox struct which will hold most of \
** the necessary variables for board manipulation.
** @return 1 - to exit;
*/

int		ft_solve_fillit(int tetri[][6], t_tbox *tbox)
{
	while (tbox->tid != tbox->tcount)
	{
		ft_no_space(tbox);
		ft_find_place(tetri, tbox);
		if (tbox->xy[0] == tbox->end && tbox->xy[1] == tbox->end)
		{
			if (tbox->tid != 0)
				tbox->tid--;
			ft_find_coordinates(tbox);
			tbox->xy[1]++;
			ft_no_space(tbox);
			ft_check_index_inc(tbox);
			ft_remove_tetri(tbox);
		}
		else
		{
			ft_put_tetri(tetri, tbox);
			tbox->tid++;
			tbox->xy[0] = 0;
			tbox->xy[1] = 0;
			if (tbox->tid == tbox->tcount)
				return (1);
		}
	}
	return (1);
}
