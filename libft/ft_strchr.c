/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:17:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/02/20 16:56:22 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @desc Locates character in string
** @param const char *s - string pointer
** @param int c - ascii value of character to locate
** @return char * - pointer to located character
*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	chr;

	chr = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == (chr))
			return ((char *)&s[i]);
		i++;
	}
	if ((chr) == '\0' && s[i] == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
