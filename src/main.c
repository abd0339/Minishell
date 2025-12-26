
#include "../includes/minishell.h"
#include "../includes/ms_lexer.h"
#include "../includes/ms_parser.h"
#include "../includes/ms_exec.h"

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
		if (!line)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			break ;
		}
		if (line[0] == '\0' || ft_isspace_only(line))
		{
			free(line);
			continue ;
		}
		add_history(line);
		
		// LEXER
		tokens = ms_lexer(line);
		if (tokens)
		{
			printf("[DEBUG] Tokens created\n");  // ADD THIS
			ms_print_tokens(tokens);              // ADD THIS
		}
		else
			printf("[DEBUG] Lexer failed\n");     // ADD THIS
		
		// PARSER
		if (tokens)
		{
			data->command_list = ms_parser(tokens);
			if (data->command_list)
				printf("[DEBUG] Parser success - commands created\n");  // ADD THIS
			else
				printf("[DEBUG] Parser failed\n");  // ADD THIS
		}
		
		// EXECUTION
		if (data->command_list)
			ms_execute_manager(data);
		
		// CLEANUP
		if (data->command_list)
			ft_lstclear(&(data->command_list), ms_free_command_node);
		if (tokens)
			ft_lstclear(&tokens, ms_free_token);
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