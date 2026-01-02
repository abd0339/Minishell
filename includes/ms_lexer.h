#ifndef MS_LEXER_H
# define MS_LEXER_H

# include "minishell.h"

t_list	*ms_lexer(const char *line);
int		ms_is_whitespace(char c);
int		ms_is_separator(char c);
int		ms_is_special_char(char c);
int		ms_is_quote(char c);
int		ms_handle_quotes(const char *s, int i, char quote_type);
int		ms_has_unclosed_quotes(const char *str);
t_token	*ms_create_token(t_token_type type, char *value);
void	ms_free_token(void *content);
char	*ms_extract_word(const char *str, int *i);
char	*ms_extract_quoted(const char *str, int *i, char quote);
t_token	*ms_tokenize_operator(const char *str, int *i);
void	ms_print_tokens(t_list *tokens);

#endif