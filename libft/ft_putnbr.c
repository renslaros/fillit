/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:17:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/01/28 23:16:40 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int int_min;

	int_min = -2147483648;
	if (n == int_min)
		ft_putstr("-2147483648");
	if (n < 0 && n != int_min)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
	else if (n != int_min)
	{
		ft_putchar((n + 48));
	}
}
