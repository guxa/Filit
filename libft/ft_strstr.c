/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 22:03:32 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/17 22:40:40 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *location, const char *target)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	if (target[i] == '\0')
		return ((char *)location);
	while (location[i] != '\0')
	{
		j = 0;
		while (location[i + j] == target[j])
		{
			j++;
			if (target[j] == '\0')
				return ((char*)&location[i]);
		}
		i++;
	}
	return (0);
}
