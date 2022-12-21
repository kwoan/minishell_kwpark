/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:03:42 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/20 17:03:42 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*start;
	t_list	*con_list;

	start = ft_lstnew(f(lst->content));
	if (!start)
		return (NULL);
	con_list = start;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		con_list->next = temp;
		con_list = temp;
		lst = lst->next;
	}
	return (start);
}
