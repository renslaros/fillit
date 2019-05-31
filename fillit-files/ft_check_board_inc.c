/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_board_inc.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 06:35:37 by rlaros         #+#    #+#                */
/*   Updated: 2019/05/31 06:35:45 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Checks if it is necessary to increase the board. Used in a loop.
** @param int tetri_count - number of validated tetriminos.
** @param char **board - table of points that represent a board on which \
** tetriminos are displayed.
** @var int i - '\n' character index in the board.
** @return 1 or 0 - depending whether it's necessary to increment the board.
*/

int		ft_check_board_inc(char **board, int tetri_count)
{
	int	i;

	i = ft_wordlen(board[0], '\n');
	if (tetri_count * 4 > i * i)
		return (1);
	return (0);
}
