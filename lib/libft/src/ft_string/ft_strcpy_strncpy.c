/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_strcpy_strncpy.c                               :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:28:54 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:28:56 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_strcpy(char *dst, const char *src)
{
	ft_stpcpy(dst, src);
	return (dst);
}

char	*ft_strncpy(char *dst, const char *src, size_t dsize)
{
	ft_stpncpy(dst, src, dsize);
	return (dst);
}
