/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:18:44 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 17:38:51 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *location, const char *target, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (target[i] == '\0')
		return ((char *)location);
	while (location[i] != '\0' && i < len)
	{
		j = 0;
		while (location[i + j] == target[j] && i + j < len)
		{
			j++;
			if (target[j] == '\0')
				return ((char *)&location[i]);
		}
		i++;
	}
	return (0);
}
