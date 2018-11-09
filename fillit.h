/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:41:19 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/06 20:41:20 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
#include "get_next_line.h"

# define FTABS(A) ((A) < 0 ? (-(A)) : (A))

typedef struct	s_fillit
{
	size_t	score;
	size_t	best_score;
	int		play_col;
	int		play_row;
	int		tem_col;
	int		tem_row;
}				t_fillit;

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
	char	t_id;
	int		cords[2][4];
	struct s_filist	*next;
	struct s_filist	*down;
}				t_filist;

void	search_for_sol(t_board *board, t_filist **playlist, t_filist **solutions, char **tetris);
void	clean_playlist(t_filist **playlist);
void	new_surface(t_board *board);
void	insert_in_list(t_filist **main_list, t_filist *newplay);
//void	copy_node2(t_filist **dest, t_filist *source);
//void	trim_solution(t_filist	*solution, t_board *board);
//t_filist	*find_best_solution(t_filist	*solutions);
void	fill_board(t_filist	*solutions, t_board *board);
void	clean_garbage(t_filist	**solution);
//int		compare_prev_solution(t_filist **org, t_filist *new_elem, t_filist **sol);
int		add_separator(t_filist **solutions);
int		copy_node(t_filist **dest, t_filist *source, int pieces);
int		compare_cords(t_filist	*solution, t_filist	*new_elem);
int		find_solution(t_board *board, t_filist *playlist, t_filist **solutions);
//void	put_down(t_filist *main_list, t_filist *new);
void	store_play(t_board *board, t_filist **main_list);
void	exit_app(const char *source);
int		ft_sqrt(int nb);
//void	insert_piece(int arr[4], t_board *board, t_fillit fil);
//void	get_score(int arr[4], int row, int col, t_fillit *fil);
int		check_after(int arr[4], t_board *board, int row, int col);
void	check_plays(int arr[4], t_board *board, t_filist **list);
void	play_tetris(char **tetris, t_board *board, t_filist **list);
int		check_sides(const char **tetris, int pos, int line, int start);
void	parse_tetris(const char *filepath, char **tetris, t_board *res_board);

#endif