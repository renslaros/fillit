/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_and_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 08:11:51 by renslaros         #+#    #+#             */
/*   Updated: 2019/05/07 13:53:41 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** @desc - Validates received input such as filedescriptor 2d array & buffsize
** @param int fd - Filedescriptor to read tetriminios from
** @param int t[][8] - 2d tetrimino array holding # X & Y positions
** @param int *tcount - pointer to tetrimino counter
*/

/*
** return error and exit program if one of the conditions below are met
*/

void		ft_validate_input(int fd, int t[][8], int *tcount)
{
	if (fd < 0 || BUFF_SIZE < 1 || !t || !tcount)
		ft_handle_error(2);
}

/*
** @desc - Updates the tetrimino counter based on y index.
** @param int *tcount - pointer to tetrimino counter
** @param int y - current y index used as iterator while reading t_lines
*/

static void	ft_update_tetri_count(int *t_count, int y)
{
	y++;
	if (y % 5 == 0)
		*t_count = y / 5;
	else
		*t_count = (y / 5) + 1;
}

/*
** @desc - Saves and validates the given tetrimino input
** @param int fd - Filedescriptor to read tetriminios from
** @param int t[][8] - 2d tetrimino array holding # X & Y positions
** @param int *tcount - pointer to tetrimino counter
** @var char *tetri_line - line holder passed to GNL
** @var int y - row counter
** return - int 0 if reading went unsuccessfull
** return - int 1 if reading was successfull
*/

/*
** Validate fd, buff size & received 2d tetrimino array. Return 0 if invalid
** Loop over each line from the received tetrimino input
** Update the tetri counter on each iteration
** If the line is invalid we return 0
** Otherwise we save the hashes in the line and increase y
** If we're done validating & reading all lines as well as saving the #'s
** We make sure the hashes we stored are valid tetriminos
** if so the validator returns 1 and we return 1, if not we return 0
*/

int			ft_save_and_validate(int fd, int t[][8], int *tcount)
{
	char	*tetri_line;
	int		y;

	y = 0;
	ft_validate_input(fd, t, tcount);
	while (ft_get_next_line(fd, &tetri_line) == 1)
	{
		ft_update_tetri_count(tcount, y);
		if (!ft_validate_line(tetri_line, y))
		{
			free(tetri_line);
			return (0);
		}
		ft_save_hash_positions(t, tetri_line, y, *tcount);
		free(tetri_line);
		y++;
	}
	if (!ft_validate_line(tetri_line, y))
	{
		free(tetri_line);
		return (0);
	}
	free(tetri_line);
	return (ft_validate_tetriminos(t, *tcount) ? 1 : 0);
}
