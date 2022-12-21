/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:27:35 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 22:27:35 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	get_digit(int n)
{
	int			digit;
	long long	temp;

	digit = 1;
	temp = n;
	if (temp < 0)
	{
		temp = -(temp);
		digit++;
	}
	while (temp > 9)
	{
		temp /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int			idx;
	char		*str;
	long long	temp;

	idx = get_digit(n);
	str = (char *)malloc(idx + 1);
	if (!str)
		return (NULL);
	temp = n;
	if (temp < 0)
		temp = -(temp);
	str[idx--] = '\0';
	while (temp > 9)
	{
		str[idx--] = temp % 10 + '0';
		temp /= 10;
	}
	str[idx--] = temp + '0';
	if (idx == 0)
		str[idx] = '-';
	return (str);
}
