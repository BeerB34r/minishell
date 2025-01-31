/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_strchrnul_strrchrnul.c                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:28:29 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:28:32 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_strchrnul(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

char	*ft_strrchrnul(const char *s, int c)
{
	char	*result;

	result = NULL;
	while (*s)
	{
		if (*s == (char)c)
			result = (char *)s;
		s++;
	}
	if (result)
		return (result);
	return ((char *)s);
}
