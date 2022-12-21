/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:21:32 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/11 17:01:06 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	fd_close(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

void	dup_infile(t_list *infile, t_fd_data *data)
{
	int		infile_fd;
	int		fd[2];
	char	*str;
	int		temp_out;

	if (infile->type == T_LEFT)
	{
		infile_fd = open(ft_lstlast(infile)->content, O_RDWR);
		dup2(infile_fd, STDIN);
	}
	else
	{
		pipe(fd);
		temp_out = dup(STDOUT);
		dup2(data->backup[0], STDIN);
		dup2(data->backup[1], STDOUT);
		str = heredoc(infile->content);
		write(fd[1], str, ft_strlen(str));
		free(str);
		dup2(fd[0], STDIN);
		dup2(temp_out, STDOUT);
		fd_close(fd);
		close(temp_out);
	}
}

void	dup_outfile(t_list *outfile)
{
	int	outfile_fd;

	while (outfile)
	{
		if (outfile->type == T_RIGHT)
			outfile_fd = open(outfile->content, O_WRONLY
					| O_CREAT | O_TRUNC, 0664);
		else
			outfile_fd = open(outfile->content, O_WRONLY
					| O_CREAT | O_APPEND, 0664);
		outfile = outfile->next;
	}
	dup2(outfile_fd, STDOUT);
}
