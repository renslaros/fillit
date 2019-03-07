/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_array_min_value.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 21:01:10 by rlaros         #+#    #+#                */
/*   Updated: 2019/02/04 21:02:56 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the value of the array’s smallest element.
*/

int		ft_array_min_value(int *arr, int length)
{
	int		i;
	int		min;

	i = 0;
	min = 0;
	while (i < length)
	{
		if (min > arr[i])
			min = arr[i];
		i += 1;
	}
	return (min);
}
