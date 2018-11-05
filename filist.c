/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 23:41:07 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/04 18:00:30 by jguleski         ###   ########.fr       */
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
		newplay->score += board->cords[x][i];
		i++;
		if (i == 4 && x++ == 0)
			i = 0;
	}
	newplay->t_id = board->t_id;
	newplay->next = *main_list;
	*main_list = newplay;
	count++; //ova cisto za testiranje
}

void	find_solution(t_board *board, t_filist *playlist)
{
	t_filist	*solution;

	solution = NULL;
	while (playlist)
	{
		if (!solution || playlist->t_id != playlist->t_id)
			copy_node(solution, playlist);

		if (x == board->pieces)
			break;
		find_solution(board, playlist->next);
	}
}


void	copy_node(t_filist **dest, t_filist *source)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!source || (*dest = malloc(sizeof(t_filist))) == NULL)
		exit_app("Malloc failed inside copy_node");
	while (x != 4)
	{
		(*dest)->cords[y][x] = source->cords[y][x];
		if (x == 4 && y++ == 0)
			x = 0;
		x++;
	}
	(*dest)->next = NULL;

}