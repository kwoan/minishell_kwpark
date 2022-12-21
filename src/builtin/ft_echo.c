/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:07:36 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/19 15:44:00 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_echo(char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (argv[++i])
	{
		if (ft_strncmp(argv[i], "-n", 2) != 0)
			break ;
		j = 2;
		while (argv[i][j] == 'n')
			j++;
		if (argv[i][j])
			break ;
	}
	flag = (i == 1);
	while (argv[i])
	{
		printf("%s", argv[i++]);
		if (argv[i])
			printf(" ");
	}
	if (flag)
		printf("\n");
	return (0);
}
