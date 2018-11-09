/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:48:39 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 22:01:30 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*prev;

	prev = NULL;
	if (!lst || !f)
		return (NULL);
	if ((head = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	while (lst)
	{
		if (!prev)
		{
			head = f(lst);
			prev = head;
		}
		else
		{
			prev->next = f(lst);
			prev = prev->next;
		}
		lst = lst->next;
	}
	prev->next = NULL;
	return (head);
}
