/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   minishell.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/14 16:57:07 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/15 07:57:41 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <ft_error.h>
#include <ft_env.h>
#include <minishell.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <signal.h>
#include <unistd.h>

void default_sigint(int signo, siginfo_t *siginfo, void *context);
void default_sigquit(int signo, siginfo_t *siginfo, void *context);
void attach_handler(struct sigaction *handler,
		void (*function)(int, siginfo_t *, void *), int signal);
int	run(t_job job);

void
	set_env_defaults(
const char *bin
)
{
	const char	*temp;

	if (!mm_getenv("PS1"))
		mm_setenv("PS1", DEFAULT_PROMPT);
	if (!mm_getenv("PS2"))
		mm_setenv("PS2", DEFAULT_CONTINUATION);
	if (!mm_getenv("SHELL"))
		mm_setenv("SHELL", bin);
	if (!mm_getenv("PWD"))
	{
		temp = getcwd(NULL, 0);
		mm_setenv("PWD", temp);
		free((void *)temp);
	}
}

void
	set_sig_defaults(
struct sigaction handlers[HANDLER_COUNT]
)
{
	attach_handler(&handlers[0], &default_sigint, SIGINT);
	attach_handler(&handlers[1], &default_sigquit, SIGQUIT);
}

//	interactive mode currently
//	determine proper amount of sighandlers
int
	minishell(
int argc,
char **argv
)
{
	struct sigaction	handlers[HANDLER_COUNT];
	char				*input;
	char				*message;

	set_env_defaults(argv[0]);
	set_sig_defaults(handlers);
	message = NULL;
	(void)argc;
	while (1)
	{
		input = readline(mm_getenv("PS1"));
		if (!input)
			return (ft_printf("exit\n"), 0);
		else if (run((t_job){.argv = ft_split(input, ' '), {0}}))
			ft_uerror(__func__, "job failed", 0);
		free(input);
	}
	(void)input;
	return (0);
}
