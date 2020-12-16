# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 13:57:22 by amoujane          #+#    #+#              #
#    Updated: 2020/12/12 13:02:50 by amoujane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_itoa.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strlcpy.c\
		ft_calloc.c\
		ft_split.c\
		get_next_line.c \
		get_next_line_util.c

SRCSB =	ft_lstnew_bonus.c\
		ft_lstmap_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstiter_bonus.c

NAME = libft.a

OBJECT = $(SRCS:.c=.o)

OBJECTB = $(SRCSB:.c=.o)

FLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJECT)
			ar rcs $(NAME) $(OBJECT)

bonus : all $(OBJECTB)
			ar rcs $(NAME) $(OBJECTB)

%.o : %.c
			gcc $(FLAGS) -c $<

clean :
			rm -rf $(OBJECT)
			rm -rf $(OBJECTB)

fclean : clean
			rm -rf $(NAME)

re : fclean all
