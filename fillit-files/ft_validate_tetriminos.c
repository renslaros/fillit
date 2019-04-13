/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate_tetriminos.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 03:42:18 by rlaros         #+#    #+#                */
/*   Updated: 2019/04/13 04:15:53 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Counts the amount of X axis connections a given hash has.
** @param int t[8] - tetrimino x & y positions
** @param int x - X position of given #
** @param int x - Y position of given #
** @var int x_connections - amount of x connections the hash has with other #'s
** @var int i - iterator used to go over the tetrimino hashes
** @return int x_connections - Amount of x connections on received # found
*/

/*
** Loop as long as i isn't greater than 6.
** Increase iterator if we're checking the same hash against itself
** If not, increase x_connections if a X connection with the received # is found
** If hash isn't the same and connection isn't found, increase I anyway
*/

static int	ft_get_x_connections(int t[8], int x, int y)
{
	int x_connections;
	int i;

	x_connections = 0;
	i = 0;
	while (i <= 6)
	{
		if (t[i] == x && t[i + 1] == y)
			i += 2;
		else
		{
			if ((t[i] == x || t[i] == (x + 1)) ||
				(t[i] == (x - 1) && (x - 1) >= 0))
			{
				if (t[i + 1] == y)
					x_connections++;
			}
			i += 2;
		}
	}
	return (x_connections);
}

/*
** @desc - Counts the amount of Y axis connections a given hash has.
** @param int t[8] - tetrimino x & y positions
** @param int x - X position of given #
** @param int x - Y position of given #
** @var int y_connections - amount of y connections the hash has with other #'s
** @var int i - iterator used to go over the tetrimino hashes
** @return int y_connections - Amount of y connections on received # found
*/

/*
** Loop as long as i isn't greater than 6.
** Increase iterator if we're checking the same hash against itself
** If not, increase y_connections if a Y connection with the received # is found
** If hash isn't the same and connection isn't found, increase I anyway
*/

static int	ft_get_y_connections(int t[8], int x, int y)
{
	int y_connections;
	int i;

	y_connections = 0;
	i = 0;
	while (i <= 6)
	{
		if (t[i] == x && t[i + 1] == y)
			i += 2;
		else
		{
			if ((t[i + 1] == y || t[i + 1] == (y + 1)) ||
				(t[i + 1] == (y - 1) && (y - 1) >= 0))
			{
				if (t[i] == x)
					y_connections++;
			}
			i += 2;
		}
	}
	return (y_connections);
}

/*
** @desc - Counts and returns the amount of X&Y connections found for a given #
** @param int t[8] - tetrimino x & y positions
** @param int x - X position of given #
** @param int x - Y position of given #
** @return int - sum of returned x & y connections
*/

static int	ft_get_side_count(int t[8], int x, int y)
{
	return (ft_get_x_connections(t, x, y) + ft_get_y_connections(t, x, y));
}

/*
** @desc - Validates if the received X/Y positions are valid for all tetriminos
** @param int t[][8] - 2d tetrimino array holding # X & Y positions
** @param int tcount - tetrimino counter (Amount of tetriminos we have)
** @var int i - iterator used to loop over all tetrimino hashes
** @var int j - iterator used to loop over all tetrimino X positions
** @var int sides - amount of sides on which each # in the tetrimino connects
*/

/*
** Loop over all tetriminos
** Loop over all hashes in a tetrimino and get the amount of sideconnections
** If the sideconnections of a tetrimino isn't 6 or 8 and we're done looping
** Return 0
** Reset sides and tetrimino hash iterator
** Increase tetriminos iterator to go over the next tetrimino
** If we looped through all tetriminos without finding invalid sideconnections
** Return 1
*/

int			ft_validate_tetriminos(int t[26][8], int tcount)
{
	int i;
	int j;
	int sides;

	i = 0;
	j = 0;
	sides = 0;
	while (t[i] && i < tcount)
	{
		while (j <= 6)
		{
			sides += ft_get_side_count(t[i], t[i][j], t[i][j + 1]);
			j += 2;
		}
		if (sides != 6 && sides != 8)
			return (0);
		sides = 0;
		j = 0;
		i++;
	}
	return (1);
}
