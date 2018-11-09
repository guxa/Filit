/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 22:58:13 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 22:59:44 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	abcsort(t_list **head, t_list *element)
{
	t_list	*curr;
	t_list	*prev;

	prev = NULL;
	curr = *head;
	while (curr->next && (ft_strcmp(curr->content, element->content) <= 0))
	{
		prev = curr;
		curr = curr->next;
	}
	if (ft_strcmp(curr->content, element->content) >= 0)
	{
		if (!prev)
			*head = element;
		else
			prev->next = element;
		element->next = curr;
	}
	else
		curr->next = element;
}

void	revabcsort(t_list **head, t_list *element)
{
	t_list	*curr;
	t_list	*prev;

	prev = NULL;
	curr = *head;
	while (curr->next && (ft_strcmp(curr->content, element->content) >= 0))
	{
		prev = curr;
		curr = curr->next;
	}
	if (ft_strcmp(curr->content, element->content) <= 0)
	{
		if (!prev)
			*head = element;
		else
			prev->next = element;
		element->next = curr;
	}
	else
		curr->next = element;
}
