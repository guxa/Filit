/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 23:41:07 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/05 20:58:33 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	store_play(t_board *board, t_filist **main_list)
{
	int	i;
	int x;
	t_filist *newplay;

	if ((newplay = malloc(sizeof(t_filist))) == NULL)
		exit_app("Malloc failed");
	i = 0;
	x = 0;
	while (i != 4)
	{
		newplay->cords[x][i] = board->cords[x][i];
		i++;
		if (i == 4 && x++ == 0)
			i = 0;
	}
	newplay->t_id = board->t_id;
	if ((*main_list) && (newplay->t_id == (*main_list)->t_id))
		put_down(*main_list, newplay);
	else
	{
		newplay->next = *main_list;
		*main_list = newplay;
		newplay->down = NULL;
	}
}

void	put_down(t_filist *main_list, t_filist *new)
{
	t_filist *temp;

	temp = main_list;
	while (temp->down)
		temp = temp->down;
	temp->down = new;
	new->next = NULL;
	new->down = NULL;
}

/*
** Gets the first valid play from figure A, then goes to the next figure, checks with B0
** if it's not valid, it goes down, checks with B1, if it's valid, stores it and goes to next
** C0, if good adds it to list, if no C element is good it deletes the stored elements from the list.
** If C0 was good it is added and has a complete solution {A0;B1;C0} then it adds a separator in the list,
** and continues from B2, then org will be init. And it will compare B2 with figure before it in the
** completed solution. if B2 is good with A0, it copies A0, then B2 is added, and contines to C ...
*/

void	find_solution(t_board *board, t_filist *playlist, t_filist *org, t_filist **solutions)
{
	//static t_filist	*solutions = NULL;
	t_filist	*temp;

	temp = playlist;
	while (temp)
	{
		if (org)
			compare_prev_solution(&org, temp, solutions);
		if (compare_cords (*solutions, temp) == 0)
		{
			if (copy_node(solutions, temp, board->pieces))
				org = *solutions;
			find_solution(board, playlist->next, org, solutions);
		}
	// if (temp->t_id == 'A')
	// 	org = NULL;
		temp = temp->down;
	}
	clean_garbage(solutions);
}

void	clean_garbage(t_filist	**solution)
{
	int			flag;
	t_filist	*temp;
	
	flag = 0;
	temp = *solution;
	if (temp && temp->t_id != '$')
	{
		*solution = (*solution)->next;
		temp->next = NULL;
		free (temp);
		temp = *solution;
	}
}

int	compare_cords(t_filist	*solution, t_filist	*new_elem)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (solution && solution->t_id != '$') // $ ke separator
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
	int x;
	int y;
	t_filist *new_node;

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
	new_node->t_id = source->t_id;	//score mozda ne trebit ovde da se kopirat, na kraj samo da se sum koordinatite
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

void	compare_prev_solution(t_filist **org, t_filist *new_elem, t_filist **sol)
{
	t_filist *temp;

	temp = *org;
	if (temp->t_id != '$')
		exit_app("Wrongly assigned original");
	
	while (temp && temp->t_id != new_elem->t_id)
		temp = temp->next;
	temp = temp->next;
	if (compare_cords(temp, new_elem) == 0)
	{
		while (temp && temp->t_id != '$')
		{
			copy_node(sol, temp, -1);
			temp = temp->next;
		}
	}
}

void	copy_node2(t_filist **dest, t_filist *source)
{
	int x;
	int y;
	t_filist *new_node;
	t_filist *prev;
	t_filist *cur;

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
	
	cur = *dest;
	prev = NULL;
	while (cur->t_id != '$')
	{
		prev = cur;
		cur = cur->next;
	}
	if (prev)
		prev->next = new_node;
	else
		*dest = new_node;
	new_node->next = cur;
}