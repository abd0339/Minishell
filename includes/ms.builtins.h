#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

# include <limits.h>
# include "minishell.h"

int	ms_is_builtin(char *cmd_name);
int	ms_run_builtin(t_data *data, t_command *cmd);
int	ms_builtin_env(t_list *env_list);
int	ms_builtin_echo(char **args);
int	ms_run_builtin(t_data *data, t_command *cmd);

int	ms_builtin_cd(t_data *data, char **args);
int	ms_builtin_unset(t_data *data, char **args);
int	ms_builtin_export(t_data *data, char **args);
int	ms_builtin_exit(t_data *data, char **args);

#endif