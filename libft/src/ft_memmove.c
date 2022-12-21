/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:45:02 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 16:45:02 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (!dest && !src)
		return (NULL);
	temp_dest = dest;
	temp_src = (unsigned char *)src;
	if (temp_src < temp_dest)
	{
		while (n-- > 0)
			*(temp_dest + n) = *(temp_src + n);
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
