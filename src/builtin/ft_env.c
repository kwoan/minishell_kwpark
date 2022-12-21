/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:11:55 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/21 16:57:41 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static t_list	*get_small(t_list *lst, t_list *small)
{
	t_list	*before;

	before = small;
	small = NULL;
	while (lst)
	{
		if (!before && !small)
			small = lst;
		else if (!before && ft_strcmp(lst->content, small->content) < 0)
			small = lst;
		else if (before && ft_strcmp(lst->content, before->content) > 0)
		{
			if (!small)
				small = lst;
			else if (ft_strcmp(lst->content, small->content) < 0)
				small = lst;
		}
		lst = lst->next;
	}
	return (small);
}

void	print_env(t_list *lst)
{
	t_list	*small;
	char	*temp;
	char	temp_c;

	small = NULL;
	while (lst)
	{
		small = get_small(lst, small);
		if (!small)
			break ;
		printf("declare -x ");
		temp = ft_strchr(small->content, '=');
		if (temp)
		{
			temp_c = temp[1];
			temp[1] = 0;
			printf("%s", small->content);
			temp[1] = temp_c;
			printf("\"%s\"", temp + 1);
		}
		else
			printf("%s", small->content);
		printf("\n");
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
