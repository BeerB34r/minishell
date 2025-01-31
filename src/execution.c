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

#include <minishell.h>
#include <ft_env.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

_Noreturn void
	do_execve(
t_execve parameters
)
{
	dup2(parameters.in, STDIN_FILENO);
	dup2(parameters.out, STDOUT_FILENO);
	dup2(parameters.err, STDERR_FILENO);
	if (parameters.builtin)
		exit(builtin(parameters.argv));
	exit(execve(parameters.path, parameters.argv, (char *const *)borrow_env()));
}

void
	set_execve_fds(
t_execve *parameters,
int in,
int out,
int err
)
{
	parameters->in = in;
	parameters->out = out;
	parameters->err = err;
}

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
	if (close_in_child != -1)
		close(close_in_child);
	do_execve(parameters);
}

_Noreturn void
	iterative_pipes(
t_command command
)
{
	const int	in = command.infile;
	int			pfd[2];

	while (command.commands + 1)
	{
		if (pipe(pfd))
		{
			dup2(-1, in);
			continue ;
		}
		set_execve_fds(command.commands, in, pfd[1], command.errfile);
		if (boss_baby(*command.commands++, pfd[0]) < 0)
			close(pfd[0]);
		close(pfd[1]);
		dup2(pfd[0], in);
	}
	set_execve_fds(command.commands, in, command.outfile, command.errfile);
	do_execve(*command.commands);
}

// NOTE function does not open or close any files, this is the responsibility of
// the calling function
int
	pipeline(
t_command	command
)
{
	int				status;
	pid_t			id;

	id = fork();
	if (id < 0)
		return (-1);
	if (!id)
		iterative_pipes(command);
	waitpid(id, &status, 0);
	while (errno != ECHILD)
		waitpid(0, NULL, 0);
	return (WEXITSTATUS(status));
}
