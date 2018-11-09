/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:35:36 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/14 19:36:50 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			b_printf(const char *format, ...)
{
	int			charwritten;
	va_list		ap;

	charwritten = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	charwritten += parser(format, ap);
	va_end(ap);
	return (charwritten);
}

int			myprinter(const char *str, int start, int end)
{
	int listcount;

	listcount = 0;
	while (start != end && str[start])
	{
		ft_putchar(str[start++]);
		listcount++;
	}
	return (listcount);
}

int			numberhandler(void *number, char type)
{
	if (type == 'd' || type == 'i')
		number = ft_itoa_base((int)(number), 10);
	else if (type == 'u')
		number = ft_itoa_base((unsigned int)(number), 10);
	else if (type == 'x')
		number = ft_itoa_base((unsigned int)number, 16);
	else if (type == 'o')
		number = ft_itoa_base((unsigned int)(number), 8);
	else if (type == 'p')
	{
		number =
		ft_itoa_base((unsigned long)(number), 16);
		ft_putstr("0x");
		return (myprinter(number, 0, -1) + 2);
	}
	return (myprinter(number, 0, -1));
}
