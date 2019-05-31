/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:24:18 by abumbier          #+#    #+#             */
/*   Updated: 2019/04/29 18:25:04 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @desc: ft_strjoin which return value overwrites (without leaks) s1.
*/

char	*ft_stradd(char *s1, char const *s2)
{
	char	*str_temp;

	str_temp = ft_strdup(s1);
	if (s1 != NULL && ft_strcmp(s1, "") != 0)
		ft_strdel(&s1);
	s1 = ft_strjoin(str_temp, s2);
	ft_strdel(&str_temp);
	return (s1);
}
