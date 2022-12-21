# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:20:21 by taehyunk          #+#    #+#              #
#    Updated: 2022/12/21 14:37:04 by taehyunk         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


 NAME = minishell
 
 LIBFT_DIR = ./libft/
 LIBFT = ./libft/libft.a

 INCS_DIR	= ./include/
 SRCS_DIR	= ./src/
 OBJS_DIR	= ./obj/

 SRC =  main.c \
		builtin/ft_pwd.c \
		builtin/ft_env.c \
		builtin/ft_unset.c \
		builtin/ft_export.c \
		builtin/ft_cd.c \
		builtin/ft_exit.c \
		builtin/ft_echo.c \
		exec/ft_exec.c \
		exec/get.c \
		exec/search.c \
		redirection/heredoc.c \
		redirection/fd.c \
		tool/ft_split_lst.c \
		tool/ft_split_dollar.c \
		tool/ft_strndup.c \
		tool/remove.c \
		tool/free.c \
		tool/ft_cmd_lst.c \
		tool/check.c \
		tool/envp.c \
		signal/signal.c \

 OBJ = $(SRC:.c=.o)
 SRCS = $(addprefix $(SRCS_DIR), $(SRC))
 OBJS = $(addprefix $(OBJS_DIR), $(OBJ))
 LINKS = -L$(LIBFT_DIR) -lft
 READLINE_INC = -I$(shell brew --prefix readline)/include/
 READLINE_LIB = -L$(shell brew --prefix readline)/lib/

 FOLDERS =  obj \
			obj/builtin \
			obj/exec \
			obj/redirection \
			obj/tool \
			obj/signal \

 CC = cc
 CFLAGS = -Wall -Wextra -Werror
 
 all : $(NAME)
 
 $(NAME) : $(LIBFT) $(FOLDERS) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(INCS_DIR) $(LINKS) $(READLINE_LIB) $(READLINE_INC) -lreadline

 $(FOLDERS) :
	mkdir -p $(FOLDERS)

 $(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I$(INCS_DIR) $(READLINE_INC) -o $@ -c $< 
	
 clean :
	make -C $(LIBFT_DIR) clean
	rm -rf $(FOLDERS)
	
 fclean : clean
	rm -rf $(LIBFT_DIR)libft.a
	rm -rf $(NAME)
	
 re : fclean all

 $(LIBFT) :
	make -C $(LIBFT_DIR)

 .PHONY : all clean fclean re	
 