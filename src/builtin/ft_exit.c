/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:12:01 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/19 16:24:06 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(char **argv)
{
	int	i;
	int	ret;

	i = 1;
	ret = 1;
	printf("exit\n");
	if (!argv[i])
		exit(0);
	else
	{
		if (check_num(argv[i]) && argv[i + 1])
			print_error_msg2("exit", "", "too many arguments\n");
		else if (check_num(argv[i]))
			exit(ft_atoi(argv[i]));
		else
		{
			print_error_msg2("exit", argv[i], ": numeric argument required\n");
			exit(-1);
		}
	}
	return (ret);
}

int	ft_exit_pipe(char **argv)
{
	int	i;
	int	ret;

	i = 1;
	ret = 1;
	if (!argv[i])
		ret = 0;
	else
	{
		if (check_num(argv[i]) && argv[i + 1])
			print_error_msg2("exit", "", "too many arguments\n");
		else if (check_num(argv[i]))
			ret = ft_atoi(argv[i]);
		else
			print_error_msg2("exit", argv[i], ": numeric argument required\n");
	}
	while (ret < 0)
		ret += 256;
	return (ret % 256);
}
