/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 10:17:45 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/07 16:36:15 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cvalue;
	unsigned char	*cptr;
	size_t			i;

	cptr = (unsigned char *)s;
	cvalue = c;
	i = 0;
	while (i < n)
	{
		if (cptr[i] == cvalue)
			return ((void *)(cptr + i));
		i++;
	}
	return (NULL);
}

void	*ft_memchrr(const void *s, int c, size_t n)
{
	unsigned char	cvalue;
	unsigned char	*cptr;
	void			*result;
	size_t			i;

	cptr = (unsigned char *)s;
	cvalue = c;
	result = NULL;
	i = 0;
	while (i < n)
	{
		if (cptr[i] == cvalue)
			result = (void *)(&cptr[i]);
		i++;
	}
	return (result);
}
