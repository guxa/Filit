/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:43:17 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/03 18:35:32 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** (i % 5) e za sekogas da imam broj na red 0 1 2 ili 3, bez razlika dali
** se procesirat 26tiot tetris ili tretot. a posle (i%5) se mnozit so 10
** i se dodavat x, zs taka sekogas prvata cifra ke e redot vtorata kolona 
*/

void	play_tetris(char **tetris, char **result)
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
			check_plays(arr, result);
		if (el == 4)
			el = 0;
		i++;
		x = 0;
	}
}

void	check_plays(int arr[4], char **result)
{
	int row;
	int col;
	t_fillit	fil;

	row = 0;
	col = 0;
	fil.high_score = INT_MAX;
	while (row < 4)
	{
		while (col < 4)
		{
			if (result[row][col] == '.')
			{
				if (check_after(arr, result, row, col) == 0)
					if ((fil.score = get_score(arr, row, col)) < fil.high_score)
					{
						fil.high_score = fil.score;
						fil.play_col = col;
						fil.play_row = row;
					}
			}
			col++;
		}
		row++;
		col = 0;
	}
	if (fil.high_score != INT_MAX)
		insert_piece(result, arr, fil);
	//b_printf("High score: -> row %d  columns: %d\n", fil.play_row, fil.play_col);
}

int		check_after(int arr[4], char **result, int row, int col)
{
	int htag;
	int start_col;

	htag = 1;
	start_col = col;
	while (htag != 4)
	{
		if (arr[htag] / 10 != arr[htag - 1] / 10)
		{
			if (++row > 3)
				return (-1);
		}
		col = (arr[htag] % 10) - (arr[0] % 10) + start_col;
		if (col > 3 || col < 0)
			return (-1);
		if (result[row][col] != '.') // or is letter /alpha
			return (-1);
		htag++;
	}
	return (0);
}

int		get_score(int arr[4], int row, int col)
{
	int		htag;
	int		score;
	int		start_col;

	score = row + col;
	htag = 1;
	start_col = 0;
	while (htag != 4)
	{
		if (arr[htag] / 10 != arr[htag - 1] / 10)
			row++;
		col = (arr[htag] % 10) - (arr[0] % 10) + start_col;
		score += row + col;
		htag++;
	}
	return (score + 1); // ova + 1 zs high score se inic na 0 pa da ne
}

void	insert_piece(char **result, int arr[4], t_fillit fil)
{
	int			htag;
	int			start_col;
	static char	c = 'A';

	//c = 'A';
	htag = 1;
	result[fil.play_row][fil.play_col] = c;
	start_col = fil.play_col;
	while (htag != 4)
	{
		if (arr[htag] / 10 != arr[htag - 1] / 10)
			fil.play_row++;
		fil.play_col = (arr[htag] % 10) - (arr[0] % 10) + start_col;
		result[fil.play_row][fil.play_col] = c;
		htag++;
	}
	c++;
}

		// x = (arr[htag] % 10) + fil.play_col;
		// y = (arr[htag] / 10) + fil.play_row;