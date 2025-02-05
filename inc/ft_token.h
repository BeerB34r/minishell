/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_token.h                                        :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/03 18:49:17 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/02/03 19:03:15 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H
//	datatypes
//	//	typedefs
typedef struct s_token	t_token;
//	//	enums
enum e_token_type
{
	undetermined,
	word,
	control_operator,
	redirection_operator,
};
//	//	structs
struct s_token
{
	char				*literal;
	enum e_token_type	type;
};
//	Porcelain
t_token	
	*mm_tokenise(
		const char *input
		);	// FILE: token.c
//	Plumbing
void	
	end_token(
		const char **token,
		enum e_token_type *type
		);	// FILE: token.c
void	
	end_operator(
		const char **token,
		enum e_token_type *type
		);	// FILE: token_utils.c
const char
	*operator_length(
		const char *opstart,
		enum e_token_type *type
		);	// FILE: token_utils.c
//	Helpers
int		
	isoperator(
		char c
		);	// FILE: token_utils.c
int		
	isredir(
		char c
		);	// FILE: token_utils.c
int		
	nonly_ctype(
		const char *string,
		int n,
		int (func)(int)
		);	// FILE: token_utils.c
			// n only_ctype, check the n next chars for wether they are ctype()
#endif
