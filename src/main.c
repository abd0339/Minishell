#include "../includes/minishell.h"

/*
** The single allowed global variable (Subject requirement)
** Stores signal status for signal handling
*/
int	g_signal_status = 0;

/*
** The core execution loop of the shell.
** Prompts user, reads input, processes, and executes.
*/
static void	ms_shell_loop(t_data *data)
{
	char	*line;
	t_list	*tokens;

	while (1)
	{
		ms_setup_signals();
		line = readline(PROMPT);
		
		// Handle Ctrl+D (EOF)
		if (!line)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			break ;
		}
		
		// Skip empty lines
		if (line[0] == '\0' || ft_isspace_only(line))
		{
			free(line);
			continue ;
		}
		
		// Add to history
		add_history(line);
		
		// LEXER: Tokenize input
		tokens = ms_lexer(line);
		if (!tokens)
		{
			free(line);
			continue ;
		}
		
		// PARSER: Build command structures
		data->command_list = ms_parser(tokens);
		
		// EXECUTOR: Run commands
		if (data->command_list)
			ms_execute_manager(data);
		
		// CLEANUP
		if (data->command_list)
		{
			ft_lstclear(&(data->command_list), ms_free_command_node);
			data->command_list = NULL;
		}
		ft_lstclear(&tokens, ms_free_token);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		exit_code;

	(void)argc;
	(void)argv;
	
	// Initialize shell data
	ms_init_data(&data, envp);
	
	// Run main loop
	ms_shell_loop(&data);
	
	// Cleanup and exit
	exit_code = data.last_exit_code;
	ms_cleanup(&data);
	
	return (exit_code);
}