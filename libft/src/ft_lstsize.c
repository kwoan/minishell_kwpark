/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:03:50 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/20 17:03:50 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*temp;

	cnt = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		cnt++;
	}
	return (cnt);
}
