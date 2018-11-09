/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:20:28 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 17:33:39 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src,
					size_t dstsize)
{
	size_t	i;
	size_t	x;
	size_t	result;

	i = 0;
	x = 0;
	while (dst[i])
		i++;
	result = i;
	if (dstsize == 0 || i > dstsize)
		result = dstsize;
	while (src[x] && (int)(dstsize-- - result - 1) > 0)
		dst[i++] = src[x++];
	dst[i] = '\0';
	return (result + ft_strlen(src));
}
