/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:03:10 by kzebian           #+#    #+#             */
/*   Updated: 2025/12/26 16:17:27 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ms_lexer.h"

/*
** Extract a regular word from input.
** Handles embedded quotes.
*/
char	*ms_extract_word(const char *str, int *i)
{
	int		start;
	int		len;
	char	*word;
	char	quote;

	start = *i;
	while (str[*i])
	{
		if (ms_is_quote(str[*i]))
		{
			quote = str[*i];
			(*i)++;
			while (str[*i] && str[*i] != quote)
				(*i)++;
			if (str[*i] == quote)
				(*i)++;
		}
		else if (ms_is_whitespace(str[*i]) || ms_is_special_char(str[*i]))
			break ;
		else
			(*i)++;
	}
	len = *i - start;
	word = ft_substr(str, start, len);
	return (word);
}

/*
** Extract quoted string (with quotes preserved).
*/
char	*ms_extract_quoted(const char *str, int *i, char quote)
{
	int		start;
	int		len;
	char	*word;

	start = *i;
	(*i)++;
	while (str[*i] && str[*i] != quote)
		(*i)++;
	if (str[*i] == quote)
		(*i)++;
	len = *i - start;
	word = ft_substr(str, start, len);
	return (word);
}

/*
** Identify and create token for operators: | < > << >>
*/
t_token	*ms_tokenize_operator(const char *str, int *i)
{
	char	*value;

	if ((str[*i] == '<' && str[*i + 1] == '<')
		|| (str[*i] == '>' && str[*i + 1] == '>'))
	{
		value = ft_substr(str, *i, 2);
		(*i) += 2;
		if (value[0] == '<')
			return (ms_create_token(TOKEN_HEREDOC, value));
		else
			return (ms_create_token(TOKEN_APPEND, value));
	}
	value = ft_substr(str, *i, 1);
	(*i)++;
	if (value[0] == '|')
		return (ms_create_token(TOKEN_PIPE, value));
	else if (value[0] == '<')
		return (ms_create_token(TOKEN_REDIRECT_IN, value));
	else
		return (ms_create_token(TOKEN_REDIRECT_OUT, value));
}

/*
** Handle quotes within a string (for compatibility).
*/
int	ms_handle_quotes(const char *s, int i, char quote_type)
{
	int	end;

	end = i + 1;
	while (s[end] && s[end] != quote_type)
		end++;
	if (s[end] == quote_type)
		return (end);
	return (i);
}