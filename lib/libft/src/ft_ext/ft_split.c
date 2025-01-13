/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 17:17:46 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/07 17:41:27 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

static size_t	count_words(char const *s, char c, size_t len)
{
	size_t	result;
	size_t	i;

	result = 0;
	i = 0;
	while (i < len)
	{
		while (i < len && s[i] == c)
			i++;
		if (i < len)
		{
			result++;
			while (i < len && s[i] != c)
				i++;
		}
	}
	return (result);
}

static char	*get_next_substr(char const *s, char c, size_t *i, size_t len)
{
	size_t	start;

	start = *i;
	while (*i < len && s[*i] != c)
		(*i)++;
	return (ft_substr(s, start, (*i) - start));
}

static char	**populate_words(char const *s, char c, size_t len, char **result)
{
	size_t	word_count;
	size_t	i;

	i = 0;
	word_count = 0;
	while (i < len)
	{
		while (i < len && s[i] == c)
			i++;
		if (i < len)
		{
			result[word_count] = get_next_substr(s, c, &i, len);
			if (result[word_count] == NULL)
			{
				ft_free_strs(result);
				return (NULL);
			}
			word_count++;
		}
	}
	result[word_count] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	len;
	char	**result;

	len = ft_strlen(s);
	word_count = count_words(s, c, len);
	result = (char **)ft_malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	return (populate_words(s, c, len, result));
}

void	ft_free_strs(char **strs)
{
	size_t	i;

	if (strs == NULL)
		return ;
	i = 0;
	while (strs[i] != NULL)
	{
		ft_free(strs[i]);
		i++;
	}
	ft_free(strs);
}
