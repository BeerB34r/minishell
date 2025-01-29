/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   token_rules.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/15 05:42:03 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/15 06:17:41 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int
	escapement(
const char *input,
int *pos
)
{
	const char	init = input[*pos];

	if (init != '\\' && init != '\'' && init != '\"')
		return (0);
	if (init == '\\')
	{
		(*pos)++;
		if (input[*pos])
			(*pos)++;
		return (1);
	}
	while (input[++(*pos)] != init)
		if (!input[*pos])
			return (1);
	if (input[*pos])
		(*pos)++;
	return (1);
}

int
	expansion(
const char *input,
int *pos
)
{
	const char	init = input[*pos];

	if (init != '$' && init != '`')
		return (0);
	if (init == '`')
	{
		while (input[++(*pos)] != '`')
			if (!input[*pos])
				return (1);
		if (input[*pos])
			(*pos)++;
		return (1);
	}
}	// TODO parameter expansion, arithmetic expression, dollar-parens cmd subst

int
	comment(
const char *input,
int *pos
)
{
	const char	init = input[*pos];

	if (init != '#')
		return (0);
	while (input[*pos] && input[*pos] != '\n')
		(*pos)++;
	return (1);
}

int
	delimit(
const char *input,
int *pos,
t_tokenisation *context,
t_token *current
)
{
	const char	init = input[*pos];

	if (!ft_isblank(init) && !is_operator(init) && init != '\n')
		return (0);
	current->end = &input[*pos];
	append_token(context, current);
	return (1);
}	// there should be no situation where current->end will be equal to
	// current->start, and even if there was, that wouldnt be a problem, as
	// single character words are technically valid in sh

int
	operator(
const char *input,
int *pos,
t_tokenisation *context,
t_token *current
)
{
	const char	init = input[*pos];

	if (!is_token(init))
		return (0);
	while (is_token(input[++(*pos)]))
		;
	current->end = &input[*pos];
	append_token(context, current);
	return (1);
}
