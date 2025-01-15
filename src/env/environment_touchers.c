/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   environment_touchers.c                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/12/11 15:03:06 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/11 15:04:51 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <ft_env.h>
#include <libft.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
//	prints all environment variables, equivalent to shell builtin env without
//	any arguments
void
	mm_printenv(void)
{
	const char *const *const	env = borrow_env();
	int							i;

	i = -1;
	while (env && env[++i])
		printf("%s\n", env[i]);
}

int
	mm_execve(
const char *pathname,
const char **argv
)
{
	const char *const *const	env = borrow_env();
	const pid_t					pid = fork();
	int							status;

	if (pid < 0)
		return (1);
	if (pid == 0)
		exit(execve(pathname, (char *const *)argv, (char *const *)env));
	waitpid(pid, &status, 0);
	free_ar((char **)argv);
	free((void *)pathname);
	return (status);
}

const char
	*mm_getenv(
const char *name
)
{
	const char *const *const	env = borrow_env();
	int							i;

	i = -1;
	while (env && env[++i])
		if (!ft_strncmp(name, env[i], ft_strlen(name))
			&& env[i][ft_strlen(name)] == '=')
			return (&env[i][ft_strlen(name) + 1]);
	return (NULL);
}
