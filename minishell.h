/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:32:48 by amoujane          #+#    #+#             */
/*   Updated: 2020/12/18 17:22:42 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <dirent.h>
# include "./libft/libft.h"

typedef struct	s_path
{
	char *pwd;
	char *oldpwd;
	char *home;
}				t_path;

typedef struct	s_upe
{
	char			*key;
	char			*value;
	struct s_upe	*next;
}				t_upe;

typedef struct	s_red
{
	int			out;
	int			in;
	char		*arg;
	char		*cmd;
}				t_red;

int				ft_putchar(char c);
char			*ft_fill_tmp(void);
int				ft_putstr(char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_echo(char **str);
int				ft_echo_flag(char *str);
int				ft_skip_space(char *str);
int				ft_putstr_c(char *str, char c);
char			*ft_adresse(char *str);
void			ft_pwd();
void			ft_cd(char **str);
void			ft_export(char **str);
void			get_pwd(void);
void			ft_env(void);
void			ft_env_init(char *buff);
char			**ft_split_2(char const *s, char c);
void			ft_cmd(char **str);
void			lstadd(t_upe **alst, char *key, char *value);
void			ft_qq(char *str);
void			ft_unset(char **str);
void			delkey(t_upe **alst, char *key);
int				ft_find(char *str, char c);
char			*ft_adresse(char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_check_qt(char *str);
int				ft_sla(char *str);
void			ft_opts(char *str);
char			**ft_adv_split(char *s, char c);
void			ft_pipe_fun(char *str);
char			*ft_rewrite(char *str);
char			*ft_lowstring(char *str);
char			**ft_rewrite_d(char **str);
void			ft_red_fun(char *str);
int				ft_create_file(char *file);
int				ft_check_file(char *file);
char			*ft_super_join(char *s1, char *s2, char *s3);
char			*ft_strcut(char *str, int start, int len);
void			run_shell();
void			ft_free_double(char **str);
int				ft_whitespaces(char *str);
void			*ft_memdel(void *ptr);
char			*ft_find_somthing(char *str);
void			ft_ctrl_bslash(int nb);
void			ft_ctrl_c(int nb);
char			*ft_find_somthing(char *str);
void			ft_newpwd();
void			ft_old_pwd();
char			*ft_find_somthing2(char *str);
char			*ft_strrejoin(char *str, int start, int len);
char			*ft_join(char *s1, char *s2, char *s3);
int				ft_change_handle_q(char **str, char change, char to, int i);
int				ft_change_handle_qq(char **str, char change, char to, int i);
void			ft_change_char(char *str, char change, char to);
void			ft_change_char_tab(char **tab, char c);
char			*ft_super_join(char *s1, char *s2, char *s3);
char			*ft_strcut(char *str, int start, int len);
int				ft_isalnum_(int c);
int				ft_key_valid (char *str);
int				ft_check_key(char *str);
void			ft_get_key_value(char *str, char **key, char **value, int j);
void			ft_add(char *key, char *value);
int				ft_strcmp(const char *s1, const char *s2);
t_upe			*lstnew(char *key, char *value);
void			freenode(t_upe **alst);
void			delpos(t_upe **alst, int position);
void			delkey(t_upe **alst, char *key);
void			lstadd(t_upe **alst, char *key, char *value);
int				ft_str2dlen(char **str);
size_t			ft_count_av(char *str);
char			*ft_cpy_stop(char *s1, char c);
char			*ft_cpy_after(char *s1, char c);
char			**ft_find_path(void);
char			**ft_environ(t_upe *env);
void			ft_replace(char *str);
int				ft_pipe(int fds, char *s1);
int				ft_white_space_fix(char *s);
void			*ft_memdel(void *ptr);
int				ft_check_start(char *str);
void			ft_free_struct(t_upe *env);
int				ft_check_line(char **str, int error);
int				ft_check_slash(char *str);
void			init_cache(void);
int				ft_skip_space(char *str);
int				ft_strlenn(char **str);
int				shell(char **str);
char			**ft_rewrite_d(char **str);
int				ft_valid_name(char *str, int *i);
void			ft_free(char *first, char *last, char *name);
int				ft_return_j(char *str, int j);
void			lstadd_declare(t_upe **alst, char *key, char *value);
void			delkey_declare(t_upe **alst, char *key);
void			ft_check_file_get_cmd_in(char **cmd, char **in);
int				ft_skip_q(char *str, char type);
int				ft_red_out(char *str, int start);
int				ft_error_print(char *str);
int				ft_fork_pf(int fds, char *s1);
void			ft_exit_util(char **new);
void			ft_execute_path_tool(char *str, DIR *dir);
void			ft_check(char **str, char *tmp, DIR *dir);
void			ft_exec_point(char **str, char **env);
t_upe			*g_env_v;
t_path			g_path;
t_red			g_red;
int				g_len_env;
int				g_len_declare;
int				g_indice;
int				g_out;
int				g_in;
int				g_fail;
int				g_f;
int				g_rep_g_fail;
int				g_red_fail;
t_upe			*g_declare;
int				g_path_len;
char			*g_tmp;
char			*g_str;

#endif
