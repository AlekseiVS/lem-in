/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:56:15 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 19:56:50 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst_new;
	t_list *tmp;
	t_list *res;

	tmp = f(lst);
	if (!lst || !f)
		return (NULL);
	if (!(lst_new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	res = lst_new;
	if (lst->next)
		lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst);
		if (!(lst_new->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst_new = lst_new->next;
		lst = lst->next;
	}
	return (res);
}
