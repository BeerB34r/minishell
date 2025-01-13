/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 17:03:25 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/07 17:13:50 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;

	len = ft_strlen(s1);
	start = 0;
	while (start < len && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = len;
	while (end > 0 && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	return (ft_substr(s1, start, end - start));
}
