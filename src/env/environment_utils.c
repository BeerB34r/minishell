/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   environment_utils.c                               :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/13 18:42:21 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/13 19:04:42 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void
	free_ar(
char **ar
)
{
	int	i;

	i = -1;
	while (ar && ar[++i])
		free(ar[i]);
	free(ar);
}

int
	str_ar_len(
char **str_ar
)
{
	int	i;

	i = -1;
	while (str_ar && str_ar[++i])
		;
	return (i);
}

char
	**dup_str_ar(
char **str_ar
)
{
	char	**ret;
	int		i;

	if (str_ar)
		ret = ft_calloc(str_ar_len(str_ar) + 1, sizeof(char *));
	else
		return (NULL);
	i = -1;
	while (str_ar[++i])
	{
		ret[i] = ft_strdup(str_ar[i]);
		if (!ret[i])
			return (free_ar(ret), NULL);
	}
	ret[i] = NULL;
	return (ret);
}
