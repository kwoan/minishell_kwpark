/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:28:21 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 22:28:21 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	idx;
	size_t	len;
	char	*dest;

	idx = 0;
	len = ft_strlen(s);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	while (idx < len)
	{
		dest[idx] = f(idx, s[idx]);
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}
