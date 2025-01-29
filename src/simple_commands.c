/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   simple_commands.c                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/29 17:56:36 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/29 18:37:55 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libftprintf.h>
#include <ft_env.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int
	pipeline(
t_simple_cmd *command
)
{
	const int	in = command->infile;
	int			pfd[2];
	int			i;
	pid_t		id;

	id = fork();
	if (id < 0)
		return (1);
	if (id)
	{
		waitpid(id, &i, 0);
		while (errno != ECHILD)
			waitpid(0, NULL, 0);
		close(in);
		close(command->outfile);
		return (WEXITSTATUS(i));
	}
	i = -1;
	while (command->arguments[++i])
	{
		if (command->arguments[i + 1])
		{
			if (pipe(pfd))
			{
				dup2(-1, in);
				continue ; // pipelines should continue even if previous
						   // commands fail
			}
			id = fork();
			if (id < 0)
			{
				close(pfd[0]);
				close(pfd[1]);
				dup2(-1, in);
				continue ; // pipelines should continue even if previous
						   // commands fail
			}
			if (id)
			{
				close(pfd[1]);
				dup2(pfd[0], in);
				continue ;
			}
			close(pfd[0]);
			dup2(pfd[1], STDOUT_FILENO);
			dup2(in, STDIN_FILENO); // TODO add differentiation between builtin
									// and external commands
			exit(execve(command->path[i], command->arguments[i], borrow_env()));
		}
		else
		{
			dup2(in, STDIN_FILENO);
			dup2(command->outfile, STDOUT_FILENO); // TODO add differentiation
												   // between builtin and
												   // external commands
			exit(execve(command->path[i], command->arguments[i], borrow_env()));
		}
	}
}
