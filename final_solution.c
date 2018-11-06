/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:32:24 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/05 20:37:30 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_filist	*find_best_solution(t_filist	*solutions)
{
	int score;
	int best_score;
	int i;
	t_filist	*best_solution;
	t_filist	*temp;

	score = INT_MAX;
	best_score = INT_MAX - 1;
	while (solutions)
	{
		i = 0;
		if (solutions->t_id == '$')
		{
			if (score < best_score)
			{
				best_solution = temp;
				best_score = score;
			}
			temp = solutions;
			solutions = solutions->next;
			score = 0;
		}
		while (i < 4)
		{
			score += solutions->cords[0][i];
			score += solutions->cords[1][i++];
		}
		solutions = solutions->next;
	}
	return (best_solution);
}

void	fill_board(t_filist	*solutions, t_board *board)
{
	int y;
	int x;
	int i;
	int z;
	t_filist *start;

	z = 0;
	i = 0;
	solutions = solutions->next;
	start = solutions;
	while (solutions && solutions->t_id != '$')
	{
		// if (solutions->t_id == '$')
		// {
		// 	while (z < board->side)
		// 		b_printf("%s\n", board->result[z++]);
		// 	z = 0;
		// 	while (i < board->side)
		// 	{
		// 		x = 0;
		// 		while (x < board->side)
		// 			board->result[i][x++] = '.';
		// 		i++;
		// 	}
		// 	i = 0;
		// 	solutions = solutions->next;
		// 	b_printf("\n");
		// }
		while (i < 4)
		{
			x = solutions->cords[0][i];
			y = solutions->cords[1][i];
			board->result[y][x] = solutions->t_id;
			i++;
		}
		solutions = solutions->next;
		i = 0;
	}
	trim_solution(start, board);
}

void	trim_solution(t_filist	*solution, t_board *board)
{
	int i;
	int largest_x;
	int largest_y;

	largest_x = 0;
	largest_y = 0;
	while (solution && solution->t_id != '$')
	{
		i = 0;
		while (i < 4)
		{
			if (solution->cords[0][i] > largest_x)
				largest_x = solution->cords[0][i];
			if (solution->cords[1][i] > largest_y)
				largest_y = solution->cords[1][i];
			i++;
		}
		solution = solution->next;
	}
	i = -1;
	board->result[largest_y + 1] = NULL;
	while (board->result[++i])
		board->result[i][largest_x + 1] = '\0';
	board->side = largest_y + 1;
}