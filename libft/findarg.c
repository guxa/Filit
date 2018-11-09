/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findarg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:16:34 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/14 19:37:41 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		findarg(const char *format, va_list ap)
{
	void		*arg;

	arg = NULL;
	if (format[1] == '%' || !(is_vartype(format[1])))
	{
		ft_putchar(format[1]);
		return (1);
	}
	arg = va_arg(ap, void *);
	if (!arg && format[1] == 's')
	{
		ft_putstr("(null)");
		return (6);
	}
	if (format[1] == 'c')
		ft_putchar((char)arg);
	else if (format[1] == 's')
		return (myprinter(arg, 0, -1));
	else
		return (numberhandler(arg, format[1]));
	return (1);
}
