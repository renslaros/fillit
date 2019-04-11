/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 22:24:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/04/11 05:50:36 by rlaros        ########   odam.nl         */
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
		printf("Tetrimino 1: X1: [ %i ] Y1: [ %i ] ## X2: [ %i ] Y2: [ %i ] ## X3: [ %i ] Y3: [ %i ] ## X4: [ %i ] Y4: [ %i ] ## \n", tetriminos[0][0], tetriminos[0][1], tetriminos[0][2], tetriminos[0][3], tetriminos[0][4], tetriminos[0][5], tetriminos[0][6], tetriminos[0][7]);
	ft_putstr("###################################################################################################\n");
	ft_putstr("\n");
	printf("Tetrimino 2: X1: [ %i ] Y1: [ %i ] ## X2: [ %i ] Y2: [ %i ] ## X3: [ %i ] Y3: [ %i ] ## X4: [ %i ] Y4: [ %i ] ## \n", tetriminos[1][0], tetriminos[1][1], tetriminos[1][2], tetriminos[1][3], tetriminos[1][4], tetriminos[1][5], tetriminos[1][6], tetriminos[1][7]);
	ft_putstr("###################################################################################################\n");
	ft_putstr("\n");
	printf("Tetrimino 3: X1: [ %i ] Y1: [ %i ] ## X2: [ %i ] Y2: [ %i ] ## X3: [ %i ] Y3: [ %i ] ## X4: [ %i ] Y4: [ %i ] ## \n", tetriminos[2][0], tetriminos[2][1], tetriminos[2][2], tetriminos[2][3], tetriminos[2][4], tetriminos[2][5], tetriminos[2][6], tetriminos[2][7]);
	ft_putstr("###################################################################################################\n");
	ft_putstr("\n");
	printf("Tetrimino 4: X1: [ %i ] Y1: [ %i ] ## X2: [ %i ] Y2: [ %i ] ## X3: [ %i ] Y3: [ %i ] ## X4: [ %i ] Y4: [ %i ] ## \n", tetriminos[3][0], tetriminos[3][1], tetriminos[3][2], tetriminos[3][3], tetriminos[3][4], tetriminos[3][5], tetriminos[3][6], tetriminos[3][7]);
	ft_putstr("###################################################################################################\n");
	ft_putstr("\n");
	printf("Tetrimino 5: X1: [ %i ] Y1: [ %i ] ## X2: [ %i ] Y2: [ %i ] ## X3: [ %i ] Y3: [ %i ] ## X4: [ %i ] Y4: [ %i ] ## \n", tetriminos[4][0], tetriminos[4][1], tetriminos[4][2], tetriminos[4][3], tetriminos[4][4], tetriminos[4][5], tetriminos[4][6], tetriminos[4][7]);
	ft_putstr("###################################################################################################\n");
	ft_putstr("\n");
	printf("Tetrimino 6: X1: [ %i ] Y1: [ %i ] ## X2: [ %i ] Y2: [ %i ] ## X3: [ %i ] Y3: [ %i ] ## X4: [ %i ] Y4: [ %i ] ## \n", tetriminos[5][0], tetriminos[5][1], tetriminos[5][2], tetriminos[5][3], tetriminos[5][4], tetriminos[5][5], tetriminos[5][6], tetriminos[5][7]);
	ft_putstr("###################################################################################################\n");
	ft_putstr("\n");
	}
	else
		ft_handle_error(2);
	(void) argv;
	return (0);
}

/*
Todo's made by vincent / jamie
- usage if arg != 2

- check input
    between 1 - 26 tetriminos.
    20 char per tetriminos containing . # \n.
    4 chars need to be #.
    the # needs to be connected to at least one other #.
    the tetriminos needs to be seperated by \n.

- solve square
    make the smallest possible square.
    the tetriminos can not rotate while solving.
    first tetriminos needs to be placed first. -> ??
    when more possibilties in a square testriminos should be placed in the most upperleft position.

- output
    the smallest square
    assigned every tetrimino a capital letter.
    first tetrimino 'A' second 'B' and so on.

*/

/*
** ####################
** Allowed Functions
** ####################
** exit, open, close, write, read, malloc and free



tetrimino[0][X] 8
....
#### 
....
....
tetrimino[0][0] Slaat X positie op van 1e hash in 1e tetrimino
tetrimino[0][1] Slaat Y positie op van 1e hash in 1e tetrimino
tetrimino[0][2] Slaat X positie op van 1e hash in 1e tetrimino
tetrimino[0][3] Slaat Y positie op van 1e hash in 1e tetrimino
tetrimino[0][4] Slaat X positie op van 1e hash in 1e tetrimino
tetrimino[0][5] Slaat Y positie op van 1e hash in 1e tetrimino
tetrimino[0][6] Slaat X positie op van 1e hash in 1e tetrimino
tetrimino[0][7] Slaat Y positie op van 1e hash in 1e tetrimino

tetrimino[1][X] 8
...#
...#
...#
...#
tetrimino[1][0] Slaat X positie op van 1e hash in 1e tetrimino
tetrimino[1][1] Slaat X positie op van 1e hash in 1e tetrimino
tetrimino[1][2] Slaat X positie op van 1e hash in 1e tetrimino
tetrimino[1][3] Slaat X positie op van 1e hash in 1e tetrimino
tetrimino[1][4] Slaat X positie op van 1e hash in 1e tetrimino
tetrimino[1][5] Slaat X positie op van 1e hash in 1e tetrimino
tetrimino[1][6] Slaat X positie op van 1e hash in 1e tetrimino
tetrimino[1][7] Slaat X positie op van 1e hash in 1e tetrimino
*/