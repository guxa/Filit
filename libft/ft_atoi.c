/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:43:49 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 21:44:48 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int		i;
	long	result;
	int		neg;

	neg = 1;
	result = 0;
	i = 0;
	while (str[i] > 0 && str[i] < 33 && str[i] != 27)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result >= 214748364 && str[i] > '8') || result > 214748365)
			return (neg > 0 ? -1 : 0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * neg);
}

int	myatoi_base(const char *str, int str_base)
{
	int		i;
	int		result;
	char	*basechar;
	int		num;

	i = 0;
	result = 0;
	basechar = "0123456789ABCDEFabcdef";
	while ((str[i]) && (ft_strchr(basechar, (int)str[i]) != NULL))
	{
		if (str[i] >= 'A')
		{
			if (str[i] >= 'a')
				num = str[i] - ('a' - 10);
			else
				num = str[i] - ('A' - 10);
		}
		else
			num = str[i] - '0';
		result = result * str_base + num;
		i++;
	}
	return (result);
}
