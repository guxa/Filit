/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:35:03 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 17:39:11 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *str)
{
	char	*result;
	int		i;
	int		len;

	i = -1;
	if (str == 0)
		return (0);
	len = ft_strlen(str);
	if (len == 0)
		return (ft_strnew(0));
	while (len--)
		if (str[len] != ' ' && str[len] != '\n' && str[len] != '\t')
			break ;
	if (len < 0)
		return (ft_strnew(0));
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			break ;
	if ((result = (char *)malloc(sizeof(char) * (len + 1 - i + 1))) == NULL)
		return (NULL);
	result = ft_strncpy(result, &(str[i]), len + 1 - i);
	result[len + 1 - i] = '\0';
	return (result);
}
