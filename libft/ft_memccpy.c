/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:17:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/01/28 13:28:28 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		uc;
	unsigned char		*udst;
	const unsigned char	*usrc;

	i = 0;
	uc = (unsigned char)c;
	udst = dst;
	usrc = src;
	while (i < n)
	{
		udst[i] = usrc[i];
		if (uc == usrc[i])
			return (&udst[i + 1]);
		i++;
	}
	return (NULL);
}
