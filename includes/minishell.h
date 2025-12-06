#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <string.h>
# include "../libft/libft.h"


typedef struct s_env
{
	char	*key;
	char	*value;
	int		is_exported; 
} t_env;

typedef struct s_command
{
	char			**args;			// Argument vector: {"ls", "-l", NULL}
	t_list			*redirections;	// Linked list of t_redir structs
	int				is_builtin;		// Flag to identify built-ins early (1 or 0)
	pid_t			pid;			// Process ID for the child process 
	int				in_fd;			// Input file descriptor (default STDIN)
	int				out_fd;			// Output file descriptor (default STDOUT)
} t_command;

typedef struct s_data
{
	t_list			*env_list;		// Linked list of t_env structs
	int				last_exit_code;	// Value of $?
	t_list			*command_list;	// Linked list of t_command structs (The parsed pipeline)
	int				stdin_backup;
	int				stdout_backup; // File Descriptors (Optional, but good practice)
} t_data;

extern int	global_signal_status;

#endif