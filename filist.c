/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 23:41:07 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/04 23:43:57 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	store_play(t_board *board, t_filist **main_list)
{
	int	i;
	int x;
	t_filist *newplay;
	static int count = 0;

	if ((newplay = malloc(sizeof(t_filist))) == NULL)
		exit_app("Malloc failed");
	newplay->score = 0;
	i = 0;
	x = 0;
	while (i != 4)
	{
		newplay->cords[x][i] = board->cords[x][i];
		newplay->score += board->cords[x][i];	//mozda nemat potreba ovde score da go sum
		i++;
		if (i == 4 && x++ == 0)
			i = 0;
	}
	newplay->t_id = board->t_id;
	if (newplay->t_id == (*main_list)->t_id)
		put_down(main_list, newplay);
	else
	{
		newplay->next = *main_list;
		*main_list = newplay;
		newplay->down = NULL;
	}
	count++; //ova cisto za testiranje
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

void	find_solution(t_board *board, t_filist *playlist)
{
	static t_filist	*solutions = NULL;
	t_filist	*temp;
	int	count;

	temp = playlist;
	count = 0;
	while (temp)
	{
		if (compare_cords (solutions, temp) == 0)
		{
			copy_node(solutions, temp, board->pieces);
			find_solution(board, playlist->next);
			count++;
		}
		temp = temp->down;
	}
	return (count)
}

		//copy_node(solution, temp->next);
		// if (x == board->pieces)
		// 	break;

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
	}
	return (0);
}


void	copy_node(t_filist **dest, t_filist *source, int pieces)
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
	new_node->t_id = source->t_id;
	new_node->next = *dest;
	*dest = new_node;
	x = 0;
	while (new_node && new_node->t_id != '$')
	{
		new_node = new_node->next;
		x++;
	}
	if (x == pieces)
		add_separator (*dest);
	//score mozda ne trebit ovde da se kopirat, na kraj samo da se sum koordinatite
}

void	add_separator(t_filist **solutions)
{
	t_filist *new_node;
	if (!solutions || (new_node = malloc(sizeof(t_filist))) == NULL)
		exit_app("Malloc failed inside copy_node");
	new_node->t_id == '$';
	new_node->down == NULL;
	new_node->next = *solutions;
	solutions = new_node;
}

