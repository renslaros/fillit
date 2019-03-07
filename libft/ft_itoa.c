/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:17:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/02/04 03:44:21 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_len(int n)
{
	size_t len;

	len = 0;
	if (n < 0)
	{
		len++;
	}
	while (n % 10 != n)
	{
		len++;
		n = n / 10;
	}
	len++;
	return (len);
}

static	void	ft_fill(char *number, int j, int n)
{
	static	int	i;

	i = j;
	if (n % 10 == n)
	{
		number[i] = n + 48;
		i++;
	}
	else
	{
		ft_fill(number, i, n / 10);
		number[i] = (n % 10) + 48;
		i++;
	}
}

char			*ft_itoa(int n)
{
	int			i;
	size_t		len;
	char		*number;

	i = 0;
	len = ft_len(n);
	number = (char *)malloc(len + 1);
	if (!number)
		return (NULL);
	if (n < 0)
	{
		number[i] = '-';
		i++;
		if (n == -2147483648)
		{
			number[10] = '8';
			n = n / 10;
		}
		n = -n;
	}
	ft_fill(number, i, n);
	number[len] = '\0';
	return (number);
}
