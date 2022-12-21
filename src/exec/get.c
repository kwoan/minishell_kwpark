/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:00:07 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/11 17:37:42 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	get_pipe_cnt(t_list *cmd)
{
	int	cnt;

	cnt = 1;
	while (cmd)
	{
		if (cmd->type == T_PIPE)
			cnt++;
		cmd = cmd->next;
	}
	return (cnt);
}

t_list	*get_next_pipe(t_list *cmd)
{
	while (cmd)
	{
		if (cmd->type == T_PIPE)
			return (cmd->next);
		cmd = cmd->next;
	}
	return (cmd);
}

static int	get_cnt(t_list *cmd)
{
	int		cnt;

	cnt = 0;
	while (cmd)
	{
		if (cmd->type == T_PIPE)
			break ;
		else if (cmd->type != T_TEXT)
			cmd = cmd->next;
		else
			cnt++;
		cmd = cmd->next;
	}
	return (cnt);
}

char	**get_argv(t_list *cmd)
{
	char	**dest;
	int		i;

	dest = (char **)malloc(sizeof(char *) * (get_cnt(cmd) + 1));
	i = 0;
	while (cmd)
	{
		if (cmd->type == T_PIPE)
			break ;
		else if (cmd->type != T_TEXT)
			cmd = cmd->next;
		else
			dest[i++] = ft_strdup(cmd->content);
		cmd = cmd->next;
	}
	dest[i] = NULL;
	return (dest);
}

t_list	*get_file(t_list *cmd, int type)
{
	t_list	*lst;
	t_list	*start;
	int		temp;

	lst = 0;
	start = lst;
	while (cmd)
	{
		if (cmd->type == type || cmd->type == type + 1)
		{
			temp = cmd->type;
			cmd = cmd->next;
			lst = ft_lstnew(cmd->content);
			lst->type = temp;
			if (!start)
				start = lst;
			else
				ft_lstadd_back(&start, lst);
			lst = lst->next;
		}
		else if (cmd->type == T_PIPE)
			break ;
		cmd = cmd->next;
	}
	return (start);
}
