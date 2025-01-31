/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_memccpy_memccpyr.c                             :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:26:41 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:26:45 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void	*ptr;

	ptr = ft_memchr(src, c, n);
	if (ptr != NULL)
		return (ft_memcpy(dest, src, (size_t)((char *)ptr - (char *)src)));
	return (ft_memcpy(dest, src, n));
}

void	*ft_memccpyr(void *dest, const void *src, int c, size_t n)
{
	void	*ptr;

	ptr = ft_memchrr(src, c, n);
	if (ptr != NULL)
		return (ft_memcpy(dest, src, (size_t)((char *)ptr - (char *)src)));
	return (ft_memcpy(dest, src, n));
}
