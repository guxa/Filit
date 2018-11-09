/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bprintf_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 17:05:21 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/14 19:37:36 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** kaj listadd morat da se prenesit so & za head-ot na listata
** da mojt da go menvit
** linija 39 //ova e za ako imat edno posle drugo konvertori primer %s%s
*/

#include "libft.h"

int			parser(const char *format, va_list ap)
{
	int			count;
	int			position;
	int			charwritten;

	count = 0;
	position = 0;
	charwritten = 0;
	while (format[count])
	{
		if (format[count] == '%')
		{
			charwritten += myprinter(format, position, count);
			charwritten += findarg(&format[count], ap);
			count += 2;
			position = count;
		}
		if (format[count] != '%' && format[count])
			count++;
	}
	charwritten += myprinter(format, position, count);
	return (charwritten);
}

int			is_vartype(char c)
{
	if (c == 's' || c == 'c' || c == 'd' || c == 'i' || c == '%'
			|| c == 'p' || c == 'o' || c == 'u' || c == 'x')
		return (1);
	return (0);
}
