/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_strchr_strrchr.c                               :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:28:07 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:28:09 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_strchr(const char *s, int c)
{
	char	*result;

	result = ft_strchrnul(s, c);
	if (*result == '\0' && (char)c != '\0')
		return (NULL);
	return (result);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = ft_strrchrnul(s, c);
	if (*result == '\0' && (char)c != '\0')
		return (NULL);
	return (result);
}
