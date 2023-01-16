/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:38:21 by taehyunk          #+#    #+#             */
/*   Updated: 2023/01/12 17:19:33 by taehyunk         ###   ########seoul.kr  */
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

int	check_syntax_error(t_list *lst)
{
	while (lst)
	{
		if (lst->type > 1)
		{
			if ((lst->type != T_PIPE
					&& (!lst->next || lst->next->type != T_TEXT))
				|| (lst->type == T_PIPE
					&& (!lst->next || lst->next->type == T_PIPE)))
			{
				ft_putstr_fd
					("minishell: syntax error near unexpected token `", 2);
				ft_putstr_fd(lst->content, 2);
				ft_putstr_fd("`\n", 2);
				g_exit_code = 258;
				return (0);
			}
		}
		lst = lst->next;
	}
	return (1);
}
