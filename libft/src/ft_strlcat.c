/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:11:44 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 18:11:44 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	idx;
	size_t	src_len;
	size_t	dest_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	idx = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[idx] && idx + dest_len < size - 1)
	{
		dest[idx + dest_len] = src[idx];
		idx++;
	}
	dest[idx + dest_len] = '\0';
	return (dest_len + src_len);
}
