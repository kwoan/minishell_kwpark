/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:40:57 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/03 12:40:57 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	check_quote(char const *s, char c)
{
	size_t	len;
	char	temp;

	len = 0;
	temp = 0;
	while (s[len])
	{
		if (!temp && s[len] == c)
			break ;
		else if (len == 0 && (s[len] == '\'' || s[len] == '\"'))
			temp = s[len];
		else if (!temp && (s[len] == '\'' || s[len] == '\"'))
			break ;
		else if (temp && s[len] == temp)
		{
			len++;
			break ;
		}
		len++;
	}
	return (len);
}

static size_t	get_size(char const *s, char c)
{
	size_t	cnt;
	size_t	len;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		len = check_quote(s, c);
		if (len == 0 && s[len])
			len++;
		s += len;
		cnt++;
	}
	return (cnt);
}

static int	free_strs(char **strs, size_t idx)
{
	while (idx-- > 0)
		free(strs[idx]);
	free(strs);
	return (0);
}

static int	set_strs(size_t size, char **strs, char const *s, char c)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	while (idx < size)
	{
		if (*s == c)
			len = check_quote(s + 1, c) + 1;
		else
			len = check_quote(s, c);
		if (len == 1 && s[len])
			len++;
		strs[idx] = (char *)malloc(len + 1);
		if (!strs[idx])
			return (free_strs(strs, idx));
		ft_strlcpy(strs[idx], s, len + 1);
		s += len;
		idx++;
	}
	strs[idx] = NULL;
	return (1);
}

char	**ft_split_dollar(char const *s, char c)
{
	size_t	size;
	char	**strs;

	size = get_size(s, c);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL);
	if (!set_strs(size, strs, s, c))
		return (NULL);
	return (strs);
}
