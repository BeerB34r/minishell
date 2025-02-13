/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_recalloc.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/03 18:58:12 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/02/04 11:31:00 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	
	ft_recalloc(
void **ptr,
size_t old_nmemb,
size_t new_nmemb,
size_t size
)
{
	void *const	new = ft_calloc(new_nmemb, size);
	size_t		copy_len;

	if (!new)
		return (1);
	if (old_nmemb > new_nmemb)
		copy_len = new_nmemb * size;
	else
		copy_len = old_nmemb * size;
	if (old_nmemb && *ptr)
		ft_memcpy(new, *ptr, copy_len);
	if (*ptr)
		free(*ptr);
	*ptr = new;
	return (0);
}
