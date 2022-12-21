/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:28:27 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 22:28:28 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	while (ft_strchr(set, *s1) && *s1)
		s1++;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len - 1]) && len > 0)
		len--;
	return (ft_substr(s1, 0, len));
}
