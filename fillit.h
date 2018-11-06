/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:41:19 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/05 23:17:13 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
#include "get_next_line.h"

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

void	trim_solution(t_filist	*solution, t_board *board);
t_filist	*find_best_solution(t_filist	*solutions);
void	fill_board(t_filist	*solutions, t_board *board);
void	clean_garbage(t_filist	**solution);
int		compare_prev_solution(t_filist **org, t_filist *new_elem, t_filist **sol);
int		add_separator(t_filist **solutions);
int		copy_node(t_filist **dest, t_filist *source, int pieces);
int		compare_cords(t_filist	*solution, t_filist	*new_elem);
void	find_solution(t_board *board, t_filist *playlist, t_filist	*org, t_filist **solutions);
void	put_down(t_filist *main_list, t_filist *new);
void	store_play(t_board *board, t_filist **main_list);
void	exit_app(const char *source);
void	store_play(t_board *board, t_filist **list);
int		ft_sqrt(int nb);
void	insert_piece(int arr[4], t_board *board, t_fillit fil);
void	get_score(int arr[4], int row, int col, t_fillit *fil);
int		check_after(int arr[4], t_board *board, int row, int col);
void	check_plays(int arr[4], t_board *board, t_filist **list);
void	play_tetris(char **tetris, t_board *board, t_filist **list);
void	parse_tetris(const char *filepath, char **tetris, t_board *res_board);

#endif