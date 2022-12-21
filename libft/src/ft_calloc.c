/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:10:09 by taehyunk          #+#    #+#             */
/*   Updated: 2022/03/19 22:10:09 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;

	temp = (void *)malloc(nmemb * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, nmemb * size);
	return (temp);
}
