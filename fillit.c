/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:50:38 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/02 19:05:55 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		exit_app(const char *source)
{
	b_printf("%s\n", source);
	exit(1);
}

int	main(int argc, char **argv)
{
	char	**tetris;
	char	**result;
	int		i;

	i = 0;
	tetris = malloc(sizeof(char*) * 26); //ova prasaj dali trebit vaka
	result = malloc(sizeof(char *) * 4);
	while (i < 4)
		result[i++] = ft_strnew(4);
	if (argc != 2)
		exit_app("usage: bla bla");
	
	parse_tetris(argv[1], tetris);

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
**  (i + 1) % 5 != 0, zs sekoja figura e 4 lines long, ova gi provreit samo tie linii
** check_hashtags se povikvit ko ke i e na posl linija od piece, namesto na praznata lin
** za da go fatam i posledniot piece zs za nego ne se dodavat "" na kraj
*/
void	parse_tetris(const char *filepath, char **tetris)
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
	tetris[i] = NULL;
	close(fd);
}
