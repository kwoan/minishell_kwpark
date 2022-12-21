/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:03:38 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/20 17:03:38 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = NULL;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
	}
	return (temp);
}
