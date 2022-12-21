/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:11:55 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/21 13:08:43 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_env(t_list *envp_lst)
{
	char	*temp;
	char	temp_c;

	while (envp_lst)
	{
		printf("declare -x ");
		temp = ft_strchr(envp_lst->content, '=');
		if (temp)
		{
			temp_c = temp[1];
			temp[1] = 0;
			printf("%s", envp_lst->content);
			temp[1] = temp_c;
			printf("\"%s\"", temp + 1);
		}
		else
			printf("%s", envp_lst->content);
		printf("\n");
		envp_lst = envp_lst->next;
	}
}

t_list	*copy_envp(char **envp)
{
	t_list	*temp;
	t_list	*start;
	t_list	*envp_lst;

	start = ft_lstnew(ft_strdup(*envp));
	if (!start)
		return (NULL);
	envp_lst = start;
	while (*(++envp))
	{
		temp = ft_lstnew(ft_strdup(*envp));
		if (!temp)
		{
			ft_lstclear(&start, free);
			return (NULL);
		}
		envp_lst->next = temp;
		envp_lst = temp;
	}
	return (start);
}

int	ft_env(t_list *envp_lst)
{
	while (envp_lst)
	{
		if (ft_strchr(envp_lst->content, '='))
			printf("%s\n", envp_lst->content);
		envp_lst = envp_lst->next;
	}
	return (0);
}
