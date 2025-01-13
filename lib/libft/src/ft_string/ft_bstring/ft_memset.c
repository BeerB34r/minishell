/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 10:17:57 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/07 16:36:41 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	cvalue;
	unsigned char	*cptr;
	size_t			i;

	cptr = (unsigned char *)ptr;
	cvalue = value;
	i = 0;
	while (i < num)
	{
		cptr[i] = cvalue;
		i++;
	}
	return (ptr);
}
