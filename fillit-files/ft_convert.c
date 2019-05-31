/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:51:16 by abumbier          #+#    #+#             */
/*   Updated: 2019/04/22 17:02:15 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @desc - convertes validated tetri x and y indexes to the vectors for \
** ft_fillit_solve.
** @param int tetriminos[][8] - x and y values of the validated tetriminos.
** @param int tcount - number of validated tetriminos.
** @param int tetri[][6] - 2d int array that will hold tetrimino vectors.
** @var int i - to loop through all the tetriminos.
*/

void	ft_convert(int tetriminos[][8], int tcount, int tetri[][6])
{
	int	i;

	i = 0;
	while (i < tcount)
	{
		tetri[i][0] = tetriminos[i][3] - tetriminos[i][1];
		tetri[i][1] = tetriminos[i][2] - tetriminos[i][0];
		tetri[i][2] = tetriminos[i][5] - tetriminos[i][1];
		tetri[i][3] = tetriminos[i][4] - tetriminos[i][0];
		tetri[i][4] = tetriminos[i][7] - tetriminos[i][1];
		tetri[i][5] = tetriminos[i][6] - tetriminos[i][0];
		i++;
	}
}
