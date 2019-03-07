/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wordlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 20:45:49 by rlaros         #+#    #+#                */
/*   Updated: 2019/02/04 20:45:54 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Find the length of a word, using the variable c as a separator between words.
*/

size_t		ft_wordlen(const char *s, char c)
{
	unsigned int	i;
	size_t			len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i += 1;
	while (s[i] != c && s[i++])
		len += 1;
	return (len);
}
