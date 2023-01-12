/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:52:50 by taehyunk          #+#    #+#             */
/*   Updated: 2023/01/12 11:44:36 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*heredoc(char *str)
{
	char	*line;
	char	*dest;
	char	*temp;

	dest = ft_strdup("");
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strncmp(str, line, ft_strlen(str) + 1) != 0)
		{
			temp = ft_strjoin(dest, line);
			free(dest);
			dest = ft_strjoin(temp, "\n");
			free(temp);
			free(line);
		}
		else
		{
			free(line);
			break ;
		}
	}
	return (dest);
}
