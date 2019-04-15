#include <string.h>
#include "libft.h"
#include "fillit.h"

t_tbox	*ft_make_tbox(int tetri_count)
{
	t_tbox	*tbox;

	tbox = (t_tbox*)malloc(sizeof(t_tbox));
	tbox->tcount = tetri_count;
	tbox->tindex = 0;
	tbox->board = NULL;
	tbox->temp = 0;
	tbox->xy[0] = 0;
	tbox->xy[1] = 0;
	tbox->end = 0;
	return(tbox);
}

int		ft_fillit_solve(int tetri[][6], t_tbox *tbox)
{
	ft_no_space(tetri, tbox);
	ft_find_place(tetri, tbox);
	if (tbox->xy[0] == tbox->end && tbox->xy[1] == tbox->end)
	{
			
		if (tbox->tindex != 0)
			tbox->tindex--;
		ft_find_coordinates(tbox);
		tbox->xy[1]++;
		ft_no_space(tetri, tbox);
		ft_incr_condition(tbox);
		ft_remove_tetri(tbox);														// If end and no space go back tetrimino.
	}
	else
	{
		ft_put_tetri(tetri, tbox);
		tbox->tindex++;
		tbox->xy[0] = 0;
		tbox->xy[1] = 0;
		if (tbox->tindex == tbox->tcount)
			return (1);																// If not end then add tetri and start a new one + if end end.
	}
	ft_fillit_solve(tetri, tbox);
	// while (!ft_fillit_solve(tetri, tbox) && tbox->xy[1] <= tbox->end)
	// {
	// 	ft_find_coordinates(tbox);
	// 	tbox->xy[1]++;
	// 	ft_incr_condition(tbox);
	// 	tbox->temp++;
//		ft_fillit_solve(tetri, tbox);
//	}
	return (1);
}

int	main(void)
{
	t_tbox	*tbox;
//	int		tetri[9][6] = {{0, 1, 1, 1, 1, 0}, {0, 1, 0, 2, 1, 2}, {1, 0, 2, 0, 3, 0}, {1, 0, 2, 0, 2, 1}, \
	{1, 0, 2, 0, 2, 1}, {0, 1, 1, 1, 1, 0}, {0, 1, 0, 2, 1, 2}, {0, 1, 1, 1, 1, 2}, {0, 1, 1, 1, 1, 0}}; // [], ¬ , I , L, L, [], ¬, z, [], []
	int		tetri[3][6] = {{0, 1, 1, 1, 1, 0}, {0, 1, 0, 2, 0, 3}, {1, 0, 2, 0, 3, 0}};
//	int		tetri[8][6] = {{1, 0, 2, 0, 3, 0}, {0, 1, 0, 2, 0, 3}, {0, 1, 0, 2, 1, 2}, {1, 0, 1, -1, 0, 1}, \
	{0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 2}, {0, 1, 1, 1, 2, 1}, {0, 1, 1, 1, 0, 2}}; 						// 42 test.
//	int		tetri[4][6] = {{0, 1, 1, 1, 2, 1}, {0, 1, 0, 2, 0, 3}, {1, 0, 1, 1, 1, 2}, {0, 1, 1, 1, 1, 2}};
//	int		tetri[8][6] = {{1, 0, 2, 0, 3, 0}, {0, 1, 0, 2, 0, 3}, {0, 1, 0, 2, 1, 2}, {1, 0, 1, -1, 0, 1}, \
	{0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 2}, {0, 1, 1, 1, 2, 1}, {0, 1, 1, 1, 0, 2}};

	tbox = ft_make_tbox(3);
	tbox->board = ft_make_board(tbox);
	ft_fillit_solve(tetri, tbox);
	ft_print_board(tbox->board);

	return (0);
}
