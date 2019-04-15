// #include "libft.h"
#include "fillit.h"

/*
** @desc - If no space in board for any of the possible combinations: resets board empty and increments board.
** @param - 
*/

void	ft_no_space(int tetri[][6], t_tbox *tbox)
{
	if (tbox->tindex == 0 && ((tbox->xy[0] >= tbox->end && tbox->xy[1] >= tbox->end) || tbox->xy[0] > tbox->end))
	{
	//	if (!ft_locate_tetri_space(tetri, tbox))
	//	{
		tbox->board = incr_board(tbox->board);
		tbox->end++;
		ft_reset_board(tbox);
		tbox->xy[0] = 0;
		tbox->xy[1] = 0;
	//	}
	}
}

/*
** @desc - Loops through board till the place for tetri is found or till the end is reached.
** @param - 
*/

void	ft_find_place(int tetri[][6], t_tbox *tbox)
{
	while (!ft_locate_tetri_space(tetri, tbox))
	{
		if (tbox->xy[0] >= tbox->end && tbox->xy[1] >= tbox->end)
			break;
		if (!ft_incr_condition(tbox))
			tbox->xy[1]++;
	}
}

/*
** @desc - 
** @param - 
*/

void	ft_solve_loop(int tetri[][6], t_tbox *tbox)
{
	while (!ft_fillit_solve(tetri, tbox) && tbox->xy[1] <= tbox->end)
	{
		ft_find_coordinates(tbox);
		tbox->xy[1]++;
		ft_incr_condition(tbox);
		ft_fillit_solve(tetri, tbox);
	}
}