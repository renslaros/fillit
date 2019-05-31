/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_board.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 03:01:04 by rlaros         #+#    #+#                */
/*   Updated: 2019/05/31 03:01:55 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Prints a board.
** @param char **board - table of points that represent a board on which \
** tetriminos are displayed.
*/

void		ft_print_board(char **board)
{
	int	j;

	j = 0;
	while (board[j] != NULL)
	{
		ft_putstr(board[j]);
		j++;
	}
}
