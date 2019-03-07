/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_op.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 20:53:06 by rlaros         #+#    #+#                */
/*   Updated: 2019/02/04 20:53:09 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_do_op(int nbr1, int nbr2, char op)
{
	int	result;

	result = 0;
	if (op == '+')
		result = nbr1 + nbr2;
	else if (op == '-')
		result = nbr1 - nbr2;
	else if (op == '*')
		result = nbr1 * nbr2;
	else if (op == '/')
		result = (nbr2 != 0) ? (nbr1 / nbr2) : result;
	else if (op == '%')
		result = (nbr2 != 0) ? (nbr1 % nbr2) : result;
	return (result);
}
