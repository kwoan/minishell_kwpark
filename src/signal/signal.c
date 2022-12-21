/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:42:56 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/21 13:15:16 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_signal(int signo)
{
	pid_t	pid;

	pid = waitpid(-1, NULL, WNOHANG);
	if (signo == SIGINT)
	{
		printf("\n");
		if (pid == -1)
		{
			if (rl_on_new_line() == -1)
				exit(1);
			g_exit_code = 1;
		}
		rl_replace_line("", 1);
		rl_redisplay();
	}
	else if (signo == SIGQUIT && pid != -1)
		printf("Quit: 3\n");
}

void	set_signal(void)
{
	extern int	rl_catch_signals;

	rl_catch_signals = 0;
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}
