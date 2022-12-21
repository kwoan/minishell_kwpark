/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:12:04 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/19 15:50:41 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	*get_lst_export(t_list *envp_lst, char *key)
{
	char	*temp_key;
	int		len;

	len = ft_strlen(key) + 1;
	while (envp_lst)
	{
		temp_key = get_key(envp_lst->content);
		if (ft_strncmp(key, temp_key, len) == 0)
		{
			free(temp_key);
			break ;
		}
		free(temp_key);
		envp_lst = envp_lst->next;
	}
	return (envp_lst);
}

static int	add_key_export(t_list *envp_lst, char *str)
{
	char	*str_key;
	t_list	*start;
	int		ret;

	str_key = get_key(str);
	ret = 1;
	if (!check_key(str_key))
		print_error_msg("export", str, "`: not a valid identifier\n");
	else
	{
		ret = 0;
		start = envp_lst;
		envp_lst = get_lst_export(envp_lst, str_key);
		if (!envp_lst)
			ft_lstadd_back(&start, ft_lstnew(ft_strdup(str)));
	}
	free(str_key);
	return (ret);
}

static int	plus_value_export(t_list *envp, char *str)
{
	char	*str_key;
	char	*value;
	int		ret;

	str_key = get_key(str);
	value = ft_strdup(ft_strchr(str, '='));
	ret = !check_key(str_key);
	if (!check_key(str_key))
		print_error_msg("export", str, "`: not a valid identifier\n");
	else
	{
		if (!get_lst_export(envp, str_key))
			ft_lstadd_back(&envp,
				ft_lstnew(ft_strdup(ft_strjoin(str_key, value))));
		else
		{
			envp = get_lst_export(envp, str_key);
			free(envp->content);
			envp->content = ft_strjoin(envp->content,
					value + (ft_strchr(envp->content, '=') != 0));
		}
	}
	free(str_key);
	free(value);
	return (ret);
}

int	add_value_export(t_list *envp, char *str)
{
	char	*str_key;
	t_list	*start;
	int		ret;

	ret = 1;
	str_key = get_key(str);
	if (!check_key(str_key))
		print_error_msg("export", str, "`: not a valid identifier\n");
	else
	{
		ret = 0;
		start = envp;
		envp = get_lst_export(envp, str_key);
		if (!envp)
			ft_lstadd_back(&start, ft_lstnew(ft_strdup(str)));
		else
		{
			free(envp->content);
			envp->content = ft_strdup(str);
		}
	}
	free(str_key);
	return (ret);
}

int	ft_export(t_list *envp_lst, char **argv)
{
	int	i;
	int	ret;
	int	temp;

	ret = 0;
	if (!argv[1])
		print_env(envp_lst);
	else
	{
		i = 1;
		while (argv[i])
		{
			if (!ft_strchr(argv[i], '='))
				temp = add_key_export(envp_lst, argv[i]);
			else if (ft_strnstr(argv[i], "+="
					, ft_strchr(argv[i], '=') - argv[i] + 1))
				temp = plus_value_export(envp_lst, argv[i]);
			else
				temp = add_value_export(envp_lst, argv[i]);
			if (temp)
				ret = 1;
			i++;
		}
	}
	return (ret);
}
