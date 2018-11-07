/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:43:17 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/06 20:26:05 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** (i % 5) e za sekogas da imam broj na red 0 1 2 ili 3, bez razlika dali
** se procesirat 26tiot tetris ili tretot. a posle (i%5) se mnozit so 10
** i se dodavat x, zs taka sekogas prvata cifra ke e redot vtorata kolona 
*/

void	play_tetris(char **tetris, t_board *board, t_filist **playlist)
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
		{
			check_plays(arr, board, playlist);
			el = 0;
			board->t_id += 1;
		}
		i++;
		x = 0;
	}
}

void	check_plays(int arr[4], t_board *board, t_filist **playlist)
{
	int row;
	int col;
	//t_fillit	fil;

	row = 0;
	col = 0;
	while (row < board->side)
	{
		while (col < board->side)
		{
			//if (board->result[row][col] == '.')
		//	{
				if (check_after(arr, board, row, col) == 0)
					store_play(board, playlist);
					//get_score(arr, row, col, &fil);
			//}
			col++;
		}
		row++;
		col = 0;
	}
	// if (fil.best_score != INT_MAX)
	// 	insert_piece(arr, board, fil);
	// else
	// 	b_printf("piece not played\n");
	//b_printf("High score: -> row %d  columns: %d\n", fil.play_row, fil.play_col);
}

int		check_after(int arr[4], t_board *board, int row, int col)
{
	int htag;
	//int start_col;

	htag = 1;
	board->cords[0][0] = row;
	board->cords[1][0] = col;
	while (htag != 4)
	{
		if (arr[htag] / 10 != arr[htag - 1] / 10)
		{
			if (++row > board->side - 1)
				return (-1);
		}
		col = (arr[htag] % 10) - (arr[0] % 10) + board->cords[1][0];
		if (col > board->side - 1 || col < 0)
			return (-1);
		// if (board->result[row][col] != '.') // or is letter /alpha
		// 	return (-1);
		board->cords[0][htag] = row;
		board->cords[1][htag] = col;
		htag++;
	}
	return (0);
}

void	search_for_sol(t_board *board, t_filist **playlist, t_filist **solutions, char **tetris)
{

	while (find_solution(board, *playlist, NULL, solutions) == 0)
	{
		board->side++;
		new_surface(board);
		clean_playlist(playlist);
		//check_plays(bla, board, playlist);
		play_tetris(tetris, board, playlist);
	}

}

void	clean_playlist(t_filist **playlist)
{
	t_filist *temp;
	t_filist *temp_d;

	temp_d = (*playlist)->down;
	while (temp_d)
	{
		temp = temp_d;
		temp_d = temp_d->down;
		temp->down = NULL;
		free(temp);
		temp = NULL;
	}
	while(*playlist)
	{
		temp = *playlist;
		*playlist = (*playlist)->next;
		//temp->next = NULL;
		free (temp);
		temp = NULL;
	}
}

void	new_surface(t_board *board)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (i < board->side)
		free(board->result[i++]);
	i = 0;
	while (i < board->side)
	{
		board->result[i] = ft_strnew(board->side); // not protected
		x = 0;
		while (x < board->side)
			board->result[i][x++] = '.';
		i++;
	}
	board->result[board->side] = NULL;
	board->t_id = 'A';
}

// void	get_score(int arr[4], int row, int col, t_fillit *fil)
// {
// 	int		htag;
// 	size_t	score;
// 	int		start_col;

// 	score = row + col;
// 	htag = 1;
// 	start_col = 0;
// 	fil->tem_col = col;
// 	fil->tem_row = row;
// 	while (htag != 4)
// 	{
// 		if (arr[htag] / 10 != arr[htag - 1] / 10)
// 			row++;
// 		col = (arr[htag] % 10) - (arr[0] % 10) + start_col;
// 		score += row + col;
// 		htag++;
// 	}
// 	if (score < fil->best_score)
// 	{
// 		fil->best_score = score;
// 		fil->play_col = fil->tem_col;
// 		fil->play_row = fil->tem_row;
// 	}
// }

// void	insert_piece(int arr[4], t_board *board, t_fillit fil)
// {
// 	int			htag;
// 	int			start_col;
// 	static char	c = 'A';

// 	htag = 1;
// 	board->result[fil.play_row][fil.play_col] = c;
// 	start_col = fil.play_col;
// 	while (htag != 4)
// 	{
// 		if (arr[htag] / 10 != arr[htag - 1] / 10)
// 			fil.play_row++;
// 		fil.play_col = (arr[htag] % 10) - (arr[0] % 10) + start_col;
// 		board->result[fil.play_row][fil.play_col] = c;
// 		htag++;
// 	}
// 	c++;
// }

		// x = (arr[htag] % 10) + fil.play_col;
		// y = (arr[htag] / 10) + fil.play_row;