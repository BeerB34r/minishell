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
//	Porcelain
char
	**mm_strtokenise(
		const char *input
		);	// FILE: token.c
//	Plumbing
void
	end_token(
		const char **token
		);	// FILE: token.c
void
	end_operator(
		const char **token
		);	// FILE: token_utils.c
const char
	*operator_length(
		const char *opstart
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
