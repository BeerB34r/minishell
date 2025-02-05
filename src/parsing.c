/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   parsing.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/04 18:11:47 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/02/04 19:08:40 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libftprintf.h>
#include <ft_token.h>
#include <minishell.h>
/*		tokens quickref
		redirection
		">", "<", ">|", "<<", ">>", "<&", ">&", "<<-", "<>"
		control
		"&", "&&", "(", ")", ";", ";;", ";&", "\n", "|", "||"
*/
enum e_command_type
{
	simple,
	complex
};
enum e_conditional
{
	and,
	or,
};
typedef struct s_complex_command	t_compcmd;
typedef struct s_cmdlist			t_cmdlist;
struct s_complex_command
{
	enum e_conditional	type;
	t_compcmd			*left;
	t_command			*right;
};
struct s_cmdlist
{
	struct s_cmdlist	*next;
	enum e_command_type	type;
	union
	{
		t_command		*simple;
		t_compcmd		*complex;
	};
};
void
	free_cmdlist(
t_cmdlist *cmds
);
enum e_command_type
	cmdtype(
t_token *tokens
);
void
	append_cmd(
t_cmdlist **head,
t_cmdlist *cmd
);

t_command
	*populate_simple(
t_token **tokens
)
{
	t_command	*out;

	out = NULL;
	while ((*tokens)->literal)
	{

	}
	return (out);
};

t_compcmd
	*populate_complex(
t_token **tokens
)
{
	t_compcmd	*out;

	out = NULL;
	while ((*tokens)->literal)
	{
	}
	return (out);
};

t_cmdlist
	*mm_parse(
t_token	*tokens
)
{
	t_cmdlist	*out;
	t_cmdlist	*current;

	out = NULL;
	while (tokens->literal)
	{
		current = ft_calloc(1, sizeof(t_cmdlist));
		if (!current)
			return (free_cmdlist(out), NULL);
		current->type = cmdtype(tokens);
		if (current->type == simple)
			current->simple = populate_simple(&tokens);
		else
			current->complex = populate_complex(&tokens);
		if (!current->simple)
			return (free_cmdlist(out), NULL);
		append_cmd(&out, current);
	}
	return (out);
};
