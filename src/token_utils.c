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
#include <ft_token.h>

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
const char *opstart,
enum e_token_type *type
)
{
	const char *const	operators[] = {
		">", "<", ">|", "<<", ">>", "<&", ">&", "<<-", "<>",
		"&", "&&", "(", ")", ";", ";;", ";&", "\n", "|", "||", NULL };
	int					longest;
	int					current;
	int					i;

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
	if (*opstart == '<' || '>' == *opstart)
		*type = redirection_operator;
	else
		*type = control_operator;
	return (opstart + longest);
}

//	The only reason this function exists is cuz i can't be bothered to refactor
//	it out lmao -Mats
void
	end_operator(
const char **token,
enum e_token_type *type
)
{
	*token = operator_length(*token, type);
}
