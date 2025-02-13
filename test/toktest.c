/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   toktest.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/04 10:59:34 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/02/04 11:26:44 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libftprintf.h>
#include <ft_token.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void
	print_tokenisation(
const char *testcase,
t_token *tokens
)
{
	const char *enumstrings[] = {
		"undetermined", "word", "control_operator", "redirection_operator"
	};
	int			i;

	i = -1;
	printf("testcase: %s\n", testcase);
	while (tokens[++i].literal)
		printf("\ttype = %s - literal = %s\n", enumstrings[tokens[i].type], tokens[i].literal);
}
int
	main(void)
{
	FILE	*testsuite;
	char	*testcase;
	size_t	size;
	t_token	*result;
	int		i;

	size = SIZE_MAX;
	testcase = NULL;
	testsuite = fopen("p.test", "r");
	while (getline(&testcase, &size, testsuite) != -1 && testcase)
	{
		result = mm_tokenise(testcase);
		print_tokenisation(testcase, result);
		i = -1;
		while (result[++i].literal)
			free(result[i].literal);
		free(result);
		free(testcase);
		testcase = NULL;
		size = SIZE_MAX;
	}
	free(testcase);
	fclose(testsuite);
}
