/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:12:45 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 17:38:32 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tem;

	i = -1;
	tem = NULL;
	while (s[++i])
	{
		if (s[i] == c)
			tem = ((char *)&(s[i]));
	}
	if (c == 0)
		return ((char *)&(s[i]));
	return (tem);
}
