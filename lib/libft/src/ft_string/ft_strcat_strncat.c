/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_strcat_strncat.c                               :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:27:57 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:27:59 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_strcat(char *dst, const char *src)
{
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	ft_stpcpy(dst + dst_len, src);
	return (dst);
}

char	*ft_strncat(char *dst, const char *src, size_t ssize)
{
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	i = 0;
	while (i < ssize && src[i] != '\0')
		dst[dst_len++] = src[i++];
	dst[dst_len] = '\0';
	return (dst);
}
