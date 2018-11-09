/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:32:24 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/06 22:48:49 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Gets the first valid play from figure A, then goes to the next figure, checks
** with B0, if it's not valid, it goes down, checks with B1, if it's valid,
** stores it and goes to next C0, if good adds it to list, if no C element
** is good it deletes the stored elements from the list. If C0 was good it is
** added and has a complete solution {A0;B1;C0} then it adds a separator
** in the list, and continues from B2, then org will be init.
** And it will compare B2 with figure before it in the completed solution.
** if B2 is good with A0, it copies A0, then B2 is added, and contines to C ...
*/

int		find_solution(t_board *board, t_filist *playlist, t_filist **solutions)
{
	t_filist	*temp;

	temp = playlist;
	while (temp)
	{
		if (compare_cords(*solutions, temp) == 0)
		{
			if (copy_node(solutions, temp, board->pieces))
				return (1);
			if (find_solution(board, playlist->next, solutions))
				return (1);
		}
		temp = temp->down;
	}
	clean_garbage(solutions);
	return (0);
}

void	clean_garbage(t_filist **solution)
{
	int			flag;
	t_filist	*temp;

	flag = 0;
	temp = *solution;
	if (temp && temp->t_id != '$')
	{
		*solution = (*solution)->next;
		temp->next = NULL;
		free(temp);
	}
}

int		compare_cords(t_filist *solution, t_filist *new_elem)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (solution && solution->t_id != '$')
	{
		while (x != 4)
		{
			while (y != 4)
			{
				if (solution->cords[0][y] == new_elem->cords[0][x]
					&& solution->cords[1][y] == new_elem->cords[1][x])
					return (-1);
				y++;
			}
			y = 0;
			x++;
		}
		solution = solution->next;
		x = 0;
	}
	return (0);
}

int		copy_node(t_filist **dest, t_filist *source, int pieces)
{
	int			x;
	int			y;
	t_filist	*new_node;

	x = 0;
	y = 0;
	if (!source || (new_node = malloc(sizeof(t_filist))) == NULL)
		exit_app("Malloc failed inside copy_node");
	while (x != 4)
	{
		new_node->cords[y][x] = source->cords[y][x];
		x++;
		if (x == 4 && y++ == 0)
			x = 0;
	}
	new_node->t_id = source->t_id;
	new_node->next = *dest;
	*dest = new_node;
	x = 0;
	while (new_node && new_node->t_id != '$')
	{
		new_node = new_node->next;
		x++;
	}
	return (x == pieces ? add_separator(dest) : 0);
}

int		add_separator(t_filist **solutions)
{
	t_filist *new_node;

	if (((new_node = malloc(sizeof(t_filist))) == NULL) || !(*solutions))
		exit_app("Malloc failed inside copy_node");
	new_node->t_id = '$';
	new_node->down = NULL;
	new_node->next = *solutions;
	*solutions = new_node;
	return (1);
}
