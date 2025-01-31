/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_allocations.c                                  :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:34:05 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:34:08 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

#include <stdlib.h>
#include <stdint.h>

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}

void	ft_free(void *ptr)
{
	free(ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	len;

	if (size == 0 || nmemb == 0)
		return (ft_malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	len = nmemb * size;
	ptr = ft_malloc(len);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}

void	*ft_realloc(void *ptr, size_t size, size_t old_size)
{
	void	*result;

	if (size <= old_size)
		return (ptr);
	result = ft_malloc(size);
	if (result == NULL)
	{
		ft_free(ptr);
		return (NULL);
	}
	ft_memcpy(result, ptr, old_size);
	ft_free(ptr);
	return (result);
}

void	*ft_reallocarray(void *ptr, size_t nmemb, size_t size,
			size_t old_nmemb)
{
	void	*result;

	if (nmemb <= old_nmemb)
		return (ptr);
	result = ft_calloc(nmemb, size);
	if (result == NULL)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(result, ptr, old_nmemb * size);
	ft_free(ptr);
	return (result);
}
