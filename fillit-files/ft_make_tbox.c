/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_tbox.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 02:52:43 by rlaros         #+#    #+#                */
/*   Updated: 2019/05/31 02:52:46 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

/*
** @desc - populates tbox structure with correct initial values.
** @param int tetri_count - holds the number of tetriminos that were validated.
** @var t_tbox *tbox - ptr to t_tbox struct which will hold most of \
** the necessary variables for board manipulation.
** @return t_tbox *tbox - ptr to t_tbox struct which will hold most of \
** the necessary variables for board manipulation.
*/

t_tbox	*ft_make_tbox(int tetri_count)
{
	t_tbox	*tbox;

	tbox = (t_tbox*)malloc(sizeof(t_tbox));
	tbox->tcount = tetri_count;
	tbox->tid = 0;
	tbox->board = NULL;
	tbox->temp = 0;
	tbox->xy[0] = 0;
	tbox->xy[1] = 0;
	tbox->end = 0;
	return (tbox);
}
