/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:39:06 by taehyunk          #+#    #+#             */
/*   Updated: 2023/01/16 15:54:05 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	search_cmd(char **argv, t_list *env_lst, char *home, t_fd_data *data)
{
	if (ft_strncmp(argv[0], "cd", 3) == 0)
		g_exit_code = ft_cd(env_lst, argv[1], home);
	else if (ft_strncmp(argv[0], "echo", 5) == 0)
		g_exit_code = ft_echo(argv);
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		g_exit_code = ft_env(env_lst);
	else if (ft_strncmp(argv[0], "exit", 5) == 0 && data->pipe_cnt == 1)
		g_exit_code = ft_exit(argv) % 256;
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		g_exit_code = ft_exit_pipe(argv);
	else if (ft_strncmp(argv[0], "export", 6) == 0)
		g_exit_code = ft_export(env_lst, argv);
	else if (ft_strncmp(argv[0], "pwd", 4) == 0)
		g_exit_code = ft_pwd();
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		g_exit_code = ft_unset(env_lst, argv);
	else
		g_exit_code = ft_exec(env_lst, argv);
}
