/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:55:13 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/30 16:55:27 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*strnew;
	size_t			count;

	count = 0;
	strnew = NULL;
	if (s != NULL)
	{
		if ((strnew = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		while (count < len)
		{
			strnew[count] = s[count + start];
			count++;
		}
		strnew[count] = '\0';
	}
	return (strnew);
}
