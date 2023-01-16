/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:17:58 by taehyunk          #+#    #+#             */
/*   Updated: 2023/01/16 13:55:00 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	replace_quote(char *c, char *start, char *flag, char **dest)
{
	int		num;
	char	*temp;

	num = (*flag == *c);
	if (!num)
		*flag = *c;
	*c = 0;
	temp = *dest;
	*dest = ft_strjoin(*dest, start + num);
	free(temp);
	*c = *flag;
	if (num)
		*flag = 0;
}

char	*remove_quote(char *str)
{
	char	*start;
	char	*dest;
	char	*temp;
	char	flag;

	if (!ft_strchr(str, '\"') && !ft_strchr(str, '\''))
		return (str);
	start = str;
	flag = 0;
	dest = ft_strdup("");
	while (*str)
	{
		if ((!flag && (*str == '\'' || *str == '\"')) || (flag == *str))
		{
			replace_quote(&*str, start, &flag, &dest);
			start = str;
			if (!flag)
				start++;
		}
		str++;
	}
	temp = dest;
	dest = ft_strjoin(dest, start);
	free(temp);
	return (dest);
}
