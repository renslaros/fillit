/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_locate_tetri_space.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 03:06:22 by rlaros         #+#    #+#                */
/*   Updated: 2019/05/31 03:06:33 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - checks if it is possible to place tetrimino in a board.
** @param - tbox->tid - which tetrimino in a tetri[] array it is.
** @var - int xy[2] - xy[0] and xy[1] array that represents x and y values.
** @return - either i with x and y values or -1 if there is no space.
*/

int		ft_locate_tetri_space(int tetri[][6], t_tbox *tbox)
{
	if (tbox->board[tbox->xy[0]] && tbox->board[tbox->xy[0]][tbox->xy[1]] && \
	tbox->board[tbox->xy[0] + tetri[tbox->tid][0]] && tbox->board[tbox->xy[0]\
	+ tetri[tbox->tid][0]][tbox->xy[1] + tetri[tbox->tid][1]] && \
	tbox->board[tbox->xy[0] + tetri[tbox->tid][2]] && tbox->board[tbox->xy[0]\
	+ tetri[tbox->tid][2]][tbox->xy[1] + tetri[tbox->tid][3]] && \
	tbox->board[tbox->xy[0] + tetri[tbox->tid][4]] && tbox->board[tbox->xy[0]\
	+ tetri[tbox->tid][4]][tbox->xy[1] + tetri[tbox->tid][5]] && \
	tbox->board[tbox->xy[0]][tbox->xy[1]] == '.' && tbox->board[tbox->xy[0]\
	+ tetri[tbox->tid][0]][tbox->xy[1] + tetri[tbox->tid][1]] == '.' && \
	tbox->board[tbox->xy[0] + tetri[tbox->tid][2]][tbox->xy[1]\
	+ tetri[tbox->tid][3]] == '.' && tbox->board[tbox->xy[0]\
	+ tetri[tbox->tid][4]][tbox->xy[1] + tetri[tbox->tid][5]] == '.')
	{
		return (1);
	}
	else
		return (0);
}
