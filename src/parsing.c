/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   parsing.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/14 21:28:50 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/15 09:45:10 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

t_token
	*new_token(void)
{
	t_token *const	token = ft_calloc(sizeof(t_token), 1);

	if (!token)
		return (NULL);
	token->type = undetermined;
	return (token);
}

void
	skip_whitespace(
const char *input,
int *pos
)
{
	while (input[*pos] && ft_isblank(input[*pos]))
		(*pos)++;
}

int
	next_token(
const char *input,
int *pos,
t_token *previous
)
{
	t_token *const	current = new_token();
	int				retval;

	skip_blank(input, pos);
	if (operator(input, pos, context, token))
		return (1);
	while (input[*pos])
	{
		if (escapement(input, pos) || expansion(input, pos)
			|| comment(input, pos))
			continue ;
		else if (delimit(input, pos, context, current))
			return (1);
		(*pos)++;
	}
	return (0);
}
