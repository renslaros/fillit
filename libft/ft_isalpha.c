/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:17:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/07 04:24:09 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_isupper(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

static	int	ft_islower(int c)
{
	if ((c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int			ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}
