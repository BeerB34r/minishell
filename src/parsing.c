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

#include <include/ft_vector.h>
#include <minishell.h>
#include <libft.h>
#include <stdlib.h>

typedef struct s_token_list	t_tokens;
typedef struct s_token		t_token;
struct s_token
{
	char	*original;
	char	*expanded;
};
struct s_token_list
{
	t_vector	list;
};

void
	free_token(
void *token
)
{
	const t_token	*actual_token = token;

	free(actual_token->original);
	free(actual_token->expanded);
}

t_token
	get_next_token(
const char **input
)
{
	t_token	out;

	out = (t_token){0};
	while (*input)
	{

	}
	return (out);
}

int
	mini_split(
const char *input,
t_tokens *result
)
{
	t_tokens	out;
	t_token		current;

	ft_init_vector(&out.list, sizeof(t_token), free_token);
	while (*input)
	{
		current = get_next_token(&input);
		if (!current.original)
			break ;
		if (ft_append_vector(&out.list, *(void**)&current))
			return (ft_delete_vector(&out.list), 1);
	}
	*result = out;
	return (0);
}
