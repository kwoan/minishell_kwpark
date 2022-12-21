/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:22:31 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/21 17:56:39 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**find_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

static void	check_cmd(char	**str, char **path)
{
	char	*temp;
	char	*cmd;

	if (ft_strchr(*str, '/') != 0)
		return ;
	temp = ft_strjoin("/", *str);
	while (*path)
	{
		cmd = ft_strjoin(*path, temp);
		if (!access(cmd, F_OK))
		{
			free(*str);
			*str = cmd;
			break ;
		}
		free(cmd);
		path++;
	}
	free(temp);
}

int	ft_exec(t_list *env_lst, char **argv)
{
	pid_t	pid;
	char	**path;
	char	**envp;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		envp = lst_to_arr(env_lst);
		path = find_path(envp);
		if (ft_strchr(argv[0], '/') && access(argv[0], F_OK) == -1)
			print_error_msg2(argv[0], "", "No such file or directory\n");
		else
		{
			check_cmd(&argv[0], path);
			if (execve(argv[0], argv, envp) == -1)
			{
				if (access(argv[0], F_OK) == 0 && access(argv[0], X_OK) == -1)
					print_error_msg2(argv[0], "", "Permission denied\n");
				else if (access(argv[0], F_OK) == 0)
					print_error_msg2(argv[0], "", "is a directory\n");
				else if (access(argv[0], F_OK) == 0)
					print_error_msg2(argv[0], "", "Not a directory\n");
				else
					print_error_msg2(argv[0], "", "command not found\n");
			}
		}
		free_str_arr(envp);
		free_str_arr(path);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (status);
}
