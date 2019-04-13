/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 22:24:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/04/13 03:20:48 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Validates & Fills tetriminios as the smallest possible square
** @param int argc - A
** @param char **argv - 
** @var
** @return 
*/

int		main(int argc, char **argv)
{
	int	tetriminos[MAX_TETRIMINOS][8];
	int	tcount;

	tcount = 1;
	if (argc != 2)
		ft_handle_error(1);
	if (ft_setup(argv, tetriminos, &tcount))
	{
		while (tcount)
		{			
			ft_putstr("###############################################################################################################\n");
			printf("Tetrimino %i: X1: [ %i ] Y1: [ %i ] ## X2: [ %i ] Y2: [ %i ] ## X3: [ %i ] Y3: [ %i ] ## X4: [ %i ] Y4: [ %i ] \n", tcount, tetriminos[tcount - 1][0], tetriminos[tcount - 1][1], tetriminos[tcount - 1][2], tetriminos[tcount - 1][3], tetriminos[tcount - 1][4], tetriminos[tcount - 1][5], tetriminos[tcount - 1][6], tetriminos[tcount - 1][7]);
			ft_putstr("###############################################################################################################\n");
			ft_putstr("\n");
			tcount--;
		}
		
	}
	else
		ft_handle_error(2);
	return (0);
}
