/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 22:16:10 by rlaros         #+#    #+#                */
/*   Updated: 2019/05/31 06:36:25 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

/*
** Defenitions
*/
# define FILLIT_H
# define MAX_TETRIMINOS 26
# define WRONG_USAGE "usage: ./fillit source_file\n"

/*
** Headers
*/
# include "../libft/includes/libft.h"
# include <fcntl.h>

/*
** Typedefinitions
*/
typedef struct	s_tbox
{
	int		end;
	int		xy[2];
	int		tcount;
	int		tid;
	char	**board;
	int		temp;
}				t_tbox;

/*
** Errorr handlers
*/
void			ft_handle_error(int error_code);

/*
** Fillit Setup
*/

int				ft_setup(char **argv, int t[][8], int *tcount);

/*
** Fillit Tetriminio input saving and validation
*/
int				ft_save_and_validate(int fd, int t[][8], int *tcount);

int				ft_validate_line(char *tetri_line, int y);
int				ft_validate_tetriminos(int t[][8], int tcount);
void			ft_save_hash_positions(int t[][8],
				char *t_line, int y, int tcount);

/*
** Arthur
*/
char			**ft_make_board(t_tbox *tbox);
void			ft_incr_board(char **board);
void			ft_print_board(char **board);
int				ft_locate_tetri_space(int tetri[][6], t_tbox *tbox);
void			ft_put_tetri(int tetri[][6], t_tbox *tbox);
int				*ft_check_for_space(int tetri[][6], t_tbox *tbox);
int				ft_check_board_inc(char **board, int tetri_count);
t_tbox			*ft_make_tbox(int tetri_count);
void			ft_reset_board(t_tbox *tbox);
void			ft_remove_tetri(t_tbox *tbox);
int				ft_check_index_inc(t_tbox *tbox);
int				ft_find_coordinates(t_tbox *tbox);
void			ft_no_space(t_tbox *tbox);
void			ft_find_place(int tetri[][6], t_tbox *tbox);
int				ft_solve_fillit(int tetri[][6], t_tbox *tbox);
int				ft_convert(int tetriminos[][8], int tcount, int tetri[][6]);

#endif
