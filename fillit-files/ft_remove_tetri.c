#include "libft.h"
#include "fillit.h"

void	ft_remove_tetri(t_tbox *tbox)
{
	int		i;
	int		j;
	char	repl;

	i = 0;
	j = 0;
	repl = 'A' + tbox->tindex;
	while (tbox->board[i])
	{
		while (tbox->board[i][j] != '\n')
		{
			if (tbox->board[i][j] == repl)
				tbox->board[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	
}

void	ft_reset_board(t_tbox *tbox)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tbox->board[i])
	{
		while (tbox->board[i][j] != '\n')
		{
			if (tbox->board[i][j] != '.')
				tbox->board[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	tbox->tindex = 0;
	tbox->xy[0] = 0;
	tbox->xy[1] = 0;
}