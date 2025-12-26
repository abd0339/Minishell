#ifndef MS_PARSER_H
# define MS_PARSER_H

# include "minishell.h"

t_list		*ms_parser(t_list *tokens);
int			ms_syntax_check(t_list *tokens);
t_command	*ms_create_command(void);
void		ms_add_argument(t_command *cmd, char *arg);
int			ms_add_redirection(t_command *cmd, t_list **current_token);
int			ms_setup_redirections(t_command *cmd);
int			ms_do_heredoc(t_redir *redir);
t_redir		*ms_create_redir(t_redir_type type, char *file);
// Add to ms_parser.h
int			ms_is_redir(t_token_type type);
int			ms_count_args(t_list *tokens);
t_command	*ms_build_single_command(t_list **tokens);
#endif