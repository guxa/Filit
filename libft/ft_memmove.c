/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:29:31 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/30 15:00:15 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	dest = (char*)dst;
	source = (const char*)src;
	if (dest <= source)
		ft_memcpy(dest, source, len);
	else
	{
		while (len--)
			dest[len] = source[len];
	}
	return (dst);
}
