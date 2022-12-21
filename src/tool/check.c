/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:38:21 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/11 17:38:39 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_type(t_list *lst)
{
	while (lst)
	{
		if (ft_strncmp(lst->content, "|", 1) == 0)
			lst->type = T_PIPE;
		else if (ft_strncmp(lst->content, "<<", 2) == 0)
					lst->type = T_LEFT_D;
		else if (ft_strncmp(lst->content, ">>", 2) == 0)
					lst->type = T_RIGHT_D;
		else if (ft_strncmp(lst->content, "<", 1) == 0)
					lst->type = T_LEFT;
		else if (ft_strncmp(lst->content, ">", 1) == 0)
					lst->type = T_RIGHT;
		else
			lst->type = T_TEXT;
		lst = lst->next;
	}
}
