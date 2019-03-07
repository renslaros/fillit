/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 13:31:03 by rlaros         #+#    #+#                */
/*   Updated: 2019/02/04 06:39:42 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int y;

	i = 0;
	y = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + y] == needle[y] && haystack[i + y] != '\0')
		{
			y++;
			if (needle[y] == '\0')
				return ((char *)haystack + i);
		}
		y = 0;
		i++;
	}
	return (NULL);
}
