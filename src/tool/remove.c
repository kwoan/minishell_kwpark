/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:17:58 by taehyunk          #+#    #+#             */
/*   Updated: 2023/01/15 16:20:35 by kwpark           ###   ########.fr       */
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
		if (strs[i][1] == '?')
		{
			temp = strs[i];
			strs[i] = ft_itoa(g_exit_code);
			free(temp);
			break;
		}
		else if ((strs[i][1] == '\'' && ft_strchr(strs[i] + 2, '\'')) || \
					(strs[i][1] == '\"' && ft_strchr(strs[i] + 2, '\"')))
		{
			temp = strs[i];
			strs[i] = ft_strdup(strs[i] + 1);
			free(temp);
			break;
		}
		else if (ft_strncmp(e_lst->content, strs[i] + 1, ft_strlen(strs[i] + 1)) == 0
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

char	*remove_dollar(t_list *envp_lst, char *str, size_t (*f)(char const *s1, char c1))
{
	char	**strs;
	char	*dest;
	char	*temp;
	int		i;

	if (check_dollar(str))
		return (str);
	strs = ft_split_dollar(str, '$', f);
	i = 0;
	dest = ft_strdup("");
	while (strs[i])
	{
		if (strs[i][0] == '\"' && ft_strchr(strs[i], '\"'))
		{
			// temp = strs[i];
			strs[i] = remove_dollar(envp_lst, strs[i], dollar_check_quote_dq);
			// free(temp);
		}
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
