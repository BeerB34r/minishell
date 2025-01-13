/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/13 20:53:59 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/13 20:54:48 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int
	main(
int argc,
char **argv
)
{
	char	str[500];
	int		i;

	ft_printf("makefile linker test\n");
	ft_dprintf(2, "argv =");
	i = 0;
	while (++i < argc)
		ft_dprintf(2, "%i-%s ", i, argv[i]);
	ft_dprintf(2, "\n");
	if (ft_sprintf(str, "i == %i", argc))
		ft_printf("%s\n", str);
	else
		ft_printf("sprintf failed\n");
	return (0);
}
