/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 21:33:17 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/11 19:46:49 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_str(char *str, int n, int len)
{
	unsigned	temp;

	if (str == NULL)
		return (NULL);
	else if (n < 0)
	{
		str[0] = '-';
		temp = n * -1;
	}
	else
		temp = n;
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (temp)
	{
		str[len - 1] = (temp % 10) + '0';
		temp /= 10;
		len--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int			len;
	char		*str;

	if (n >= 0)
		len = ft_intlen(n);
	else
		len = ft_intlen(n) + 1;
	str = (char*)malloc(sizeof(char) * len + 1);
	return (get_str(str, n, len));
}
