/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   execve.c                                          :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/30 18:00:35 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/30 20:06:56 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft_env.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

typedef struct s_execve_environments	t_execve;
typedef struct s_simple_command			t_command;
struct s_execve_environments
{
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

pid_t
	boss_baby(
t_execve parameters,
int close_in_child
)
{
	const pid_t	id = fork();

	if (id < 0)
		return (-1);
	if (id)
		return (id);
	dup2(parameters.in, STDIN_FILENO);
	dup2(parameters.out, STDOUT_FILENO);
	dup2(parameters.err, STDERR_FILENO);
	if (close_in_child != -1)
		close(close_in_child);
	exit(execve(parameters.path, parameters.argv, (char *const *)borrow_env()));
}

int
	pipeline(
t_command	command
)
{
	const int		in = command.infile;
	int				pfd[2];
	int				status;
	unsigned int	i;
	pid_t			id;

	id = fork();
	if (id < 0)
		return (-1);
	if (id)
	{
		waitpid(id, &status, 0);
		while (errno != ECHILD)
			waitpid(0, NULL, 0);
		close(in);
		close(command.outfile);
		return (WEXITSTATUS(status));
	}
	i = -1;
	while (++i < command.count - 1)
	{
		if (pipe(pfd))
		{
			dup2(-1, in);
			continue ;
		}
		command.commands[i].in = in;
		command.commands[i].out = pfd[1];
		command.commands[i].err = command.errfile;
		id = boss_baby(command.commands[i], pfd[0]);
		close(pfd[1]);
		if (id < 0)
			close(pfd[0]);
		dup2(pfd[0], in);
	}
	dup2(in, STDIN_FILENO);
	dup2(command.outfile, STDOUT_FILENO);
	dup2(command.errfile, STDERR_FILENO);
	exit(execve(command.commands[i].path,
			command.commands[i].argv,
			(char *const *)borrow_env()));
}
