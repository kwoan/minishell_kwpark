/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:28:06 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 22:28:06 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	get_size(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s && *s != c)
				s++;
			cnt++;
		}
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
		len = 0;
		while (*s && *s == c)
			s++;
		while (s[len] && s[len] != c)
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

char	**ft_split(char const *s, char c)
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
