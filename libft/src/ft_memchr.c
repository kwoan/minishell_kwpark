/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:59:27 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 20:59:27 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	size_t			idx;

	temp_s = (unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		if (temp_s[idx] == (unsigned char)c)
			return ((void *)s + idx);
		idx++;
	}
	return (NULL);
}
