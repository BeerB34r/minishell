/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_unistd.h                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:23:40 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:23:43 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNISTD_H
# define FT_UNISTD_H

# include <stddef.h>
# include <sys/types.h>

ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);

#endif
