/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char_count.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 20:44:47 by rlaros         #+#    #+#                */
/*   Updated: 2019/02/04 20:44:51 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the total number of characters in a set of words.
** For example, a two word set, like: [Hello][World], returns 10.
*/

size_t		ft_char_count(char **values)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (values[i] != NULL)
		j += ft_strlen(values[i++]);
	i -= 1;
	return (i + j);
}
