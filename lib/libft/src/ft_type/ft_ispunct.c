/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_ispunct.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:31:55 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:31:59 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int	ft_ispunct(int c)
{
	if (ft_isgraph(c) && !ft_isalnum(c))
		return (1);
	return (0);
}
