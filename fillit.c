/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:50:38 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/08 18:34:48 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		init_board(t_board *board)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	if ((board->result = malloc(sizeof(char *) * ft_sqrt(26 * 4) + 1)) == NULL)
		exit_app("Malloc inside init_board failed");
	while (i < board->side)
	{
		if ((board->result[i] = ft_strnew(board->side)) == NULL)
			exit_app("Malloc inside init_board failed");
		x = 0;
		while (x < board->side)
			board->result[i][x++] = '.';
		i++;
	}
	board->result[board->side] = NULL;
	board->t_id = 'A';
}

void		init_fig(int pieces, t_fig **figures)
{
	int	i;
	char	c;
	t_fig	*temp;

	c = 'A';
	i = 0;
	if ((*figures = malloc(sizeof(t_fig))) == NULL)
		exit_app("Malloc inside init_fig failed");
	(*figures)->t_id = c;
	(*figures)->next = NULL;
	temp = *figures;
	while (++i < pieces)
	{
		temp->next = malloc(sizeof(t_fig));
		temp = temp->next;
		temp->t_id = ++c;
		temp->next = NULL;
	}
}

int			main(int argc, char **argv)
{
	char		**tetris;
	int			i;
	t_board		*res_board;
	t_filist	*playlist;
	t_filist	*solutions;
	t_fig		*figures;

	if (argc != 2)
		exit_app("usage: fillit target_file");
	i = 0;
	playlist = NULL;
	solutions = NULL;
	figures = NULL;
	res_board = malloc(sizeof(t_board));
	tetris = malloc(sizeof(char*) * 26 * 5);
	if (!res_board || !tetris)
		exit_app("Malloc failed");
	parse_tetris(argv[1], tetris, res_board);
	init_board(res_board);
	init_fig(res_board->pieces, &figures);
	scan_figures(tetris, res_board, figures, &playlist);

	//play_tetris(tetris, res_board, &playlist);
	search_for_sol(res_board, &playlist, &solutions, figures);
	fill_board(solutions, res_board);
	while (i < res_board->side)
		b_printf("%s\n", res_board->result[i++]);
	return (0);
}

// void		search_for_sol(t_board *board, t_filist **playlist,
// t_filist **solutions, char **tetris)
// {
// 	//scan_figures
// 	while (find_solution(board, *playlist, solutions) == 0)
// 	{
// 		board->side++;
// 		new_surface(board);
// 		clean_playlist(playlist);
// 		play_tetris(tetris, board, playlist);
// 	}
// }

void		search_for_sol(t_board *board, t_filist **playlist,
t_filist **solutions, t_fig *figures)
{
	t_fig *head;

	head = figures;
	while (find_solution(board, *playlist, solutions) == 0)
	{
		board->side++;
		new_surface(board);
		clean_playlist(playlist);
		while (figures)
		{
			board->t_id = figures->t_id;
			check_plays(figures->cords, board, playlist);
			figures = figures->next;
		}
		figures = head;
		//play_tetris(tetris, board, playlist);
	}
}
