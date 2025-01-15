/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_env.h                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: mde-beer <mde-beer@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/12/09 15:52:37 by mde-beer       #+#    #+#                */
/*   Updated: 2024/12/11 15:05:48 by mde-beer       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_ENV_H
# define FT_ENV_H
//	equivalent to stdlib getenv()
const char
	*mm_getenv(
		const char *name
		);	// FILE: environment_touchers.c
//	equivalent to stdlib setenv()
int		
	mm_setenv(
		const char *name,
		const char *value
		);	// FILE: environment.c
//	equivalent to stdlib clearenv()
void	
	mm_clearenv(void);	// FILE: environment.c
//	used for functions that have to touch the *entire* environment (env, execve)
const char *const
	*borrow_env(void);	// FILE: environment.c
int
	mm_execve(
		const char *pathname,
		const char **argv
		);	// FILE: environment_touchers.c
			// wrapper for execve, frees pathname and argv
void
	mm_printenv(void);	// FILE: environment_touchers.c
void
	free_ar(
		char **ar
		);	// FILE: environment_utils.c
#endif
