/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:50:38 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/05 20:37:37 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		exit_app(const char *source)
{
	b_printf("%s\n", source);
	exit(1);
}

void		init_board(t_board	*board)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	if ((board->result = malloc(sizeof(char *) * board->side)) == NULL)
		exit_app("Malloc inside init_board failed");
	while (i < board->side)
	{
		board->result[i] = ft_strnew(board->side);
		x = 0;
		while (x < board->side)
			board->result[i][x++] = '.';
		i++;
	}
	board->t_id = 'A';
}

int	main(int argc, char **argv)
{
	char	**tetris;
	int		i;
	t_board		*res_board;
	t_filist	*playlist;
	t_filist	*solutions;

	i = 0;
	playlist = NULL;
	if (argc != 2)
		exit_app("usage: bla bla");
	res_board = malloc(sizeof(t_board));
	tetris = malloc(sizeof(char*) * 26 * 5); //ova prasaj dali trebit vaka
	if (!res_board || !tetris)
		exit_app("Malloc failed");
	parse_tetris(argv[1], tetris, res_board);
	init_board(res_board);

	play_tetris(tetris, res_board, &playlist);

	solutions = NULL;
	find_solution(res_board, playlist, NULL, &solutions);
	
	fill_board(find_best_solution(solutions), res_board);
	while (i < res_board->side)
		b_printf("%s\n", res_board->result[i++]);
	return (0);
	
}

static void	check_hashtags(const char **tetris, int line)
{
	int	start;
	int i;
	int	hashtags;

	i = 0;
	hashtags = 0;
	start = line - 3;
	while (line >= start)
	{
		if (tetris[line][i] == '#')
			hashtags++;
		else if (tetris[line][i] != '.')
			exit_app("error");
		i++;
		if (i == 4)
		{
			line--;
			i = 0;
		}
	}
	if (hashtags != 4)
		exit_app("error");
}

/*
** error checks: (i + 1) % 5 != 0, zs figurite e 4 lines long, 
** ova gi provreit samo tie linii bez praznite ... check_hashtags se povikvit
** ~ ko ke i e na posl linija od piece, namesto na praznata lin
** za da go fatam i posledniot piece zs za nego ne se dodavat "" na kraj
** board->side notes: (i+1) / 5 e brojot na tetriminosi. 
** Ako e 1 ili 4 samo togas sqroot ke e cel broj i togas ne trebit
** da se zgolemit za +1, vo drugite slucai trebit zs ne e cel broj
*/
void	parse_tetris(const char *filepath, char **tetris, t_board *board)
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open(filepath, O_RDONLY, S_IRUSR);
	while (get_next_line(fd, &line))
	{
		if (((i + 1) % 5 == 0) && ft_strequ(line, "") == 0)
			exit_app("error Tetriminos not valid");
		if (((i + 1) % 5 != 0) && ft_strlen(line) != 4)
			exit_app("error Tetriminos not valid");
		tetris[i] = ft_strdup(line);
		if ((i + 2) % 5 == 0 || i == 3)
			check_hashtags((const char**)tetris, i);
		ft_memdel((void**)&line);
		i++;
	}
	board->side = ft_sqrt(((i + 1) / 5) * 4);
	board->pieces = ((i + 1) / 5);
	// if (((i + 1) / 5 != 4) && ((i + 1) / 5 != 1))
	 	board->side++;
	tetris[i] = NULL;
	close(fd);
}
