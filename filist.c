/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 23:41:07 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/06 22:51:21 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	store_play(t_board *board, t_filist **main_list)
{
	int			i;
	int			x;
	t_filist	*newplay;

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
	newplay->next = NULL;
	newplay->down = NULL;
	insert_in_list(main_list, newplay);
}

void	insert_in_list(t_filist **main_list, t_filist *newplay)
{
	t_filist *temp;

	temp = *main_list;
	if (*main_list == NULL)
	{
		*main_list = newplay;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	if (temp->t_id == newplay->t_id)
	{
		while (temp->down)
			temp = temp->down;
		temp->down = newplay;
	}
	else
		temp->next = newplay;
}

void	fill_board(t_filist *solutions, t_board *board)
{
	int			y;
	int			x;
	int			i;
	int			z;
	t_filist	*start;

	z = 0;
	i = 0;
	solutions = solutions->next;
	start = solutions;
	while (solutions && solutions->t_id != '$')
	{
		while (i < 4)
		{
			y = solutions->cords[0][i];
			x = solutions->cords[1][i];
			board->result[y][x] = solutions->t_id;
			i++;
		}
		solutions = solutions->next;
		i = 0;
	}
}
