#include "../../includes/minishell.h"

static int	ms_get_unquoted_len(const char *str)
{
	int		i;
	int		len;
	char	quote_state;

	i = 0;
	len = 0;
	quote_state = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			if (!quote_state)
				quote_state = str[i];
			else if (quote_state == str[i])
				quote_state = 0;
		}
		else
			len++;
		i++;
	}
	return (len);
}

static char	*ms_remove_quotes_from_string(char *old_str)
{
	char	*new_str;
	int		old_i;
	int		new_i;
	char	quote_state;

	if (!old_str)
		return (NULL);
	new_str = (char *)malloc(ms_get_unquoted_len(old_str) + 1);
	if (!new_str)
		return (NULL);
	old_i = 0;
	new_i = 0;
	quote_state = 0;
	while (old_str[old_i])
	{
		if (old_str[old_i] == '\'' || old_str[old_i] == '"')
		{
			if (!quote_state)
				quote_state = old_str[old_i];
			else if (quote_state == old_str[old_i])
				quote_state = 0;
		}
		else
			new_str[new_i++] = old_str[old_i];
		old_i++;
	}
	new_str[new_i] = '\0';
	ft_free_and_null((void **)&old_str);
	return (new_str);
}

void	ms_remove_quotes(t_command *cmd)
{
	int		i;
	char	*unquoted_str;

	if (!cmd || !cmd->args)
		return ;
	i = 0;
	while (cmd->args[i])
	{
		unquoted_str = ms_remove_quotes_from_string(cmd->args[i]);
		if (!unquoted_str)
		{
			return ;
		}
		cmd->args[i] = unquoted_str;
		i++;
	}
}