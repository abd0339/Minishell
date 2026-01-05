#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"

# define PROMPT "minishell$ "
# define SUCCESS 0
# define ERROR 1
# define CMD_NOT_FOUND 127
# define CMD_NOT_EXECUTABLE 126

extern int	g_signal_status;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_WHITESPACE
}	t_token_type;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}	t_redir_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
}	t_token;

typedef struct s_env
{
	char	*key;
	char	*value;
	int		is_exported;
}	t_env;

typedef struct s_redir
{
	t_redir_type	type;
	char			*file;
}	t_redir;

typedef struct s_command
{
	char	**args;
	t_list	*redirections;
	int		is_builtin;
	pid_t	pid;
	int		in_fd;
	int		out_fd;
}	t_command;

typedef struct s_data
{
	t_list	*env_list;
	t_list	*command_list;
	int		last_exit_code;
	int		stdin_backup;
	int		stdout_backup;
}	t_data;

void	ms_init_data(t_data *data, char **envp);
void	ms_cleanup(t_data *data);
void	ms_save_io(t_data *data);
void	ms_restore_io(t_data *data);
t_list	*ms_create_env_list(char **envp);
char	*ms_get_env_value(t_list *env_list, const char *key);
void	ms_free_env_node(void *content);
void	ms_setup_signals(void);
void	ms_handle_sigint(int sig);
void	ms_free_command_node(void *content);
void	ms_free_redir(void *content);
void	ms_error_exit(const char *msg, int exit_code);
void	ms_print_error(char *cmd, char *msg);

# include "ms.builtins.h"
# include "ms_lexer.h"
# include "ms_parser.h"
# include "ms.exec.h"

#endif