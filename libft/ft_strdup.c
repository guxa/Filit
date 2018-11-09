/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:14:51 by jguleski          #+#    #+#             */
/*   Updated: 2018/09/23 16:53:04 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*newstr;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = -1;
	if (newstr == NULL)
		return (NULL);
	while (s1[++i])
		newstr[i] = s1[i];
	newstr[i] = '\0';
	return (newstr);
}
