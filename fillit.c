/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:50:38 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/06 16:57:05 by jguleski         ###   ########.fr       */
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
	if ((board->result = malloc(sizeof(char *) * board->side + 1)) == NULL)
		exit_app("Malloc inside init_board failed");
	while (i < board->side)
	{
		board->result[i] = ft_strnew(board->side);
		x = 0;
		while (x < board->side)
			board->result[i][x++] = '.';
		i++;
	}
	board->result[i] = NULL;
	board->t_id = 'A';
}

int	main(int argc, char **argv)
{
	char	**tetris;
	int		i;
	t_board		*res_board;
	t_filist	*playlist;
	t_filist	*solutions;
	t_filist	*or;

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
	or = NULL;
	//find_solution(res_board, playlist, &or, &solutions);
	
	//fill_board(find_best_solution(solutions), res_board);
	while (i < res_board->side)
		b_printf("%s\n", res_board->result[i++]);
	return (0);
	
}

static void	check_hashtags(const char **tetris, int line, int start_line)
{
	int i;
	int	hashtags;
	int sides;

	i = 0;
	hashtags = 0;
	sides = 0;
	while (line >= start_line)
	{
		if (tetris[line][i] == '#')
		{
			hashtags++;
			sides += check_sides(tetris, i, line, start_line);
		}
		else if (tetris[line][i] != '.')
			exit_app("error");
		i++;
		if (i == 4)
		{
			line--;
			i = 0;
		}
	}
	if (hashtags != 4 || sides < 6)
		exit_app("error");
}

int		check_sides(const char **tetris, int pos, int line, int start)
{
	int sides;

	sides = 0;
	if (pos != 0 && tetris[line][pos - 1] == '#')
		sides++;
	if (pos < 3 && tetris[line][pos + 1] == '#')
		sides++;
	if (line != start && tetris[line - 1][pos] == '#')
		sides++;
	if ((line + 2) % 5 != 0 && tetris[line + 1][pos] == '#')
		sides++;
	return (sides);
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
	if ((fd = open(filepath, O_RDONLY, S_IRUSR)) < 0)
		exit_app("File doesn't exist");
	while (get_next_line(fd, &line))
	{
		if (((i + 1) % 5 == 0) && ft_strequ(line, "") == 0)
			exit_app("error");
		if (((i + 1) % 5 != 0) && ft_strlen(line) != 4)
			exit_app("error");
		tetris[i] = ft_strdup(line);
		if ((i + 2) % 5 == 0)
			check_hashtags((const char**)tetris, i, i - 3);
		ft_memdel((void**)&line);
		i++;
	}
	if ((i + 1) % 5 != 0)
		exit_app("error");
	board->side = ft_sqrt(((i + 1) / 5) * 4) + 1; // ova fiksno + 1 mozit da e problem
	board->pieces = ((i + 1) / 5);
	tetris[i] = NULL;
	close(fd);
}
