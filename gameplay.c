/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:43:17 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/03 00:41:56 by jguleski         ###   ########.fr       */
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
	static int	i;
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
			check_plays(arr, result, i);
		if (el == 4)
			el = 0;
		i++;
		x = 0;
	}
}

void	check_plays(int arr[4], char **result, int test)
{
	int row;
	int col;
	//t_fillit	fil;

	row = 0;
	col = 0;
	while (row < 4)
	{
		while (col < 4)
		{
			if (result[row][col] == '\0')
			{
				if (check_after(arr, result, row, col) == 0)
					b_printf("Test br:%d -> row %d  columns: %d\n",test, row, col);
					//score = get_score(arr[4], result, row, col);
			}
			col++;
		}
		row++;
		col = 0;
	}
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
		if (result[row][col] != '\0') // or is letter /alpha
			return (-1);
		htag++;
	}
	return (0);
}

int		get_score(int arr[4], int row, int col)
{
	int			htag;
	int			score;
	int			start_col;

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
	return (score);
}

	// y = y % 5;

	// x = 0;
	// while (y < 4)
	// {
	// 	if (result[y][x] == '\0')
	// 	{
	// 		(check after)
	// 	}
	// 	x++;
	// 	if (x == )
	// }