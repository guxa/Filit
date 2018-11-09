/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:55:26 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 21:37:50 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (!alst || !(*alst) || !del)
		return ;
	while (*alst)
	{
		temp = *alst;
		(*alst) = (*alst)->next;
		ft_lstdelone(&temp, del);
	}
}
