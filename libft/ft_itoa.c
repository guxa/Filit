/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 18:17:34 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 17:28:20 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** linija 34 i 45 base == 10 na e zs vo vezbana vikat
**	deka drugi base trebit ko unsigned da se tretiret
**	linija 33 i 34: ova e zaradi minimum integerot zs ako ne e Long,
**	ne ja cuvat pozitivna brojkata ostanvit negativna
** 	Linija 40 i 41 pukase 1Test malloc is not protected
** 	izbrisana validaicja za base da e pomalo od 2 od linija 36
*/

#include "libft.h"

char	*ft_itoa_base(long number, int base)
{
	int		size;
	long	newnumber;
	char	*numtable;
	char	*string;

	numtable = ft_strnew(16);
	numtable = "0123456789abcdef";
	size = countdigits(number, base);
	newnumber = number;
	newnumber = (number > 0 ? number : -newnumber);
	if (number < 0 && base == 10)
		size++;
	string = ft_strnew((size > 0 ? size : 1));
	if (!string)
		return (NULL);
	(string ? string[0] = '0' : 0);
	while (size > 0)
	{
		string[--size] = numtable[newnumber % base];
		newnumber = newnumber / base;
	}
	if (number < 0 && base == 10)
		string[0] = '-';
	return (string);
}

int		countdigits(long number, int base)
{
	int size;

	size = 0;
	while (number)
	{
		size++;
		number = number / base;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	return (ft_itoa_base(n, 10));
}
