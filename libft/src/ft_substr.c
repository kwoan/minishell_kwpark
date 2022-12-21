/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:28:32 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 22:28:32 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	dest_len;

	dest_len = len;
	if (ft_strlen(s) < len)
		dest_len = ft_strlen(s);
	dest = (char *)ft_calloc(dest_len + 1, 1);
	if (!dest)
		return (NULL);
	if (ft_strlen(s) > start)
		ft_strlcpy(dest, s + start, dest_len + 1);
	return (dest);
}
