/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 22:24:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/04/15 19:21:30 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Validates & Fills tetriminios as the smallest possible square
** @param int argc - Argument counter
** @param char **argv - arguments as 2d string array
** @var int tetriminos[][8] - 2d tetrimino array holding # X & Y positions
** @var int tcount - tetrimino counter
** @return 0 when program is finished
*/

/*
** Return Error if argument count is invalid
** Call the setup method and start solving if the setup went successfull (1)
** If setup doesn't return 1 return an error
*/

int		main(int argc, char **argv)
{
	int	tetriminos[MAX_TETRIMINOS][8];
	int	tcount;
	t_tbox	*tbox;

	tcount = 1;
	if (argc != 2)
		ft_handle_error(1);
	if (ft_setup(argv, tetriminos, &tcount))
	{
		tbox = ft_make_tbox(tcount);
		tbox->board = ft_make_board(tbox);
		ft_fillit_solve(ft_convert(tetriminos), tbox);
		ft_print_board(tbox->board);
	}
	else
		ft_handle_error(2);
	return (0);
}
