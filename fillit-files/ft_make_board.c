/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_board.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 17:53:54 by abumbier       #+#    #+#                */
/*   Updated: 2019/05/31 06:34:14 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Creates a board.
** @param t_tbox *tbox - ptr to t_tbox struct which will holds most of \
** the necessary variables for board manipulation.
** @var char **board - a 2d char array(2 by 2) which holds dots.
** @return char **board - incremented board.
*/

char		**ft_make_board(t_tbox *tbox)
{
	char	**board;

	board = (char**)malloc(sizeof(char*) * (4 + tbox->tcount));
	board[0] = (char*)malloc(4);
	board[1] = (char*)malloc(4);
	board[0] = ft_strcpy(board[0], "..\n");
	board[1] = ft_strcpy(board[1], "..\n");
	board[2] = NULL;
	while (ft_check_board_inc(board, tbox->tcount))
		ft_incr_board(board);
	tbox->end = ft_wordlen(board[0], '\n') - 1;
	return (board);
}
