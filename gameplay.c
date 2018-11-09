/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:43:17 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/08 18:29:53 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** (i % 5) e za sekogas da imam broj na red 0 1 2 ili 3, bez razlika dali
** se procesirat 26tiot tetris ili tretot. a posle (i%5) se mnozit so 10
** i se dodavat x, zs taka sekogas prvata cifra ke e redot vtorata kolona
*/

void	play_tetris(char **tetris, t_board *board, t_filist **playlist)
{
	int			i;
	int			x;
	int			arr[4];
	int			el;

	i = 0;
	x = 0;
	el = 0;
	while (tetris[i])
	{
		while (tetris[i][x])
		{
			if (tetris[i][x] == '#')
				arr[el++] = (i % 5) * 10 + x;
			x++;
		}
		if (el == 4)
		{
			check_plays(arr, board, playlist);
			el = 0;
			board->t_id += 1;
		}
		i++;
		x = 0;
	}
}

void	scan_figures(char **tetris, t_board *board, t_fig *figures, t_filist **playlist)
{
	int			i;
	int			x;
	int			el;

	i = 0;
	x = 0;
	el = 0;
	while (figures)
	{
		while (tetris[i][x])
		{
			if (tetris[i][x] == '#')
				figures->cords[el++] = (i % 5) * 10 + x;
			x++;
		}
		if (el == 4)
		{
			board->t_id = figures->t_id;
			check_plays(figures->cords, board, playlist);
			figures = figures->next;
			el = 0;
		}
		i++;
		x = 0;
	}
}

void	check_plays(int arr[4], t_board *board, t_filist **playlist)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (row < board->side)
	{
		while (col < board->side)
		{
			if (check_after(arr, board, row, col) == 0)
				store_play(board, playlist);
			col++;
		}
		row++;
		col = 0;
	}
}

int		check_after(int arr[4], t_board *board, int row, int col)
{
	int htag;

	htag = 1;
	board->cords[0][0] = row;
	board->cords[1][0] = col;
	while (htag != 4)
	{
		if (arr[htag] / 10 != arr[htag - 1] / 10)
		{
			if (++row > board->side - 1)
				return (-1);
		}
		col = (arr[htag] % 10) - (arr[0] % 10) + board->cords[1][0];
		if (col > board->side - 1 || col < 0)
			return (-1);
		board->cords[0][htag] = row;
		board->cords[1][htag] = col;
		htag++;
	}
	return (0);
}

void	clean_playlist(t_filist **playlist)
{
	t_filist *temp;
	t_filist *temp_d;

	temp_d = (*playlist)->down;
	while (temp_d)
	{
		temp = temp_d;
		temp_d = temp_d->down;
		temp->down = NULL;
		free(temp);
		temp = NULL;
	}
	while (*playlist)
	{
		temp = *playlist;
		*playlist = (*playlist)->next;
		free(temp);
		temp = NULL;
	}
}

void	new_surface(t_board *board)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (i < board->side)
		free(board->result[i++]);
	i = 0;
	while (i < board->side)
	{
		if (!(board->result[i] = ft_strnew(board->side)))
			exit_app("Malloc inside new_surface failed");
		x = 0;
		while (x < board->side)
			board->result[i][x++] = '.';
		i++;
	}
	board->result[board->side] = NULL;
	board->t_id = 'A';
}
