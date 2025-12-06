#ifndef MS_EXEC_H
# define MS_EXEC_H

# include "minishell.h"

char	*ms_get_env_value(t_data *data, const char *key);
char	*ms_resolve_path(t_data *data, char *cmd);
void	ms_expand_command(t_data *data, t_command *cmd);

/* Execution Flow (P2.4, P3.4) */
void	ms_execute_manager(t_data *data);
int		ms_execute_single_cmd(t_data *data, t_command *cmd);
void	ms_execute_external(t_data *data, t_command *cmd);

/* Piping and I/O (P3.1) */
void	ms_execute_pipeline(t_data *data);
void	ms_child_process_setup(t_data *data, t_command *cmd, int *pipe_fds, int is_last);

/* Error Handling */
void	ms_error_exit(const char *msg, int exit_code);

#endif