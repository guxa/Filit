/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:56:23 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/01 22:31:35 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int			getlinija(int fd, char **line, char *buffer, char **rest)
{
	char		*nl;
	int			bred;
	char		*temp;

	if (checkresto(line, rest))
		return (1);
	while ((bred = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[bred] = '\0';
		if ((nl = ft_strchr(buffer, '\n')))
		{
			temp = *line;
			*nl = '\0';
			*line = ft_strjoin(*line, buffer);
			*rest = ft_strdup(++nl);
			free(temp);
			return (1);
		}
		temp = *line;
		*line = ft_strjoin(*line, buffer);
		free(temp);
	}
	*rest = 0;
	return (ft_strlen(*line) > 0 ? 1 : 0);
}

int			checkresto(char **line, char **rest)
{
	char *nl;
	char *temp;

	if (!*rest || *rest[0] == '\0')
	{
		free(*rest);
		return (0);
	}
	if ((nl = ft_strchr(*rest, '\n')))
	{
		*nl = '\0';
		temp = *line;
		*line = ft_strjoin(*line, *rest);
		free(temp);
		temp = *rest;
		*rest = ft_strdup(++nl);
		free(temp);
		return (1);
	}
	free(*line);
	*line = ft_strdup(*rest);
	free(*rest);
	return (0);
}

static char	**handle_file(t_getlines **list, int fd)
{
	t_getlines	*tem;

	tem = *list;
	while (tem)
	{
		if (tem->fd == fd)
			return (&tem->rest);
		tem = tem->next;
	}
	tem = (t_getlines *)malloc(sizeof(t_getlines));
	tem->fd = fd;
	tem->rest = NULL;
	tem->next = *list;
	*list = tem;
	return (&tem->rest);
}

int			get_next_line(const int fd, char **line)
{
	char				*linija;
	char				buffer[BUFF_SIZE + 1];
	static t_getlines	*list;

	linija = ft_strdup("");
	if (fd < 0 || !line || read(fd, buffer, 0) < 0
		|| !linija)
		return (-1);
	if (getlinija(fd, &linija, buffer, handle_file(&list, fd)))
		*line = linija;
	else
		return (0);
	return (1);
}
