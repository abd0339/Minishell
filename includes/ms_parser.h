#ifndef MS_PARSER_H
# define MS_PARSER_H

# include "minishell.h"

/*- Parser Functions (P1.2, P1.3) */
t_list	*ms_parser(t_list *tokens);
int		ms_syntax_check(t_list *tokens);
int		ms_add_redirection(t_command *cmd, t_list **current_token);

/* I/O Redirection Setup (P3.2, P3.3 ) */
int		ms_setup_redirections(t_command *cmd);
int		ms_do_heredoc(t_redir *redir);
void	ms_restore_io(t_data *data);
void	ms_save_io(t_data *data);

#endif