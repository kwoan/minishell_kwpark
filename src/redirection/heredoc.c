/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:52:50 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/11 14:19:07 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*heredoc(char *str)
{
	char	*line;
	char	*dest;
	char	*temp;
	size_t	len;

	dest = ft_strdup("");
	while (1)
	{
		len = ft_strlen(str);
		line = readline("> ");
		if (ft_strlen(line) > len)
			len = ft_strlen(line);
		if (ft_strncmp(str, line, len) != 0)
		{
			temp = ft_strjoin(dest, line);
			free(dest);
			dest = ft_strjoin(temp, "\n");
			free(temp);
		}
		else
			break ;
		free(line);
	}
	return (dest);
}
