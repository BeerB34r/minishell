/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 10:18:06 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/07 10:41:16 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	len_to_copy;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (src_len >= size)
		len_to_copy = size - 1;
	else
		len_to_copy = src_len;
	i = 0;
	while (i < len_to_copy)
	{
		dst[i] = src[i];
		i++;
	}
	dst[len_to_copy] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	while (dst_len < size && dst[dst_len] != '\0')
		dst_len++;
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && dst_len + i + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
