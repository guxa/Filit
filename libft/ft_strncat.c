/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:13:17 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 17:33:54 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t i;
	size_t x;

	i = 0;
	x = 0;
	while (s1[i])
		i++;
	while (s2[x] && x < n)
		s1[i++] = s2[x++];
	s1[i] = '\0';
	return (s1);
}
