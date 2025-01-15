/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   minishell.h                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/14 21:30:53 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/14 21:38:52 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
//	convenience macros
# define DEFAULT_PROMPT "Σ:3 "
# define DEFAULT_CONTINUATION "> "
# define HANDLER_COUNT 2

//	typedefs
typedef struct s_tokenisation_output	t_tokenisation;
typedef struct s_individual_token		t_token;
typedef struct s_builtin_utility		t_builtin;
typedef struct s_redirections			t_redirections;
typedef struct s_simple_command			t_job;

//	enums
enum e_tokenisation_result_type
{
	error,
	partial,
	complete
};
enum e_token_type
{
	undetermined,
	word,
	operator
};

// structs
struct s_individual_token
{
	char				*start;
	char				*end;
	enum e_token_type	type;
	t_token				*next;
};
struct s_tokenisation_output
{
	enum e_tokenisation_result_type	type;
	t_token							*head;
	int								count;
};
struct s_builtin_utility
{
	const char	*name;
	int			(*function)(char **);
};
struct s_redirections
{
	int	stdin;
	int	stdout;
	int	stderr;
};
struct s_simple_command
{
	char			**argv;
	t_redirections	redirections;
};

//	function prototypes
//	//	porcelain

//	//	builtins
int
	builtin(
		char **argv
		);	// FILE: binlocation.c
			// checks wether something _is_ a builtin, and if it is, runs it
int
	command(
		const char **argv
		);	// FILE: binlocation.c
			// attempts to find a file by the name of bin somewhere in $PATH
int
	builtin_echo(
		char **argv
		);	// FILE: builtins.c
int
	builtin_pwd(
		char **argv
		);	// FILE: builtins.c
int
	builtin_export(
		char **argv
		);	// FILE: builtins.c
int
	builtin_unset(
		char **argv
		);	// FILE: builtins.c
int
	builtin_env(
		char **argv
		);	// FILE: builtins.c
#endif
