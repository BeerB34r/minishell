/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   builtins.c                                        :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/15 06:18:15 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/15 06:50:47 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <ft_env.h>
#include <stdlib.h>
#include <unistd.h>

int
	str_ar_len(
char **str_ar
);

int
	builtin_echo(
char **argv
)
{
	const int	argc = str_ar_len(argv);
	int			i;

	i = 1;
	if (argc > 1 && !ft_strncmp("-n", argv[1], 3))
		i++;
	while (i < argc)
		ft_printf("%s", argv[i++]);
	if (argc < 2 || ft_strncmp("-n", argv[1], 3))
		ft_printf("\n");
	return (0);
}

int
	builtin_pwd(
char **argv
)
{
	const char *const	cwd = getcwd(NULL, 0);

	(void)argv;
	if (!cwd)
		return (1);
	ft_printf("%s\n", cwd);
	free((void *)cwd);
	return (0);
}

int
	builtin_export(
char **argv
)
{
	const int	argc = str_ar_len(argv);
	int			i;
	char		*name;
	char		*value;

	if (argc == 1)
		return (mm_printenv(), 0);
	i = 0;
	while (++i < argc)
	{
		value = ft_strchr(argv[i], '=');
		if (!value)
		{
			name = argv[i];
			value = "";
			mm_setenv(name, value);
		}
		else
		{
			name = ft_substr(argv[i], 0, ft_strchr(argv[i], '=') - argv[i]);
			value++;
			mm_setenv(name, value);
			free(name);
		}
	}
	return (0);
}

int
	builtin_unset(
char **argv
)
{
	const int	argc = str_ar_len(argv);
	int			i;

	i = 0;
	while (++i < argc)
		mm_setenv(argv[i], NULL);
	return (0);
}

int
	builtin_env(
char **argv
)
{
	(void)argv;
	mm_printenv();
	return (0);
}
