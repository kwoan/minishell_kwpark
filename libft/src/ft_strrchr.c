/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:50:14 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 20:50:14 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				idx;
	unsigned char	temp;

	idx = ft_strlen(s) + 1;
	temp = (unsigned char)c;
	while (idx-- > 0)
	{
		if (s[idx] == temp)
			return ((char *)(s + idx));
	}
	return (NULL);
}
