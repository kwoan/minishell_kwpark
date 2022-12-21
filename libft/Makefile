# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehyunk <taehyunk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 23:28:49 by taehyunk          #+#    #+#              #
#    Updated: 2022/11/29 19:16:25 by taehyunk         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


 NAME = libft.a
 
 SRC = ft_isalpha.c \
 		ft_isdigit.c \
 		ft_isalnum.c \
 		ft_isascii.c \
 		ft_isprint.c \
 		ft_strlen.c \
 		ft_memset.c \
 		ft_bzero.c \
 		ft_memcpy.c \
 		ft_memmove.c \
 		ft_strlcpy.c \
 		ft_strlcat.c \
 		ft_strncmp.c \
 		ft_toupper.c \
 		ft_tolower.c \
 		ft_strchr.c \
 		ft_strrchr.c \
 		ft_memchr.c \
 		ft_memcmp.c \
 		ft_strnstr.c \
 		ft_atoi.c \
 		ft_calloc.c \
 		ft_strdup.c \
 		ft_substr.c \
 		ft_strjoin.c \
 		ft_strtrim.c \
 		ft_split.c \
 		ft_itoa.c \
 		ft_strmapi.c \
 		ft_striteri.c \
 		ft_putchar_fd.c \
 		ft_putstr_fd.c \
 		ft_putendl_fd.c \
 		ft_putnbr_fd.c \

 BOUNS_SRC = 	ft_lstnew.c \
 				ft_lstadd_front.c \
 				ft_lstsize.c \
 				ft_lstlast.c \
 				ft_lstadd_back.c \
 				ft_lstdelone.c \
 				ft_lstclear.c \
 				ft_lstiter.c \
 				ft_lstmap.c \

 INCS_DIR	= ./include/
 SRCS_DIR	= ./src/

 SRCS = $(addprefix $(SRCS_DIR), $(SRC))
 OBJS = $(SRCS:.c=.o)
 BOUNS_SRCS = $(addprefix $(SRCS_DIR), $(BOUNS_SRC))
 BOUNS_OBJS = $(BOUNS_SRCS:.c=.o)
 
 CC = cc
 CFLAGS = -c -Wall -Wextra -Werror
 
 all : $(NAME)
 
 $(NAME) : $(OBJS)
	ar -rc $@ $^

 bonus : $(NAME) $(BOUNS_OBJS)
	ar -rc $(NAME) $(BOUNS_OBJS)

 %.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $< 

 clean :
	rm -rf $(OBJS) $(BOUNS_OBJS)
		
 fclean : clean
	rm -rf $(NAME)
	
 re : fclean all
   
 .PHONY : all clean fclean re bonus	
 