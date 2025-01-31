/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_libgen.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:24:03 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:24:06 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_basename(char *s)
{
	size_t	start;
	size_t	end;

	if (s == NULL || ft_strlen(s) == 0)
		return (ft_strdup("."));
	if (ft_strcmp(s, "/") == 0)
		return (ft_strdup("/"));
	end = ft_strlen(s);
	while (end > 0 && s[end - 1] == '/')
		end--;
	if (end == 0)
		return (ft_strdup("/"));
	start = end - 1;
	while (start > 0 && s[start - 1] != '/')
		start--;
	return (ft_substr(s, start, end - start));
}
