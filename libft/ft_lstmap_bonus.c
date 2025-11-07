/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:43:32 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/06 17:55:50 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*aux_n;
	t_list	*nw_el;

	if (!lst)
		return (NULL);
	nw_el = ft_lstnew(f(lst->content));
	if (nw_el == NULL)
		return (NULL);
	n_list = nw_el;
	aux_n = n_list;
	lst = lst->next;
	while (lst)
	{
		nw_el = ft_lstnew(f(lst->content));
		if (nw_el == NULL)
		{
			ft_lstclear(&aux_n, del);
			return (NULL);
		}
		n_list->next = nw_el;
		n_list = nw_el;
		lst = lst->next;
	}
	return (aux_n);
}
