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
t_token *token
)
{
	free(token->original);
	free(token->expanded);
}
int
	mini_split(
const char *const input,
t_tokens *result
)
{
	t_tokens	out;
	t_token		current;

	ft_init_vector(&out.list, sizeof(t_token), (t_cleanf)free_token);
}
