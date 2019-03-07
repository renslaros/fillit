/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 22:24:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/06 17:53:01 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Description of Main Function
** @param int argc -
** @param char **argv - 
** @var 
** @return 
*/

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_handle_error(1);	
	}
	
	if (ft_setup(argc, argv) == 1)
	{
		// Setup will call ft_validate and ft_configure()
		// Input is validated & configured  if ft_setup returns 1
		// ft_start() 
	}

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
*/