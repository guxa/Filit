/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:43:17 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/03 21:04:00 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** (i % 5) e za sekogas da imam broj na red 0 1 2 ili 3, bez razlika dali
** se procesirat 26tiot tetris ili tretot. a posle (i%5) se mnozit so 10
** i se dodavat x, zs taka sekogas prvata cifra ke e redot vtorata kolona 
*/

void	play_tetris(char **tetris, t_board *board)
{
	int			i;
	int			x;
	int			arr[4];
	int			el;

	i = 0;
	x = 0;
	el = 0;
	while (tetris[i]) //(el != 4) // || (i + 1) % 5 != 0) //ova drugava proverka so i mozda in e trebit ovde
	{
		while (tetris[i][x])
		{
			if (tetris[i][x] == '#')
				arr[el++] = (i % 5) * 10 + x;
			x++;
		}
		if (el == 4)
			check_plays(arr, board);
		if (el == 4)
			el = 0;
		i++;
		x = 0;
	}
}

void	check_plays(int arr[4], t_board *board)
{
	int row;
	int col;
	t_fillit	fil;

	row = 0;
	col = 0;
	fil.best_score = INT_MAX;
	while (row < board->side)
	{
		while (col < board->side)
		{
			if (board->result[row][col] == '.')
			{
				if (check_after(arr, board, row, col) == 0)
					get_score(arr, row, col, &fil);
			}
			col++;
		}
		row++;
		col = 0;
	}
	if (fil.best_score != INT_MAX)
		insert_piece(arr, board, fil);
	else
		b_printf("piece not played\n");
	//b_printf("High score: -> row %d  columns: %d\n", fil.play_row, fil.play_col);
}

int		check_after(int arr[4], t_board *board, int row, int col)
{
	int htag;
	int start_col;

	htag = 1;
	start_col = col;
	while (htag != 4)
	{
		if (arr[htag] / 10 != arr[htag - 1] / 10)
		{
			if (++row > board->side - 1)
				return (-1);
		}
		col = (arr[htag] % 10) - (arr[0] % 10) + start_col;
		if (col > board->side - 1 || col < 0)
			return (-1);
		if (board->result[row][col] != '.') // or is letter /alpha
			return (-1);
		htag++;
	}
	return (0);
}

void	get_score(int arr[4], int row, int col, t_fillit *fil)
{
	int		htag;
	size_t	score;
	int		start_col;

	score = row + col;
	htag = 1;
	start_col = 0;
	fil->tem_col = col;
	fil->tem_row = row;
	while (htag != 4)
	{
		if (arr[htag] / 10 != arr[htag - 1] / 10)
			row++;
		col = (arr[htag] % 10) - (arr[0] % 10) + start_col;
		score += row + col;
		htag++;
	}
	if (score < fil->best_score)
	{
		fil->best_score = score;
		fil->play_col = fil->tem_col;
		fil->play_row = fil->tem_row;
	}
}

void	insert_piece(int arr[4], t_board *board, t_fillit fil)
{
	int			htag;
	int			start_col;
	static char	c = 'A';

	//c = 'A';
	htag = 1;
	board->result[fil.play_row][fil.play_col] = c;
	start_col = fil.play_col;
	while (htag != 4)
	{
		if (arr[htag] / 10 != arr[htag - 1] / 10)
			fil.play_row++;
		fil.play_col = (arr[htag] % 10) - (arr[0] % 10) + start_col;
		board->result[fil.play_row][fil.play_col] = c;
		htag++;
	}
	c++;
}

		// x = (arr[htag] % 10) + fil.play_col;
		// y = (arr[htag] / 10) + fil.play_row;