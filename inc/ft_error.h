/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_error.h                                        :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/13 20:42:27 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/13 20:45:08 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

int
	ft_perror(
		const char *file,
		const int line,
		const char *msg
		);	// FILE: error.c
int
	ft_uerror(
		const char *func,
		const char *msg,
		const int retval
		);	// FILE: error.c
#endif
