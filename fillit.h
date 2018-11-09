/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:41:19 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/08 19:00:26 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_board
{
	char	**result;
	int		side;
	int		cords[2][4];
	char	t_id;
	int		pieces;
}				t_board;

typedef struct	s_filist
{
	char			t_id;
	int				cords[2][4];
	struct s_filist	*next;
	struct s_filist	*down;
}				t_filist;

typedef struct	s_fig
{
	char			t_id;
	int				cords[4];
	struct s_fig	*next;
}				t_fig;

void			scan_figures(char **tetris, t_board *board, t_fig *figures,
							t_filist **playlist);
void			search_for_sol(t_board *board, t_filist **playlist,
						t_filist **solutions, t_fig *figures);
void			clean_playlist(t_filist **playlist);
void			new_surface(t_board *board);
void			insert_in_list(t_filist **main_list, t_filist *newplay);
void			fill_n_print(t_filist	*solutions, t_board *board);
void			clean_garbage(t_filist	**solution);
int				add_separator(t_filist **solutions);
int				copy_node(t_filist **dest, t_filist *source, int pieces);
int				compare_cords(t_filist	*solution, t_filist	*new_elem);
int				find_solution(t_board *board, t_filist *playlist,
								t_filist **solutions);
void			store_play(t_board *board, t_filist **main_list);
void			exit_app(const char *source);
int				ft_sqrt(int nb);
int				check_after(int arr[4], t_board *board, int row, int col);
void			check_plays(int arr[4], t_board *board, t_filist **list);
int				check_sides(const char **tetris, int pos, int line, int start);
void			parse_tetris(const char *filepath, char **tetris,
							t_board *res_board);

#endif
