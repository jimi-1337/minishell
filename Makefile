SRC =		main.c \
			./srcs/ft_address_change.c \
			./srcs/ft_adv_split_util.c \
			./srcs/ft_address_change_util.c \
			./srcs/ft_adv_split.c \
			./srcs/ft_cd_utils.c \
			./srcs/ft_echo.c \
			./srcs/ft_check_qt.c \
			./srcs/ft_cd.c \
			./srcs/ft_env.c \
			./srcs/ft_export_util.c \
			./srcs/ft_linked_list_util_2.c \
			./srcs/ft_linked_list.c \
			./srcs/ft_export.c \
			./srcs/ft_linked_list_utile.c \
			./srcs/ft_main_util.c \
			./srcs/ft_pars.c \
			./srcs/ft_pwd.c \
			./srcs/ft_putstr.c \
			./srcs/ft_main_util_2.c \
			./srcs/ft_rewrite_util.c \
			./srcs/ft_red_fun_util.c \
			./srcs/ft_red_fun.c \
			./srcs/ft_strncmp.c \
			./srcs/ft_rewrite.c \
			./srcs/handler.c \
			./srcs/ft_unset.c \
			./srcs/pipe_util.c \
			./srcs/ft_split_2.c \
			./srcs/red_tools.c \
			./srcs/pipe.c \
			./srcs/ft_util.c
		
SRC_LIB=	libft/ft_itoa.c\
			libft/ft_atoi.c\
			libft/ft_bzero.c\
			libft/ft_isalnum.c\
			libft/ft_isalpha.c\
			libft/ft_isascii.c\
			libft/ft_isdigit.c\
			libft/ft_isprint.c\
			libft/ft_memccpy.c\
			libft/ft_memchr.c\
			libft/ft_memcmp.c\
			libft/ft_memcpy.c\
			libft/ft_memmove.c\
			libft/ft_memset.c\
			libft/ft_putchar_fd.c\
			libft/ft_putchar_fd.c\
			libft/ft_putendl_fd.c\
			libft/ft_putnbr_fd.c\
			libft/ft_putstr_fd.c\
			libft/ft_strchr.c\
			libft/ft_strrchr.c\
			libft/ft_strdup.c\
			libft/ft_strjoin.c\
			libft/ft_strlcat.c\
			libft/ft_strlen.c\
			libft/ft_strmapi.c\
			libft/ft_strncmp.c\
			libft/ft_strrchr.c\
			libft/ft_strnstr.c\
			libft/ft_substr.c\
			libft/ft_strtrim.c\
			libft/ft_tolower.c\
			libft/ft_toupper.c\
			libft/ft_strlcpy.c\
			libft/ft_calloc.c\
			libft/ft_split.c \
			libft/ft_lstnew_bonus.c\
			libft/ft_lstmap_bonus.c\
			libft/ft_lstadd_front_bonus.c\
			libft/ft_lstsize_bonus.c\
			libft/ft_lstlast_bonus.c\
			libft/ft_lstadd_back_bonus.c\
			libft/ft_lstdelone_bonus.c\
			libft/ft_lstclear_bonus.c\
			libft/ft_lstiter_bonus.c \
			libft/get_next_line.c \
			libft/get_next_line_util.c

LIBS =	./libft/libft.a

HEADER =	./libft/libft.h \
			./minishell.h

FLAGS = -Wall -Wextra -Werror

NAME = minishell

OBJ = $(SRC:c=o)

OBJ_L = $(SRC_LIB:c=o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(OBJ_L)
	@make -C libft
	@echo "\n"
	@echo "\033[0;32mCompiling minishell..."
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBS)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@gcc ${FLAGS} -c $< -o $@

norm :
	@norminette $(SRC) $(HEADER) $(SRC_LIB)

clean:
	@make clean -C libft
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@make fclean -C libft
	@echo "\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all
