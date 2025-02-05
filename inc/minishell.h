/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   minishell.h                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/14 21:30:53 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/02/03 19:01:59 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
//	convenience macros
# define DEFAULT_PROMPT "Σ:3 "
# define DEFAULT_CONTINUATION "> "
# define HANDLER_COUNT 2
//	prototype inclusions
# include <stdbool.h>	//	bool
# include <sys/types.h> //	pid_t
//	typedefs
typedef struct s_builtin_utility		t_builtin;
typedef struct s_execve_environments	t_execve;
typedef struct s_simple_command			t_command;

//	enums
enum e_tokenisation_result_type
{
	error,
	partial,
	complete
};

// structs
struct s_builtin_utility
{
	const char	*name;
	int			(*function)(char **);
};
struct s_execve_environments
{
	bool	builtin;
	int		in;
	int		out;
	int		err;
	char	*path;
	char	**argv;
};
struct s_simple_command
{
	unsigned int	count;
	t_execve		*commands;
	int				infile;
	int				outfile;
	int				errfile;
};

//	function prototypes
//	//	porcelain
//	//	job-control
int			
	command(
		const char **argv
		);	// FILE: binlocation.c
			// attempts to find a file by the name of bin somewhere in $PATH
pid_t		
	boss_baby(
		t_execve parameters,
		int close_in_child
		);	// FILE: execution.c
			// execute_in_child() => executive_child() => boss_baby()
			// forks process, child execve's, parent returns pid of child
void		
	set_execve_fds(
		t_execve *parameters,
		int in,
		int out,
		int err
		);	// FILE: execution.c
_Noreturn void
	iterative_pipes(
		t_command command
		);	// FILE: execution.c
			// despite the name, this will also work for non-pipe executions (i
			// hope)
int			
	pipeline(
		t_command command
		);	// FILE: execution.c
			// returns the status of the final command ran
_Noreturn void
	do_execve(
		t_execve parameters
		);	// FILE: execution.c
//	//	builtins
int			
	builtin(
		char **argv
		);	// FILE: binlocation.c
			// checks wether something _is_ a builtin, and if it is, runs it
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
//	//	Helpers
int			
	ft_recalloc(	
		void **ptr,
		size_t old_nmemb,
		size_t new_nmemb,
		size_t size
		);	// FILE: ft_recalloc.c
void
	free_ar(
		char **ar
		);	// FILE: env/enviornment_utils.c
#endif
