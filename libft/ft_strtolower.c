/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 22:50:17 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 22:50:40 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlwr(char *s)
{
	size_t i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			s[i] = ft_tolower(s[i]);
			i++;
		}
	}
	return (s);
}