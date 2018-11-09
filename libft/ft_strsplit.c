/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 00:56:34 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 16:30:52 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** vo countwords (*x) se prakat za ako stringot pocvit so ' ' ili '\t' i sl.
** da ne vlezat vo prviot word/str praznite mesta, tuku da gi skoknit niv
** prv if vo while loop, ako string pocvit so delim i posle imat samo 1 zbor
*/

static size_t	countwords(char *str, int *x, char c)
{
	size_t i;
	size_t words;

	i = 0;
	words = 0;
	while (str[i] && str[i] == c)
		i++;
	*x = i;
	while (str[i])
	{
		if (str[i] == c || words == 0)
			words++;
		while (str[i] && str[i] == c)
			i++;
		if (str[i] == '\0')
		{
			words--;
			break ;
		}
		i++;
	}
	return (words);
}

/*
** line 70 if-ot ako stringot nemat niedno prazno mesto, [x] e veke do kraj
** za da ne go zgolemit i da e nadvor od mem//l62 +1 vo words za da mozit
** da se locirat krajot na char**, za da mozit da se listat
*/

static int		split_words(char ***ar, char *str, char c)
{
	size_t	words;
	size_t	i;
	int		x;
	int		start;

	i = 0;
	x = 0;
	words = countwords(str, &x, c);
	if ((*ar = malloc(sizeof(char *) * words + 1)) == NULL)
		return (-1);
	while (i < words)
	{
		start = x;
		while (str[x] && str[x] != c)
			x++;
		if (str[x])
			str[x++] = '\0';
		while (str[x] && str[x] == c)
			x++;
		(*ar)[i++] = ft_strdup(&(str[start]));
	}
	return ((int)i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**ar;
	char	*str;

	if (!s || (str = ft_strdup(s)) == NULL)
		return (NULL);
	ar = NULL;
	i = split_words(&ar, str, c);
	if (i < 0)
		return (NULL);
	ar[i] = NULL;
	free(str);
	return (ar);
}
