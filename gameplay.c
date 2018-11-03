/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:43:17 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/02 21:33:13 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** (i % 5) e za sekogas da imam broj na red 0 1 2 ili 3, bez razlika dali
** se procesirat 26tiot tetris ili tretot. a posle (i%5) se mnozit so 10
** i se dodavat x, zs taka sekogas prvata cifra ke e redot vtorata kolona 
*/

void	check_valid_plays(char **tetris, char **result)
{
	static int	i;
	int			x;
	int			arr[4];
	int			el;

	i = 0;
	x = 0;
	el = 0;
	while (el != 4) // || (i + 1) % 5 != 0) //ova drugava proverka so i mozda in e trebit ovde
	{
		while (tetris[i][x])
		{
			if (tetris[i][x] == '#')
				arr[el++] = (i % 5) * 10 + x;
			x++;
		}
		i++;
		x = 0;
	}
	check_play(arr, result)
}

static	void	check_play(int arr[4], char **result)
{
	int el;
	int row;
	int col;

	el = 0;
	while (el != 4) //ova mozda ne trebit
	{
		while (row < 4)
		{
			while (col < 4)
			{
				if (result[row][col] == '\0')
					{
						if (checkafter(arr[4], el, row, col))
							//checkscore;
					}
			}

			row++;
			col = 0;
		}
	}

}

int		checkafter(int arr[4], char **result, int row, int col)
{
	int el;
	int start_col;

	el = 1;
	start_col = col;
	while (el != 4)
	{
		if (arr[el] / 10 != arr[el - 1] / 10)
		{
			if (++row > 3)
				return (-1);
			//if (((arr[el] - arr[el - 1]) % 10) > 1) // mozam i ternary op za da zastedam red
			//	col = start_col + ;
		}
		col = (arr[el] - arr[0]) % 10 + start_col;
		//col += (arr[el] - arr[el - 1]) % 10;
		
		if (result[row][col] != '\0') // or is letter /alpha
			return (-1);
		el++;
	}
	return (0);
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