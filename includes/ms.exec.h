#ifndef MS_EXEC_H
# define MS_EXEC_H

# include "minishell.h"

char	*ms_get_env_value(t_list *env_list, const char *key);
char	*ms_resolve_path(t_data *data, char *cmd);
void	ms_expand_command(t_data *data, t_command *cmd);

/* Execution Flow (P2.4, P3.4) */
void	ms_execute_manager(t_data *data);
void	ms_execute_external(t_data *data, t_command *cmd);
void	ms_execute_fork(t_data *data, t_command *cmd);
void	ms_wait_all(t_data *data);


/* Piping and I/O (P3.1) */
void	ms_execute_pipeline(t_data *data);

/* Error Handling */
void	ms_error_exit(const char *msg, int exit_code);

#endif