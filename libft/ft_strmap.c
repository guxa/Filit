/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:03:10 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 16:16:03 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	i = 0;
	if (!s || !f || ((result = ft_strdup(s)) == NULL))
		return (NULL);
	while (result[i])
	{
		result[i] = f(result[i]);
		i++;
	}
	return (result);
}
