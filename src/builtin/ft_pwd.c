/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:35:00 by taehyunk          #+#    #+#             */
/*   Updated: 2023/01/16 15:13:33 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (str)
	{
		ft_putstr_fd(str, STDOUT);
		ft_putstr_fd("\n", STDOUT);
		free(str);
	}
	else
	{
		ft_putstr_fd("pwd: error retrieving current directory", 2);
		ft_putstr_fd(": getcwd: No such file or directory\n", 2);
	}
	return (0);
}
