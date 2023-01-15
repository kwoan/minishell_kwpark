/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:21:33 by taehyunk          #+#    #+#             */
/*   Updated: 2023/01/15 16:18:03 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <term.h>
# include "../libft/include/libft.h"

# define STDIN 			0
# define STDOUT 		1
# define STDERR 		2

# define T_TEXT 		1
# define T_PIPE 		2
# define T_LEFT 		3
# define T_LEFT_D		4
# define T_RIGHT 		5
# define T_RIGHT_D 		6

int	g_exit_code;

typedef struct s_list
{
	// void				*content;
	char				*content;
	int					type;
	struct s_list		*next;
}	t_list;

typedef struct s_fd_data
{
	int	fd[2][2];
	int	flag;
	int	backup[2];
	int	pipe_cnt;
}	t_fd_data;

//builtin
//ft_pwd.c
int		ft_pwd(void);
//ft_env.c
t_list	*copy_envp(char **envp);
int		ft_env(t_list *envp_lst);
void	print_env(t_list *envp_lst);
//ft_unset.c
int		ft_unset(t_list *envp_lst, char **argv);
int		check_key(char *str);
char	*get_key(char *content);
//ft_export.c
int		add_value_export(t_list *envp, char *str);
int		ft_export(t_list *envp_lst, char **argv);
t_list	*get_lst_export(t_list *envp_lst, char *key);
//ft_cd.c
int		ft_cd(t_list *envp_lst, char *directory, char *home);
char	*get_envp_value(t_list *envp_lst, char *key);
//ft_echo.c
int		ft_echo(char **argv);
//ft_exit.c
int		ft_exit(char **argv);
int		ft_exit_pipe(char **argv);

//exec
//ft_exec.c
int		ft_exec(t_list *env_lst, char **argv);
//search.c
void	search_cmd(char **argv, t_list *env_lst, char *home, t_fd_data *data);
//get.c
int		get_pipe_cnt(t_list *cmd);
t_list	*get_next_pipe(t_list *cmd);
t_list	*get_file(t_list *cmd, int type);
char	**get_argv(t_list *cmd);

//redirection
//heredoc.c
char	*heredoc(char *str);
//fd.c
void	dup_infile(t_list *infile, t_fd_data *data);
void	dup_outfile(t_list *outfile);
void	fd_close(int fd[2]);

//tool
//ft_split_m.c
char	**ft_split_m(char const *s, char c);
//ft_split_dollar.c
char	**ft_split_dollar(char const *s, char c);
//ft_split_lst.c
t_list	*ft_split_lst(char *s, char c);
//remove.c
char	*remove_quote(char *str);
char	*remove_dollar(t_list *envp_lst, char *str);
//free.c
void	free_str_arr(char **arr);
void	print_error_msg(char *cmd, char *str, char *msg);
void	print_error_msg2(char *cmd, char *str, char *msg);
void	print_error_msg3(char *cmd, char *str, char *msg);
//ft_strndup.c
char	*ft_strndup(const char *s, size_t size);
//ft_list.c
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
//check.c
void	check_type(t_list *lst);
//envp.c
char	**lst_to_arr(t_list *lst);
t_list	*check_lst(t_list *lst);

//signal
//signal.c
void	set_signal(void);
#endif