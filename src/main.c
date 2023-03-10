/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:49:02 by taehyunk          #+#    #+#             */
/*   Updated: 2023/01/17 13:44:52 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	run_cmd(t_list *cmd, t_list *env_lst, t_fd_data *data, char *home)
{
	t_list	*infile;
	t_list	*outfile;
	char	**argv;

	argv = get_argv(cmd);
	if (get_pipe_cnt(cmd) != 1)
		dup2(data->fd[data->flag][1], STDOUT);
	infile = get_file(cmd, T_LEFT);
	outfile = get_file(cmd, T_RIGHT);
	if (infile)
		dup_infile(infile, data);
	if (outfile)
		dup_outfile(outfile);
	if (argv[0])
		search_cmd(argv, env_lst, home, data);
	ft_lstclear(&infile, free);
	ft_lstclear(&outfile, free);
	free_str_arr(argv);
}

void	loop_cmd(t_list *cmd, t_list *envp_lst, char *home)
{
	int			pipe_cnt;
	t_fd_data	data;

	pipe_cnt = get_pipe_cnt(cmd);
	data.backup[0] = dup(STDIN);
	data.backup[1] = dup(STDOUT);
	data.flag = 0;
	data.pipe_cnt = pipe_cnt;
	while (pipe_cnt > 0)
	{
		pipe(data.fd[data.flag]);
		run_cmd(cmd, envp_lst, &data, home);
		dup2(data.backup[0], STDIN);
		dup2(data.backup[1], STDOUT);
		if (get_pipe_cnt(cmd) != 1)
			dup2(data.fd[data.flag][0], STDIN);
		cmd = get_next_pipe(cmd);
		fd_close(data.fd[data.flag]);
		data.flag = !data.flag;
		pipe_cnt--;
	}
	fd_close(data.backup);
}

t_list	*parse(char *line, t_list *envp_lst)
{
	t_list	*cmd;
	t_list	*tmp;
	char	*to_free;

	cmd = ft_split_lst(line, ' ');
	check_type(cmd);
	tmp = cmd;
	while (tmp)
	{
		tmp->content
			= remove_dollar(envp_lst, tmp->content, dollar_check_quote);
		to_free = tmp->content;
		tmp->content = remove_quote(tmp->content);
		if (to_free != tmp->content)
			free(to_free);
		tmp = tmp->next;
	}
	return (cmd);
}

static void	run_prompt(t_list *envp_lst, char *home)
{
	char	*line;
	t_list	*cmd;

	line = readline("minishell $ ");
	while (1)
	{
		if (!line)
		{
			printf("\033[1Aminishell $ exit\n");
			break ;
		}
		cmd = parse(line, envp_lst);
		if (cmd && check_syntax_error(cmd))
		{
			loop_cmd(cmd, envp_lst, home);
			envp_lst = check_lst(envp_lst);
		}
		if (ft_strlen(line) > 0)
			add_history(line);
		free(line);
		ft_lstclear(&cmd, free);
		line = readline("minishell $ ");
	}
	free(line);
}

int	main(int argc, char **argv, char **envp)
{
	char	*home;
	t_list	*envp_lst;

	(void)argc;
	(void)argv;
	g_exit_code = 0;
	envp_lst = copy_envp(envp);
	home = get_envp_value(envp_lst, "HOME");
	set_signal();
	run_prompt(envp_lst, home);
	free(home);
	return (0);
}
