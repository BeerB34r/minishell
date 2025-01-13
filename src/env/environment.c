/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   environment.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/12/06 18:37:59 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/16 16:24:07 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_printf.h>
#include <ft_error.h>

extern char	**environ;	// There is a specific edge case in norminette for this
char	**dup_str_ar(char **str_ar);	// FILE: environment_utils.c
int		str_ar_len(char **str_ar);		// FILE: environment_utils.c

//	Holds the entirety of our environment, as youre not allowed to touch it
//	otherwise. thus, it is duped and kept in a nice enclosure where only *some*
//	functions are allowed to touch it. and even then under strict supervision
static char
	***env_holder(void)
{
	static char	**envp = NULL;
	static int	initialised = 0;

	if (!initialised)
	{
		envp = dup_str_ar(environ);
		if (!envp)
			ft_perror(__FILE__, __LINE__, "Environ initialisation failed");
		else
			initialised = 1;
	}
	return (&envp);
}

//	used exclusively by functions that require the entire env at once e.g.:
//	(printenv, execve)
const char *const
	*borrow_env(void)
{
	return ((const char *const *const)*env_holder());
}

//	helper for mm_setenv(), deletes a variable from the environment.
//	the OR in the while statement is specifically for if two variables are
//	substrings of eachother, IE: "var" "var1".
static int	
	mm_delenv(
const char *name
)
{
	char ***const	env = env_holder();
	char **const	new_env = ft_calloc(str_ar_len(*env), sizeof(char *));
	int				i;
	int				j;

	if (!new_env)
		return (ft_perror(__FILE__, __LINE__, "environ allocation"));
	i = -1;
	j = 0;
	while (*env && (*env)[++i])
	{
		if (ft_strncmp((*env)[i], name, ft_strlen(name))
			|| (*env)[i][ft_strlen(name)] != '=')
			new_env[j++] = (*env)[i];
		else
			free((*env)[i]);
	}
	free(*env);
	*env = new_env;
	return (0);
}

//	equivalent to the stdlib function setenv()
//	to delete an env variable, call with value = NULL
//	NOTE: to declare a variable without giving it a value, call as follows:
//		`mm_setenv(VARNAME, "")`
//	the OR in the while statement is specifically for if two variables are
//	substrings of eachother, IE: "var" "var1".
int	
	mm_setenv(
const char *name,
const char *value
)
{
	char ***const	env = env_holder();
	char			*var;
	char			**new_env;
	int				i;

	if (!name)
		return (ft_uerror(__func__, "Nameless variable cannot be set", 1));
	if (!value)
		return (mm_delenv(name));
	var = ft_calloc(ft_strlen(name) + ft_strlen(value) + 2, sizeof(char));
	if (!var)
		return (ft_perror(__FILE__, __LINE__, "environ variable allocation"));
	ft_sprintf(var, "%s%c%s", name, '=', value);
	i = -1;
	while (*env && (*env)[++i])
		if (!ft_strncmp((*env)[i], name, ft_strlen(name))
			&& (*env)[i][ft_strlen(name)] == '=')
			return (free((*env)[i]), ((*env)[i] = var), 0);
	new_env = (char **)ft_calloc(str_ar_len(*env) + 2, sizeof(char *));
	if (!new_env)
		return (free(var), ft_perror(__FILE__, __LINE__, "environ allocation"));
	new_env[i] = var;
	while (i-- > 0)
		new_env[i] = (*env)[i];
	return (free(*env), (*env = new_env), 0);
}

//	equivalent to the stdib function clearenv()
void
	mm_clearenv(void)
{
	char ***const	env = env_holder();
	const char		**arr = (const char **)*env;

	while (arr && *arr)
		free((void *)*arr++);
	free(*env);
	*env = NULL;
}
