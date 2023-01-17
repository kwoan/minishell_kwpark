/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:28:39 by kwpark            #+#    #+#             */
/*   Updated: 2023/01/17 13:45:07 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_dollar(char *str)
{
	while (*str && *str != '$')
		str++;
	return (*str == 0);
}

static int	dollar_exception(char **strs, int i)
{
	char	*temp;

	if (strs[i][1] == '?')
	{
		temp = strs[i];
		strs[i] = ft_itoa(g_exit_code);
		free(temp);
		return (1);
	}
	else if ((strs[i][1] == '\'' && ft_strchr(strs[i] + 2, '\'')) || \
				(strs[i][1] == '\"' && ft_strchr(strs[i] + 2, '\"')))
	{
		temp = strs[i];
		strs[i] = ft_strdup(strs[i] + 1);
		free(temp);
		return (1);
	}
	return (0);
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
	if (dollar_exception(strs, i))
		return ;
	if (!e_lst)
	{
		free(strs[i]);
		strs[i] = ft_strdup("");
	}
}

char	*remove_dollar(t_list *envp_lst, char *str, \
						size_t (*f)(char const *s1, char c1))
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
			strs[i] = remove_dollar(envp_lst, strs[i], dollar_check_quote_dq);
		if (strs[i][0] == '$' && strs[i][1])
			replace_dollar(envp_lst, strs, i);
		temp = dest;
		dest = ft_strjoin(dest, strs[i]);
		free(temp);
		i++;
	}
	free_str_arr(strs);
	free(str);
	return (dest);
}
