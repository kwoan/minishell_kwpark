/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_check_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:01:19 by kwpark            #+#    #+#             */
/*   Updated: 2023/01/15 19:32:07 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	dollar_check_quote(char const *s, char c)
{
	size_t	len;
	char	temp;

	len = -1;
	temp = 0;
	while (s[++len])
	{
		if (!temp && s[len] == c)
			break ;
		else if (!temp && s[len] == '?')
		{
			len++;
			break ;
		}
		else if (len == 0 && (s[len] == '\'' || s[len] == '\"'))
			temp = s[len];
		else if (!temp && (s[len] == '\'' || s[len] == '\"'))
			break ;
		else if (temp && s[len] == temp)
		{
			len++;
			break ;
		}
	}
	return (len);
}

size_t	dollar_check_quote_dq(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == c)
			break ;
		else if (s[len] == '\'' || s[len] == '\"' || s[len] == ' ')
		{
			if (len == 0)
				len++;
			break ;
		}
		len++;
	}
	return (len);
}
