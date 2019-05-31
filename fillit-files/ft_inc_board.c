/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_inc_board.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 03:04:01 by rlaros         #+#    #+#                */
/*   Updated: 2019/05/31 03:04:43 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Adds last line of dots to board in ft_incr_board.
*/

static int	ft_add_line(char **board, int i, int a)
{
	int	j;

	j = 0;
	while (j <= a)
	{
		board[i][j] = '.';
		j++;
	}
	return (j);
}

/*
** @desc - Increments the boards field by (x + 1)^2 (dots) where x is the
** length of a side.
** @param char **board - table of points that represent a board on which \
** tetriminos are displayed.
** @var - a to save '\n' index.
** @var - i and j to loop through.
** @var char *point - to hold a pointer to "./n" string that will be added \
** at the end of line.
** @var - *temp to avoid memory leak.
** @return - board.
*/

void		ft_incr_board(char **board)
{
	int		a;
	int		i;
	int		j;
	char	*temp;
	char	*point;

	point = ".\n";
	a = ft_wordlen(board[0], '\n');
	i = 0;
	while (board[i] != NULL)
	{
		board[i][a] = '\0';
		temp = ft_strdup(board[i]);
		free(board[i]);
		board[i] = ft_strjoin(temp, point);
		free(temp);
		i++;
	}
	board[i] = (char*)malloc(a + 2);
	j = ft_add_line(board, i, a);
	board[i][j] = '\n';
	board[i][j + 1] = '\0';
	board[i + 1] = NULL;
}
