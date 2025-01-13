/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 10:17:50 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/07 16:36:30 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

static void	set_from_src(char *cdest, const char *csrc, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
}

static void	set_from_src_rev(char *cdest, const char *csrc, size_t n)
{
	size_t	i;

	i = n - 1;
	while (i != 0)
	{
		cdest[i] = csrc[i];
		i--;
	}
	cdest[i] = csrc[i];
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;

	if (dest == NULL && src == NULL)
		return (dest);
	cdest = (char *)dest;
	csrc = (char *)src;
	if (cdest == csrc)
		return (dest);
	set_from_src(cdest, csrc, n);
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	if (cdest == csrc)
		return (dest);
	if (cdest < csrc)
		set_from_src(cdest, csrc, n);
	else if (n > 0)
		set_from_src_rev(cdest, csrc, n);
	return (dest);
}
