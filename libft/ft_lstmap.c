/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:35:15 by lschambe          #+#    #+#             */
/*   Updated: 2018/12/02 14:59:05 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fri(t_list *alst)
{
	while (alst)
	{
		free(alst->content);
		alst->content_size = 0;
		alst = alst->next;
	}
	free(alst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nekst;
	t_list	*list;
	t_list	*alst;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	alst = list;
	nekst = lst;
	while (nekst->next)
	{
		nekst = nekst->next;
		list->next = f(nekst);
		if (!list)
		{
			fri(alst);
			return (NULL);
		}
		list = list->next;
	}
	return (alst);
}
