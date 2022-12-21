/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:29:23 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/19 16:11:07 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	get_lst_size(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		if (ft_strncmp(lst->content, "?", 1) == 0)
		{
			lst = lst->next;
			continue ;
		}
		size++;
		lst = lst->next;
	}
	return (size);
}

char	**lst_to_arr(t_list *lst)
{
	char	**dest;
	int		size;

	size = get_lst_size(lst);
	dest = malloc(sizeof(char *) * (size + 1));
	if (!dest)
		return (NULL);
	size = 0;
	while (lst)
	{
		if (ft_strncmp(lst->content, "?", 1) == 0)
		{
			lst = lst->next;
			continue ;
		}
		dest[size++] = strdup(lst->content);
		if (!dest[size - 1])
		{
			free_str_arr(dest);
			return (NULL);
		}
		lst = lst->next;
	}
	dest[size] = NULL;
	return (dest);
}

t_list	*check_lst(t_list *lst)
{
	while (!lst->content)
		lst = lst->next;
	return (lst);
}
