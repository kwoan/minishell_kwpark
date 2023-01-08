/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:39:02 by taehyunk          #+#    #+#             */
/*   Updated: 2022/12/02 11:39:02 by taehyunk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static int	check_quote_flag(char *str, char temp, char c, size_t len)
// {
// 	if (!temp && (str[len] == '\'' || str[len] == '\"'))
// 		return (1);
// 	else if (temp && temp == str[len])
// 		return (2);
// 	else if (!temp && (str[len] == '|' || str[len] == '<' || str[len] == '>'))
// 	{
// 		if (len == 0
// 			&& (!ft_strncmp(str, "<<", 2) || !ft_strncmp(str, ">>", 2)))
// 			return (4);
// 		else if (len == 0)
// 			return (5);
// 		return (3);
// 	}
// 	else if (!temp && str[len] == c)
// 		return (3);
// 	return (0);
// }

static int  check_sep(char *s, char opened_quote, size_t len)
{
    if (!opened_quote)
    {
        if (s[len] == '\'' || s[len] == '\"')
        {
            if (!ft_strchr(s + len + 1, s[len]))
                return (0);
            else
                return (1);
        }
        else if (s[len] == '|' || s[len] == '<' || s[len] == '>')
        {
            if (len == 0 && (!ft_strncmp(s, "<<", 2) || !ft_strncmp(s, ">>", 2)))
                return (4);
            else if (len == 0)
                return (5);
            return (3);
        }
        else if (s[len] == ' ')
            return (3);
    }
    else
        if (opened_quote == s[len])
            return (2);
    return (0);
}

static size_t	check_quote(char **s, char c)
{
	size_t	len;
	char	temp;
	char	*str;
	int		flag;

	str = *s;
	len = 0;
	temp = 0;
	while (*str && *str == c)
		str++;
	while (str[len])
	{
		// flag = check_quote_flag(str, temp, c, len);
		flag = check_sep(str, temp, len);
		if (flag == 1)
			temp = str[len];
		else if (flag == 2)
			temp = 0;
		if (flag > 3)
			len += (6 - flag);
		if (flag >= 3)
			break ;
		len++;
	}
	*s = str;
	return (len);
}

static t_list	*ft_lstclear_m(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del || !*lst)
		return (NULL);
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	return (NULL);
}

t_list	*ft_split_lst(char *s, char c)
{
	size_t	len;
	t_list	*start;
	t_list	*lst;
	t_list	*temp;

	len = check_quote(&s, c);
	if (!len)
		return (NULL);
	start = ft_lstnew(ft_strndup(s, len + 1));
	lst = start;
	while (*s && start)
	{
		s += len;
		len = check_quote(&s, c);
		if (!len || !*s)
			break ;
		temp = ft_lstnew(ft_strndup(s, len + 1));
		if (!temp)
			return (ft_lstclear_m(&start, free));
		lst->next = temp;
		lst = temp;
	}
	return (start);
}
