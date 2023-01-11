/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:23:20 by kwpark            #+#    #+#             */
/*   Updated: 2023/01/11 13:54:44 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_lst(t_list *lst)
{
	while (lst)
	{
		printf("	print_lst : %s\n", lst->content);
		lst = lst->next;
	}
}

t_list  *parse(char *line, t_list *envp_lst)
{
	t_list  *cmd;
	t_list  *tmp;

	cmd = ft_split_lst(line, ' ');
	tmp = cmd;
	while (tmp)
	{
		tmp->content = remove_dollar(envp_lst, tmp->content);
		// tmp->content = remove_quote(tmp->content);
		tmp = tmp->next;
	}
	return (cmd);
}

int main(int ac, char **av, char **envp)
{
	t_list  *envp_lst;
	t_list  *cmd;
	char	*line;

	
	(void)ac;
	(void)av;
	(void)envp_lst;
	envp_lst = copy_envp(envp);
	line = readline("minishell $ ");
	while (1)
	{
		cmd = parse(line, envp_lst);
		// cmd = ft_split_lst(line, ' ');
		print_lst(cmd);
		free(line);
		line = readline("minishell $ ");
	}
}