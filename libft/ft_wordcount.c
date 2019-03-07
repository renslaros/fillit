/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wordcount.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 20:46:45 by rlaros         #+#    #+#                */
/*   Updated: 2019/02/04 20:46:48 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts the words found in a string (using the variable c as a separator).
*/

size_t		ft_wordcount(const char *s, char c)
{
	unsigned int	i;
	size_t			w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
			w += 1;
		while (s[i] != c && s[i + 1])
			i += 1;
		i += 1;
	}
	return (w);
}
