/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_memfrob.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:27:06 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:27:11 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

#define MEMFROB_VALUE 42

void	*ft_memfrob(void *s, size_t n)
{
	size_t	i;
	char	*cs;

	cs = (char *)s;
	i = 0;
	while (i < n)
	{
		cs[i] ^= MEMFROB_VALUE;
		i++;
	}
	return (s);
}
