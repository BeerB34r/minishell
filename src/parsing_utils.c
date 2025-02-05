/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   parsing_utils.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/05 18:06:39 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/02/05 18:10:51 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libftprintf.h>
#include <ft_token.h>
#include <minishell.h>
#include <stdlib.h>
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
)
{
	t_cmdlist	*next;

	while (cmds)
	{
		next = cmds->next;
		free(cmds->simple);
		free(cmds);
		cmds = next;
	}
}

enum e_command_type
	cmdtype(
t_token *tokens
)
{

	while (tokens->literal)
	{
		if (*tokens->literal == ';' || *tokens->literal == '\n')
			return (simple);
		if (tokens->literal[0] == tokens->literal[1] 
			&& (*tokens->literal == '&' || *tokens->literal == '|'))
			return (complex);
		tokens++;
	}
	return (simple);
}

void
	append_cmd(
t_cmdlist **head,
t_cmdlist *cmd
)
{
	t_cmdlist	*current;

	if (!*head)
	{
		*head = cmd;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = cmd;
}

