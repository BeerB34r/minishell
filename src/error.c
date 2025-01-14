/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   error.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/13 17:31:27 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/13 18:00:24 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <ft_printf.h>
#include <string.h>

//	use as follows: ft_perror(__FILE__, __LINE__, [INSERT MESSAGE HERE])
int
	ft_perror(
const char *file,
const int line,
const char *msg
)
{
	const int	errnr = errno;

	ft_dprintf(2, "%s:%d %s\n%s\n", file, line, strerror(errnr), msg);
	return (errnr);
}

//	use or user error, your pick ;P
//	use as follows: ft_uerror(__func__, [insert message here], [return value])
int
	ft_uerror(
const char *func,
const char *msg,
const int retval
)
{
	ft_dprintf(2, "%s(): %s\n", func, msg);
	return (retval);
}
