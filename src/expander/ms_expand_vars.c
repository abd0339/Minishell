
#include "../../includes/minishell.h"

char	*ms_get_env_value(t_list *env_list, const char *key);

static char	*ms_replace_var(t_data *data, const char *key, int var_len)
{
	char	*var_name;
	char	*value;
	
	if (var_len == 1 && *key == '?')
		return (ft_itoa(data->last_exit_code));
	
	var_name = ft_substr(key, 0, var_len); 
	if (!var_name)
		return (ft_strdup(""));
	
	value = ms_get_env_value(data->env_list, var_name);
	free(var_name);

	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}

static int	ms_get_var_len(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '?')
		return (1);
	while (s[i] && (ft_isalnum(s[i]) || s[i] == '_'))
		i++;
	return (i);
}

static char	*ms_expand_string(t_data *data, char *str)
{
	char	*new_str;
	char	*tmp;
	char	quote_state;
	int		i;
	
	new_str = ft_strdup("");
	if (!new_str)
		return (NULL);
	i = 0;
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
		if (str[i] == '$' && quote_state != '\'')
		{
			i++;
			int	var_len = ms_get_var_len(str + i);
			if (var_len > 0)
			{
				char *value = ms_replace_var(data, str + i, var_len);
				tmp = ft_strjoin(new_str, value);
				ft_free_and_null((void **)&new_str);
				ft_free_and_null((void **)&value);
				new_str = tmp;
				i += var_len;
				continue ;
			}
		}
		char char_to_append[2];
		char_to_append[0] = str[i];
		char_to_append[1] = '\0';
		tmp = ft_strjoin(new_str, char_to_append);
		ft_free_and_null((void **)&new_str);
		new_str = tmp;
		i++;
	}
	return (new_str);
}

void	ms_expand_vars(t_data *data, t_command *cmd)
{
	int		i;
	char	*expanded_str;

	if (!cmd->args)
		return ;
	i = 0;
	while (cmd->args[i])
	{
		expanded_str = ms_expand_string(data, cmd->args[i]);
		if (!expanded_str)
		{
			data->last_exit_code = 1;
			return ;
		}
		ft_free_and_null((void **)&cmd->args[i]);
		cmd->args[i] = expanded_str;
		i++;
	}
}
