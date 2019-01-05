/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:09:32 by pzubar            #+#    #+#             */
/*   Updated: 2017/11/09 12:09:34 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cleaner(t_list *fst)
{
	t_list *tmp;

	while (fst)
	{
		tmp = fst->next;
		free(fst);
		fst = NULL;
		fst = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *fst;

	if (lst && f)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		if (!new)
			return (NULL);
		new = (*f)(new);
		fst = new;
		while (lst->next)
		{
			lst = lst->next;
			new->next = ft_lstnew(lst->content, lst->content_size);
			if (!new)
			{
				cleaner(fst);
				return (NULL);
			}
			new->next = (*f)(new->next);
			new = new->next;
		}
		return (fst);
	}
	return (NULL);
}
