/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:28:13 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 22:28:13 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(s);
	while (idx < len)
	{
		f(idx, &s[idx]);
		idx++;
	}
}
