#include "../../includes/minishell.h"

/* Converts our t_list environment into the char ** format for execve, env_list The linked list of environment variables
char** The array of "KEY=VALUE" strings, NULL terminated */
static char	**ms_get_env_array(t_list *env_list)
{
	char	**env_array;
	t_list	*tmp;
	t_env	*env;
	int		i;

	env_array = malloc(sizeof(char *) * (ft_lstsize(env_list) + 1));
	if (!env_array)
		return (NULL);
	tmp = env_list;
	i = 0;
	while (tmp)
	{
		env = (t_env *)tmp->content;
		env_array[i] = ft_strjoin_three(env->key, "=", env->value);
		if (!env_array[i])
		{
			ft_free_array(env_array);
			return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
	env_array[i] = NULL;
	return (env_array);
}

/* Handles the actual execution of an external command , This function is called inside a child process
data Main shell data , cmd Current command structure */
void	ms_execute_external(t_data *data, t_command *cmd)
{
	pid_t	pid;
	int		status;
	char	*path;
	char	**env_tab;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell: fork");
		data->last_exit_code = 1;
		return ;
	}
	if (pid == 0)  // ✅ CHILD PROCESS ONLY
	{
		// Resolve path
		path = ms_resolve_path(data, cmd->args[0]);
		if (!path)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(cmd->args[0], 2);
			ft_putendl_fd(": command not found", 2);
			ms_cleanup(data);
			exit(127);  // ✅ Only child exits
		}
		
		// Setup redirections
		if (ms_setup_redirections(cmd) != 0)
		{
			free(path);
			ms_cleanup(data);
			exit(1);
		}
		
		// Get environment
		env_tab = ms_get_env_array(data->env_list);
		if (!env_tab)
		{
			free(path);
			ms_cleanup(data);
			exit(EXIT_FAILURE);
		}
		
		// Execute
		execve(path, cmd->args, env_tab);
		
		// If execve fails (only reaches here on error)
		perror("minishell: execve");
		free(path);
		ft_free_array(env_tab);
		ms_cleanup(data);
		exit(126);
	}
	else  // ✅ PARENT PROCESS
	{
		// Wait for child to finish
		waitpid(pid, &status, 0);
		
		// Update exit code
		if (WIFEXITED(status))
			data->last_exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			data->last_exit_code = 128 + WTERMSIG(status);
		
		// ✅ Parent continues - NO exit() here!
	}
}

/* Forking logic for a single (non-piped) external command ,data Main shell data 
cmd Current command structure  */
void	ms_execute_fork(t_data *data, t_command *cmd)
{
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		perror("minishell: fork");
		data->last_exit_code = 1;
		return ;
	}
	if (cmd->pid == 0)
	{
		if (ms_setup_redirections(cmd) != 0)
		{
			ms_cleanup(data);
			exit(EXIT_FAILURE);
		}
		ms_execute_external(data, cmd);
	}
	ms_wait_all(data);
}