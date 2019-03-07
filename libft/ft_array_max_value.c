/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_array_max_value.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 21:01:10 by rlaros         #+#    #+#                */
/*   Updated: 2019/02/04 21:01:23 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the value of the array’s biggest element.
*/

int		ft_array_max_value(int *arr, int length)
{
	int		i;
	int		max;

	i = 0;
	max = 0;
	while (i < length)
	{
		if (max < arr[i])
			max = arr[i];
		i += 1;
	}
	return (max);
}
