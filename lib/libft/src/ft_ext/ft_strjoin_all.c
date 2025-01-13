/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_all.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 14:01:16 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/28 16:25:19 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

static size_t	calc_length(size_t size, const char **strs, const char *sep)
{
	size_t	result;
	size_t	str_index;

	result = ft_strlen(sep) * (size - 1);
	str_index = 0;
	while (str_index < size)
	{
		result += ft_strlen(strs[str_index]);
		str_index++;
	}
	return (result);
}

static size_t	get_size(const char **strs)
{
	size_t	res;

	res = 0;
	while (strs[res])
		res++;
	return (res);
}

char	*ft_strjoin_all(const char **strs, const char *sep)
{
	size_t	size;
	size_t	result_length;
	size_t	str_index;
	char	*result;

	size = get_size(strs);
	if (size == 0)
		return (ft_strdup(""));
	result_length = calc_length(size, strs, sep);
	result = (char *)ft_malloc((result_length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	ft_strlcat(result, strs[0], result_length + 1);
	str_index = 1;
	while (str_index < size)
	{
		ft_strlcat(result, sep, result_length + 1);
		ft_strlcat(result, strs[str_index], result_length + 1);
		str_index++;
	}
	return (result);
}
