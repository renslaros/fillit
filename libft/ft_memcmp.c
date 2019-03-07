/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:17:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/01/31 11:04:30 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return 0 if identical
** return difference of first differing bytes
** treat as unsigned char
** zero length strings are always identical
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uc1;
	unsigned char	*uc2;
	size_t			i;

	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	i = 0;
	while (i < n && uc1[i] == uc2[i])
		i++;
	if (i == n)
		return (0);
	return (uc1[i] - uc2[i]);
}
