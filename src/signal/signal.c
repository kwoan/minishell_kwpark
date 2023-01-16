/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:42:56 by taehyunk          #+#    #+#             */
/*   Updated: 2023/01/16 16:35:59 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	handle_signal(int signo)
{
	pid_t	pid;

	pid = waitpid(-1, NULL, WNOHANG);
	if (signo == SIGINT)
	{
		printf("\n");
		if (pid == -1)
		{
			g_exit_code = 1;
			if (rl_on_new_line() == -1)
				exit(1);
		}
		else
			g_exit_code = 130;
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
	signal(SIGTSTP, handle_signal);
}

static void	handle_reset_signal(int signo)
{
	waitpid(-1, NULL, WNOHANG);
	(void)signo;
}

void	reset_signal(void)
{
	extern int	rl_catch_signals;

	rl_catch_signals = 0;
	signal(SIGINT, handle_reset_signal);
	signal(SIGQUIT, handle_reset_signal);
	signal(SIGTSTP, handle_reset_signal);
}
