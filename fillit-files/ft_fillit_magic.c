#include <string.h>
#include "libft.h"
#include "fillit.h"

char	**make_board(int tetri_count);
char	**incr_board(char **board);
void	ft_print_board(char **board);
int		*ft_locate_tetri_space(int tetri[][6], char **board, int tetri_index, int *xy);
void	ft_put_tetri(int tetri[][6], char **board, int tetri_index, int *xy);
int		*ft_check_for_space(int tetri[][6], char **board, int tetri_index);
int		ft_check_incr(char **board, int tetri_count);

void	ft_fillit_magic()
{
	int 	tetri[5][6] = {{0, 1, 0, 2, 1, 2}, {1, 0, 2, 0, 3, 0}, {1, 0, 2, 0, 2, 1}, \
	{1, 0, 2, 0, 2, 1}, {0, 1, 1, 1, 1, 0}}; // ¬ , I , L, L, []
	int 	*x_y_val;
	char	**board;
//	int 	tetri[1][6] = {};
	int		tetri_index;
	int		tetri_count;

	tetri_count = 5;
	tetri_index = 0;
	board = make_board(tetri_count);
	if (board == NULL)
		ft_putstr("Make fail! \n");
	else
	{
		while (ft_check_incr(board, tetri_count))
			board = incr_board(board);
		while (tetri_index < tetri_count)
		{
			x_y_val = NULL;
			while (x_y_val == NULL)
			{
				x_y_val = ft_check_for_space(tetri, board, tetri_index);
				if (x_y_val == NULL)
				{
					board = incr_board(board);
					ft_putstr("\nIncr happened \n");
				}
				if (board == NULL)
				{
					ft_putstr("Epic increment fail! \n");
					break;
				}
			}
			ft_put_tetri(tetri, board, tetri_index, x_y_val);
			ft_putstr("\nTetri planted -_-\n");
			ft_print_board(board);
			tetri_index++;
		}
	}
}

/*
void	ft_fillit_solve(t_tbox *tbox, int tetri[][6])
{
	int *a;

	while (tbox->tindex < tbox->tcount)
	{
		if (a == NULL)
	}
}
*/
/*
** @desc -	checks if it is possible to place tetrimino in a board.
** @param - tetri_index - which tetrimino in a tetri[] array it is.
** @var - int xy[2] - xy[0] and xy[1] array that represents x and y values respectively.
** @return - either i with x and y values or -1 if there is no space.
*/

int		*ft_locate_tetri_space(int tetri[][6], char **board, int tetri_index, int *xy)
{
	if (board[xy[0] + tetri[tetri_index][0]] \
	&& board[xy[0] + tetri[tetri_index][0]][xy[1] + tetri[tetri_index][1]] \
	&& board[xy[0] + tetri[tetri_index][2]]	\
	&& board[xy[0] + tetri[tetri_index][2]][xy[1] + tetri[tetri_index][3]] \
	&& board[xy[0] + tetri[tetri_index][4]] \
	&& board[xy[0] + tetri[tetri_index][4]][xy[1] + tetri[tetri_index][5]] \
	&& board[xy[0] + tetri[tetri_index][0]][xy[1] + tetri[tetri_index][1]] == '.' \
	&& board[xy[0] + tetri[tetri_index][2]][xy[1] + tetri[tetri_index][3]] == '.' \
	&& board[xy[0] + tetri[tetri_index][4]][xy[1] + tetri[tetri_index][5]] == '.')
	{
		return (xy);
	}
	else
		return (NULL);
}

void	ft_put_tetri(int tetri[][6], char **board, int tetri_index, int *xy)
{
	board[xy[0]][xy[1]] = 'A' + tetri_index;
	board[xy[0] + tetri[tetri_index][0]][xy[1] + tetri[tetri_index][1]] = 'A' + tetri_index;
	board[xy[0] + tetri[tetri_index][2]][xy[1] + tetri[tetri_index][3]] = 'A' + tetri_index;
	board[xy[0] + tetri[tetri_index][4]][xy[1] + tetri[tetri_index][5]] = 'A' + tetri_index;
}

int		*ft_check_for_space(int tetri[][6], char **board, int tetri_index)
{
	static int	xy[2];
	int *ret;

	xy[0] = 0;
	xy[1] = 0;
	while (board && board[xy[0]] != NULL)
	{
		while (board[xy[0]][xy[1]] && board[xy[0]][xy[1]] != '.' && board[xy[0]][xy[1]] != '\n')
			xy[1]++;
		if (board[xy[0]][xy[1]] == '.')
		{
			ret = ft_locate_tetri_space(tetri, board, tetri_index, xy);
			if (ret != NULL)
				return (xy);
		}
		if (board[xy[0]][xy[1]] == '\n')
		{
			xy[0]++;
			xy[1] = 0;
		}
		else
			xy[1]++;
	}
	return (NULL);
}

/*
** @desc - Checks if it is necessary to increase the board. Can be used in a loop.
** @param -
** @var -  
** @return -
*/

int		ft_check_incr(char **board, int tetri_count)
{
	int	i;

	i = 0;
	while (board[0][i] != '\n')
		i++;
	if (tetri_count * 4 > i * i)
		return (1);
	return (0);
}

int	main(void)
{
	ft_fillit_magic();
}