/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:17:58 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/21 15:04:27 by taehyunk         ###   ########seoul.kr  */
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

static int	check_dollar(char *str)
{
	while (*str && *str != '$')
		str++;
	return (*str == 0);
}

static void	replace_dollar(t_list *e_lst, char **strs, int i)
{
	char	*temp;

	while (e_lst)
	{
		if (ft_strncmp(e_lst->content, strs[i] + 1, ft_strlen(strs[i] + 1)) == 0
			&& ((char *)e_lst->content)[ft_strlen(strs[i] + 1)] == '=')
		{
			temp = strs[i];
			strs[i] = ft_strdup(ft_strchr(e_lst->content, '=') + 1);
			free(temp);
			break ;
		}
		e_lst = e_lst->next;
	}
	if (!e_lst)
	{
		free(strs[i]);
		strs[i] = ft_strdup("");
	}
}

char	*remove_dollar(t_list *envp_lst, char *str)
{
	char	**strs;
	char	*dest;
	char	*temp;
	int		i;

	if (check_dollar(str))
		return (str);
	strs = ft_split_dollar(str, '$');
	i = 0;
	dest = ft_strdup("");
	while (strs[i])
	{
		if (strs[i][0] == '$' && strs[i][1])
			replace_dollar(envp_lst, strs, i);
		temp = dest;
		dest = ft_strjoin(dest, strs[i]);
		free(temp);
		i++;
	}
	free_str_arr(strs);
	return (dest);
}
