/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 22:16:10 by rlaros         #+#    #+#                */
/*   Updated: 2019/04/15 17:53:47 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

/*
** Defenitions
*/
# define FILLIT_H
# define MAX_TETRIMINOS 26

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
	int		tindex;
	char	**board;
	int		temp;
}				t_tbox;


/*
** ERROR MESSAGES
*/
# define WRONG_USAGE "usage: ./fillit source_file\n"

/*
** Errorr handlers
*/
void	ft_handle_error(int error_code);

/*
** Fillit Setup
*/

int		ft_setup(char **argv, int t[][8], int *tcount);

/*
** Fillit Tetriminio input saving and validation
*/
int		ft_save_and_validate(int fd, int t[][8], int *tcount);

int		ft_validate_line(char *tetri_line, int y);
int		ft_validate_tetriminos(int t[][8], int tcount);
void	ft_save_hash_positions(int t[][8], char *t_line, int y, int tcount);

/*
** Arthur
*/
char	**ft_make_board(t_tbox *tbox);
char	**incr_board(char **board);
void	ft_print_board(char **board);
int		ft_locate_tetri_space(int tetri[][6], t_tbox *tbox);
void	ft_put_tetri(int tetri[][6], t_tbox *tbox);
int		*ft_check_for_space(int tetri[][6], t_tbox *tbox);
int		ft_check_incr(char **board, int tetri_count);
t_tbox	*ft_make_tbox(int tetri_count);
void	ft_reset_board(t_tbox *tbox);
void	ft_remove_tetri(t_tbox *tbox);
int		ft_incr_condition(t_tbox *tbox);
char	**ft_dup_board(t_tbox *tbox);
int		ft_find_coordinates(t_tbox *tbox);
void	ft_no_space(int tetri[][6], t_tbox *tbox);
void	ft_find_place(int tetri[][6], t_tbox *tbox);
void	ft_solve_loop(int tetri[][6], t_tbox *tbox);
int		ft_fillit_solve(int tetri[][6], t_tbox *tbox);
#endif
