/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   token_utils.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/03 18:46:04 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/02/03 18:48:21 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

int
	isoperator(
char c
)
{
	if (c == '>' || c == '<')
		return (1);
	if (c == ';')
		return (1);
	if (c == '(' || c == ')')
		return (1);
	if (c == '|' || c == '&')
		return (1);
	return (0);
}

int
	isredir(
char c
)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

int
	nonly_ctype(
const char *string,
int n,
int (func)(int)
)
{
	while (*string && n--)
		if (!func(*string++))
			return (0);
	return (1);
}

const char
	*operator_length(
const char *opstart
)
{
	const char	*operators[] = {
		">", "<", ">|", "<<", ">>", "<&", ">&", "<<-", "<>",
		"&", "&&", "(", ")", ";", ";;", ";&", "\n", "|", "||", NULL };
	int			longest;
	int			current;
	int			i;

	longest = 0;
	i = -1;
	while (operators[++i])
	{
		if (ft_strncmp(opstart, operators[i], ft_strlen(operators[i])))
			continue ;
		current = ft_strlen(operators[i]);
		if (current > longest)
			longest = current;
	}
	return (opstart + longest);
}

void
	end_operator(
const char **token
)
{
	const char	*in;

	in = operator_length(*token);
	*token = in;
}
