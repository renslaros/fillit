/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_remove_tetri.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 17:55:03 by abumbier       #+#    #+#                */
/*   Updated: 2019/05/31 06:43:56 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - removes from the board the tetrimino which represents the current \
** tbox->tid value.
** @param t_tbox *tbox - structure with board and tindex values.
** @var int i and j - indexes to loop through the board to find the tetrimino.
** @var char repl - letter which represents the index of tetrimino to replace.
*/

void	ft_remove_tetri(t_tbox *tbox)
{
	int		i;
	int		j;
	char	repl;

	i = 0;
	j = 0;
	repl = 'A' + tbox->tid;
	while (tbox->board[i])
	{
		while (tbox->board[i][j] != '\n')
		{
			if (tbox->board[i][j] == repl)
				tbox->board[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}
