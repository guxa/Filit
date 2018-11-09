/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:32:02 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 16:27:56 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char const *str, int fd)
{
	if (!str)
		return ;
	while (str[0])
	{
		write(fd, &str[0], 1);
		str++;
	}
	write(fd, "\n", 1);
}
