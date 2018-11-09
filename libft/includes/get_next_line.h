/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:28:09 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/01 22:49:11 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

typedef struct	s_getlines
{
	char				*rest;
	int					fd;
	struct s_getlines	*next;

}				t_getlines;

int				getlinija(int filedesc, char **line, char *buffer, char **rest);
int				checkresto(char **line, char **rest);
int				get_next_line(const int fd, char **line);

#endif
