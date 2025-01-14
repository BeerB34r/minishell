/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   minishell.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/14 16:57:07 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/14 17:50:08 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_error.h>
#include <ft_env.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <ft_printf.h>
#define INTERACTIVE 1
#define CMDSTRING 2
#define ARGUMENTATION 3
#define DEFAULT_PROMPT "Σ:3 "

int
	check_valid(
char *input
)
{
	if (!ft_strncmp(input, "invalid", ft_strlen(input)))
		return (1);
	return (0);
}

char
	*parse(
char *input
)
{
	return (input);
}

int
	run_command(
char *input
)
{
	ft_printf("command ran: %s\n", input);
	return (0);
}
//	interactive mode currently
int
	minishell(
int argc,
char **argv
)
{
	char	*input;

	// insert signal handlers
	(void)argc;
	(void)argv;
	if (!mm_getenv("PS1"))
		mm_setenv("PS1", DEFAULT_PROMPT);
	while (1)
	{
		input = readline(mm_getenv("PS1"));
		if (!input)
			ft_uerror(__func__, "no input", 0);
		else if (check_valid(input))
			ft_uerror(__func__, "invalid input", 0);
		else if (run_command(parse(input)))
			ft_uerror(__func__, "execution error", 0);
		free(input);
	}
}
