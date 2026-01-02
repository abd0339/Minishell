#include "../../includes/minishell.h"


/* Saves the original standard I/O file descriptors.
 This is crucial for restoration after redirections (P3.2).
 param data The main shell structure */
static void	ms_save_io(t_data *data)
{
	data->stdin_backup = dup(STDIN_FILENO);
	data->stdout_backup = dup(STDOUT_FILENO);
	if (data->stdin_backup == -1 || data->stdout_backup == -1)
	{
		perror("minishell: Fatal I/O setup error");
		exit(EXIT_FAILURE);
	}
}

/* Restores the original standard I/O streams and closes backup FDs.
Used before exiting or when a command fails/finishes.
param data The main shell structure.
 */
static void	ms_restore_io_and_close_backups(t_data *data)
{
	if (data->stdin_backup != -1)
	{
		dup2(data->stdin_backup, STDIN_FILENO);
		close(data->stdin_backup);
		data->stdin_backup = -1;
	}
	if (data->stdout_backup != -1)
	{
		dup2(data->stdout_backup, STDOUT_FILENO);
		close(data->stdout_backup);
		data->stdout_backup = -1;
	}
}
/* Placeholder for freeing a single t_command node and its contents.
 This function will be properly implemented by Student A (P1 cleanup).
 param content A pointer to the t_command struct content */
static void	ms_free_command_node(void *content)
{
	t_command	*cmd;
	
	cmd = (t_command *)content;
	if (!cmd)
		return ;
	(void)cmd;
}
void	ms_init_data(t_data *data, char **envp)
{
	data->env_list = NULL;
	data->command_list = NULL;
	data->last_exit_code = 0;
	ms_save_io(data);
	data->env_list = ms_create_env_list(envp);
	if (!data->env_list)
	{
		ft_printf(stderr, "minishell: WARNING: Could not initialize environment.\n");
	}
}

/* Cleans up all dynamically allocated memory before exiting.
 This should be called before `return (exit_code)` in main.
 param data The main shell structure */
void	ms_cleanup(t_data *data)
{
	if (data->env_list)
		ft_lstclear(&(data->env_list), ms_free_env_node);
	if (data->command_list)
		ft_lstclear(&(data->command_list), ms_free_command_node);
	ms_restore_io_and_close_backups(data);
}