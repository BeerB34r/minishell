/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_write.c                                        :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:32:32 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:32:55 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

#include <unistd.h>

ssize_t	ft_write(int fildes, const void *buf, size_t nbyte)
{
	return (write(fildes, buf, nbyte));
}
