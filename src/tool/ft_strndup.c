/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:28:26 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/02 17:35:53 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_strndup(const char *s, size_t size)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s) + 1;
	if (len > size)
		len = size;
	dest = (char *)malloc(len);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s, len);
	return (dest);
}
