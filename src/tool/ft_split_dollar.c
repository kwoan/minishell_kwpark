/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:22:51 by kwpark            #+#    #+#             */
/*   Updated: 2023/01/15 16:22:51 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	dollar_check_quote(char const *s, char c)
{
	size_t	len;
	char	temp;

	len = 0;
	temp = 0;
	while (s[len])
	{
		if (!temp && s[len] == c)
			break ;
		else if (!temp && s[len] == '?')
		{
			len++;
			break;
		}
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

size_t	dollar_check_quote_dq(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == c)
			break ;
		else if (s[len] == '\'' || s[len] == '\"' || s[len] == ' ')
		{
			if (len == 0)
				len++;
			break;
		}
		len++;
	}
	return (len);
}

static size_t	get_size(char const *s, char c, size_t (*f)(char const *s1, char c1))
{
	size_t	cnt;
	size_t	len;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		len = (*f)(s, c);
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

static int	set_strs(size_t size, char **strs, char const *s, char c, size_t (*f)(char const *s1, char c1))
{
	size_t	idx;
	size_t	len;

	idx = 0;
	while (idx < size)
	{
		if (*s == c)
			len = (*f)(s + 1, c) + 1;
		else
			len = (*f)(s, c);
		// if (len == 1 && s[len])
		// 	len++;
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

char	**ft_split_dollar(char const *s, char c, size_t (*f)(char const *s1, char c1))
{
	size_t	size;
	char	**strs;

	size = get_size(s, c, f);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL);
	if (!set_strs(size, strs, s, c, f))
		return (NULL);
	return (strs);
}
