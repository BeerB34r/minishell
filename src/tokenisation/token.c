/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   parse-playground.c                                :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/03 12:27:20 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/02/03 19:01:04 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libftprintf.h>
#include <minishell.h>
#include <ft_token.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ctype.h>

void
	end_token(
const char **token,
enum e_token_type *type
)
{
	const char	*in;
	char		escape;

	in = *token;
	*type = word;
	while (*in)
	{
		escape = *in;
		if (isblank(escape) || isoperator(escape))
			break ;
		if (escape == '\\')
		{
			if (*++in)
				in++;
			continue ;
		}
		while ((escape == '\"' || escape == '\'') && *in && *++in != escape)
			;
		in++;
	}
	if (isredir(*in) && nonly_ctype(*token, in - *token, ft_isdigit))
		end_operator(&in, type);
	*token = in;
}

static void
	free_tokens(
t_token *tokens
)
{
	int	i;

	i = -1;
	while (tokens[++i].literal)
		free(tokens[i].literal);
	free(tokens);
}

t_token
	*mm_tokenise(
const char *input
)
{
	const char	*start;
	t_token		*output;
	t_token		current;
	int			count;

	count = 1;
	output = ft_calloc(count, sizeof(t_token));
	while (*input)
	{
		while (isblank(*input))
			input++;
		if (!*input)
			break ;
		start = input;
		if (isoperator(*start))
			end_operator(&input, &current.type);
		else
			end_token(&input, &current.type);
		current.literal = ft_substr(start, 0, input - start);
		if (ft_recalloc((void **)&output, count, count + 1, sizeof(t_token)))
			return (free_tokens(output), NULL);
		output[count++ - 1] = current;
	}
	return (output);
}
