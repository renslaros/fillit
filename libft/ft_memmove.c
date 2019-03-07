/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:17:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/01/29 05:17:01 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ssrc;
	char	*ddst;
	int		i;

	ssrc = (char *)src;
	ddst = (char *)dst;
	i = 0;
	if (ssrc < ddst)
	{
		while ((int)len)
		{
			len--;
			ddst[len] = ssrc[len];
		}
	}
	else
	{
		while (i < (int)len)
		{
			ddst[i] = ssrc[i];
			i++;
		}
	}
	return (dst);
}
