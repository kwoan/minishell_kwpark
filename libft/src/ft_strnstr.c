/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:24:58 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 21:24:58 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	char	*temp_little;
	char	*temp_big;

	temp_little = (char *)little;
	temp_big = (char *)big;
	if (*temp_little == '\0')
		return (temp_big);
	little_len = ft_strlen(temp_little);
	while (*temp_big && len-- >= little_len)
	{
		if (*temp_big == *little
			&& ft_strncmp(temp_big, temp_little, little_len) == 0)
			return (temp_big);
		temp_big++;
	}
	return (NULL);
}
