#include "../../includes/minishell.h"

/* Checks if a string represents a valid numeric long long 
param str The string to check , return int 1 if numeric, 0 otherwise */
static int	ms_is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Handles error messaging for the exit builtin
param arg The invalid argument , param error_type 0 for non-numeric, 1 for too many args */
static void	ms_exit_error(char *arg, int error_type)
{
	ft_putstr_fd("minishell: exit: ", 2);
	if (error_type == 0)
	{
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
	else if (error_type == 1)
	{
		ft_putendl_fd("too many arguments", 2);
	}
}

/* Implementation of the 'exit' builtin , Cleans up memory and exits the shell with a specific status.
param data Main shell data , param args Argument vector , return int Returns 1 only if it fails to exit (too many args) */
int	ms_builtin_exit(t_data *data, char **args)
{
	long long	status;

	ft_putendl_fd("exit", STDOUT_FILENO);
	if (args[1])
	{
		if (!ms_is_numeric(args[1]))
		{
			ms_exit_error(args[1], 0);
			ms_cleanup(data);
			exit(2);
		}
		if (args[2])
		{
			ms_exit_error(NULL, 1);
			return (1);
		}
		status = ft_atoll(args[1]);
		ms_cleanup(data);
		exit(status % 256);
	}
	ms_cleanup(data);
	exit(data->last_exit_code);
}