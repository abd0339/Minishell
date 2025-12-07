
#include "includes/minishell.h"
// Assuming ft_isspace_only and ft_lstclear are in libft

// The single allowed global variable (P0.4) to track signal status.
// This is checked by the main loop after readline returns.
int	global_signal_status = 0;

t_list	*ms_lexer(const char *line)
{
	(void)line;
	return (NULL); 
}

t_list	*ms_parser(t_list *tokens)
{
	(void)tokens;
	return (NULL); 
}

void	ms_setup_signals(void)
{
	// Setup handlers for Interactive mode (Ctrl-C, Ctrl-\ ignored)
}

void	ms_execute_manager(t_data *data)
{
	(void)data;
}
/* The core execution loop of the shell (P0.3).
 Prompts user, reads input, processes, and executes.
 param data The main shell structure */
static void	ms_shell_loop(t_data *data)
{
	char	*line;

	while (1)
	{
		ms_setup_signals(); 
		
		// 2. Readline: Display prompt and get input
		line = readline("minishell$ "); 
		
		// 3. Handle Ctrl-D (EOF)
		if (!line)
		{
			ft_printf("exit\n");
			break ;
		}
		if (line[0] == '\0' || ft_isspace_only(line) )
		{
			free(line);
			continue ;
		}

		add_history(line);

		// --- PHASE 1: LEXER & PARSER (Student A) ---
		// data->command_list = ms_parser(ms_lexer(line));
		
		// 5. Execution
		if (data->command_list)
		{
			// --- PHASE 2/3: EXECUTION (Student B) ---
			ms_execute_manager(data);
		}
		
		// 6. Cleanup after each command execution
		// ft_lstclear will call ms_free_command_node (from ms_init.c)
		if (data->command_list)
			ft_lstclear(&(data->command_list), ms_free_command_node);
		data->command_list = NULL;
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		exit_code;

	(void)argc;
	(void)argv;
	ms_init_data(&data, envp);
	ms_shell_loop(&data);
	exit_code = data.last_exit_code;
	ms_cleanup(&data);
	
	return (exit_code);
}