
NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror 
READLINE	= -lreadline

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR	= ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR)


SRC_SETUP	= setup/ms_init.c \
			  setup/ms_env.c

SRC_SIGNALS	= signals/ms_signals.c

SRC_PARSE	= lexer/ms_lexer_main.c \
			  parser/ms_parser_main.c \
			  parser/ms_syntax.c

SRC_EXPAND	= expander/ms_expand_vars.c \
			  expander/ms_remove_quotes.c

SRC_EXEC	= executor/ms_execute.c \
			  executor/ms_pipes.c \
			  executor/ms_path.c \
			  executor/ms_execute_cmd.c

SRC_REDIR	= io_redir/ms_redir_setup.c \
			  io_redir/ms_heredoc.c

SRC_BUILTIN	= builtins/ms_builtin_simple.c \
			  builtins/ms_builtin_complex.c \
			  builtins/ms_builtin_cd.c \
			  builtins/ms_builtin_export.c \
			  builtins/ms_builtin_unset.c \
			  builtins/ms_builtin_exit.c

SRCS		= main.c \
			  $(SRC_SETUP) \
			  $(SRC_SIGNALS) \
			  $(SRC_PARSE) \
			  $(SRC_EXPAND) \
			  $(SRC_EXEC) \
			  $(SRC_REDIR) \
			  $(SRC_BUILTIN)

VPATH		= $(SRC_DIR)
SRCS		:= $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Linking Minishell..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE) -o $@
	@echo "Minishell compiled successfully!"

$(LIBFT):
	@make -sC $(LIBFT_DIR)
	@echo "Libft compiled."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D) 2>/dev/null || true
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -sC $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned object files."

fclean: clean
	@make fclean -sC $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "Cleaned Minishell  and Libft."

re: fclean all

.PHONY: all clean fclean re norm $(LIBFT)