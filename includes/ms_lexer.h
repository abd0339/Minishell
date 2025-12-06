#ifndef MS_LEXER_H
# define MS_LEXER_H

# include "minishell.h"


typedef struct s_token
{
	char				*value;
	enum e_token_type	type;
} t_token;

/* Lexer Functions (P1.1)  or you can creat your function*/
t_list	*ms_lexer(const char *line);
int		ms_is_separator(char c);
int		ms_handle_quotes(const char *s, int i, char quote_type);

#endif