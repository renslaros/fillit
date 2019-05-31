/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_tetri.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 17:54:40 by abumbier       #+#    #+#                */
/*   Updated: 2019/05/31 06:37:47 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Replaces point with a letter that represents tetrimino \
** in its respective place.
** @param int tetri[][6] - int 2d array that holds representations of \
** validated tetriminos.
** @param t_tbox *tbox - ptr to t_tbox struct which will hold most of \
** the necessary variables for board manipulation.
*/

void	ft_put_tetri(int tetri[][6], t_tbox *tbox)
{
	tbox->board[tbox->xy[0]][tbox->xy[1]] = 'A' + tbox->tid;
	tbox->board[tbox->xy[0] + tetri[tbox->tid][0]][tbox->xy[1] + \
	tetri[tbox->tid][1]] = 'A' + tbox->tid;
	tbox->board[tbox->xy[0] + tetri[tbox->tid][2]][tbox->xy[1] + \
	tetri[tbox->tid][3]] = 'A' + tbox->tid;
	tbox->board[tbox->xy[0] + tetri[tbox->tid][4]][tbox->xy[1] + \
	tetri[tbox->tid][5]] = 'A' + tbox->tid;
}
