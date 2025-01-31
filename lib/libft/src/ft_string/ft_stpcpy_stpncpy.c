/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_stpcpy_stpncpy.c                               :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:27:44 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:27:46 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_stpcpy(char *dst, const char *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (dst);
}

char	*ft_stpncpy(char *dst, const char *src, size_t dsize)
{
	while (dsize > 0)
	{
		if (*src)
			*dst++ = *src++;
		else
			*dst++ = '\0';
		dsize--;
	}
	return (dst);
}
