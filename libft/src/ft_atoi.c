/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:57:55 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 21:57:55 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *nptr)
{
	int					minus;
	unsigned long long	result;

	minus = 1;
	result = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-')
		minus = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + *nptr - '0';
		nptr++;
		if (result > 9223372036854775807)
		{
			if (minus == -1)
				return (0);
			return (-1);
		}
	}
	return ((int)(result * minus));
}
