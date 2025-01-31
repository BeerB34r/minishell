/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_strdup.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:29:12 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:29:14 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(src) + 1;
	dest = (char *)ft_malloc(len * sizeof(char));
	if (dest == NULL)
		return (NULL);
	return (ft_memcpy(dest, src, len));
}
