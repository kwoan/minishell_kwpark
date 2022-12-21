/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:35:00 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/19 15:03:39 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	ft_putstr_fd(str, STDOUT);
	ft_putstr_fd("\n", STDOUT);
	free(str);
	return (0);
}
