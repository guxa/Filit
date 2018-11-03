/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:43:17 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/02 19:43:14 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	check_valid_plays(char **tetris, char **result)
{
	int i;
	int x;
	int offset;

	i = 0;
	x = 0;
	offset = -1;
	while (tetris[i])
	{
		if ((i + 1) % 5 == 0)
			i += 1;
		while (tetris[i][x])
		{
			if (tetris[i][x] == '#')
				
			x++
		}
		//insert_piece(tetris, result, i);
		i++;
		x = 0;
	}
}

static	void	check_play(int y, int x, char **result, int *off)
{
	y = y % 5;

	x = 0;
	while (y < 4)
	{
		if (result[y][x] == '\0')
		{
			(check after)
		}
		x++;
		if (x == )
	}


	if (off < 0)
		off = 

}
