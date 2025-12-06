#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

# include "minishell.h"

int		ms_is_builtin(char *cmd_name);
int		ms_run_builtin(t_data *data, t_command *cmd);


// Complex (Student B)
int		ms_cd(t_data *data, t_command *cmd);
int		ms_export(t_data *data, t_command *cmd);
int		ms_unset(t_data *data, t_command *cmd);
int		ms_exit(t_command *cmd);

#endif