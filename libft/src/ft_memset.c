/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:35:23 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 14:35:23 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	size_t			idx;

	temp_s = s;
	idx = 0;
	while (idx < n)
		*(temp_s + idx++) = (unsigned char)c;
	return (s);
}
