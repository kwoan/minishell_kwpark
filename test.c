#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

#include "libft/include/libft.h"

typedef struct s_list
{
	// void				*content;
	char				*content;
	int					type;
	struct s_list		*next;
}	t_list;



static size_t	check_quote(char const *s, char c)
{
	size_t	len;
	char	temp;

	len = 0;
	temp = 0;
	while (s[len])
	{
		if (!temp && s[len] == c)
			break ;
		else if (len == 0 && (s[len] == '\'' || s[len] == '\"'))
			temp = s[len];
		else if (!temp && (s[len] == '\'' || s[len] == '\"'))
			break ;
		else if (temp && s[len] == temp)
		{
			len++;
			break ;
		}
		len++;
	}
	return (len);
}

static size_t	get_size(char const *s, char c)
{
	size_t	cnt;
	size_t	len;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		len = check_quote(s, c);
		if (len == 0 && s[len])
			len++;
		s += len;
		cnt++;
	}
	return (cnt);
}

static int	free_strs(char **strs, size_t idx)
{
	while (idx-- > 0)
		free(strs[idx]);
	free(strs);
	return (0);
}

static int	set_strs(size_t size, char **strs, char const *s, char c)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	while (idx < size)
	{
		if (*s == c)
			len = check_quote(s + 1, c) + 1;
		else
			len = check_quote(s, c);
		if (len == 1 && s[len])
			len++;
		strs[idx] = (char *)malloc(len + 1);
		if (!strs[idx])
			return (free_strs(strs, idx));
		ft_strlcpy(strs[idx], s, len + 1);
		s += len;
		idx++;
	}
	strs[idx] = NULL;
	return (1);
}

char	**ft_split_dollar(char const *s, char c)
{
	size_t	size;
	char	**strs;

	size = get_size(s, c);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL);
	if (!set_strs(size, strs, s, c))
		return (NULL);
	return (strs);
}


int	main(int ac, char **av)
{
	char **strs = ft_split_dollar("\"$USERbb\"", '$');
	int	i = 0;

	while (strs[i])
	{
		printf("ttt : %s\n", strs[i]);
		i++;
	}
}


// static void	replace_quote(char *c, char *start, char *flag, char **dest)
// {
// 	int		num;
// 	char	*temp;

// 	num = (*flag == *c);
// 	if (!num)
// 		*flag = *c;
// 	*c = 0;
// 	temp = *dest;
// 	*dest = ft_strjoin(*dest, start + num);
// 	free(temp);
// 	*c = *flag;
// 	if (num)
// 		*flag = 0;
// }

// char	*remove_quote(char *str)
// {
// 	char	*start;
// 	char	*dest;
// 	char	*temp;
// 	char	flag;

// 	if (!ft_strchr(str, '\"') && !ft_strchr(str, '\''))
// 		return (str);
// 	start = str;
// 	flag = 0;
// 	dest = ft_strdup("");
// 	while (*str)
// 	{
// 		if ((!flag && (*str == '\'' || *str == '\"')) || (flag == *str))
// 		{
// 			replace_quote(&*str, start, &flag, &dest);
// 			start = str;
// 			if (!flag)
// 				start++;
// 		}
// 		str++;
// 	}
// 	temp = dest;
// 	dest = ft_strjoin(dest, start);
// 	free(temp);
// 	return (dest);
// }

// int	main()
// {
// 	char	*str;

// 	str = ft_strdup("\"kwpark");
	
// 	printf("%s\n", remove_quote(str));
// }