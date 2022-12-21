/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:22:52 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 15:22:52 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			idx;

	if (!dest && !src)
		return (NULL);
	temp_dest = dest;
	temp_src = (unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		*(temp_dest + idx) = *(temp_src + idx);
		idx++;
	}
	return (dest);
}
