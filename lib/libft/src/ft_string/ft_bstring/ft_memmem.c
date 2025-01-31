/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_memmem.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:27:35 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:27:37 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	*ft_memmem(const void *haystack, size_t haystacklen,
			const void *needle, size_t needlelen)
{
	size_t		i;
	size_t		j;
	const char	*chaystack;
	const char	*cneedle;

	chaystack = (const char *)haystack;
	cneedle = (const char *)needle;
	if (needlelen == 0)
		return ((void *)haystack);
	i = 0;
	while (i + needlelen <= haystacklen)
	{
		j = 0;
		while (j < needlelen && chaystack[i + j] == cneedle[j])
			j++;
		if (j == needlelen)
			return ((void *)(&chaystack[i]));
		i++;
	}
	return (NULL);
}
