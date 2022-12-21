/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:11:48 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/19 15:58:35 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_envp_value(t_list *envp_lst, char *key)
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
			return (ft_strdup(ft_strchr(envp_lst->content, '=') + 1));
		}
		free(temp_key);
		envp_lst = envp_lst->next;
	}
	return (NULL);
}

static void	update_pwd(t_list *envp_lst)
{
	char	*value;
	char	*temp;

	value = get_envp_value(envp_lst, "PWD");
	if (value)
	{
		temp = ft_strjoin("OLDPWD=", value);
		add_value_export(envp_lst, temp);
		free(temp);
	}
	free(value);
	value = getcwd(NULL, 0);
	if (value)
	{
		temp = ft_strjoin("PWD=", value);
		add_value_export(envp_lst, temp);
		free(temp);
	}
	free(value);
}

static int	run_chdir(t_list *envp_lst, char *directory)
{
	int	ret;

	ret = chdir(directory);
	if (ret == -1)
	{
		print_error_msg("cd", directory, "`: No such file or directory\n");
		return (256);
	}
	else
		update_pwd(envp_lst);
	return (0);
}

int	ft_cd(t_list *envp_lst, char *directory, char *home)
{
	char	*value;
	char	*key;
	int		ret;

	key = "HOME";
	ret = 1;
	if (directory && ft_strncmp(directory, "-", 2))
		key = "OLDPWD";
	value = get_envp_value(envp_lst, key);
	if (!directory || !ft_strncmp(directory, "~", 2)
		|| !ft_strncmp(directory, "-", 2))
	{
		if (directory && !value && !ft_strncmp(directory, "~", 2))
			ret = run_chdir(envp_lst, home);
		else if (!value)
			print_error_msg("cd", key, "` not set\n");
		else
			ret = run_chdir(envp_lst, value);
	}
	else
		ret = run_chdir(envp_lst, directory);
	free(value);
	return (ret);
}
