/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:12:11 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/19 15:06:15 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_key(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

char	*get_key(char *content)
{
	char	*dest;
	char	*equal;
	int		len;

	equal = ft_strchr(content, '=');
	if (equal)
	{
		if ((equal - 1)[0] == '+')
			len = equal - content;
		else
			len = equal - content + 1;
		dest = ft_strndup(content, len);
	}
	else
		dest = ft_strdup(content);
	return (dest);
}

static void	delete_key_value(t_list *envp_lst, char *str)
{
	int		len;
	char	*key;
	t_list	*pre;

	pre = envp_lst;
	len = ft_strlen(str) + 1;
	while (envp_lst)
	{
		key = get_key(envp_lst->content);
		if (ft_strncmp(key, str, len) == 0)
		{
			pre->next = envp_lst->next;
			free(envp_lst->content);
			free(envp_lst);
			free(key);
			envp_lst->content = NULL;
			return ;
		}
		free(key);
		pre = envp_lst;
		envp_lst = envp_lst->next;
	}
}

int	ft_unset(t_list *envp_lst, char **argv)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	while (argv[i])
	{
		if (check_key(argv[i]))
			delete_key_value(envp_lst, argv[i]);
		else
		{
			print_error_msg("unset", argv[i], "': not a valid identifier\n");
			ret = 1;
		}
		i++;
	}
	return (ret);
}
