/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:27:59 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/09 20:21:12 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int			check_sides(const char **tetris, int pos, int line, int start)
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

void		parse_tetris(const char *filepath, char **tetris, t_board *board)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if ((fd = open(filepath, O_RDONLY, S_IRUSR)) < 0)
		exit_app("File doesn't exist");
	while (get_next_line(fd, &line) > 0)
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
	board->side = ft_sqrt(((i + 1) / 5) * 4);
	board->pieces = ((i + 1) / 5);
	tetris[i] = NULL;
	close(fd);
}

void		exit_app(const char *source)
{
	b_printf("%s\n", source);
	exit(1);
}
