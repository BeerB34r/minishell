/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_isxdigit.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:32:21 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:32:24 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

static int	isxletter(int c)
{
	if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

int	ft_isxdigit(int c)
{
	if (ft_isdigit(c) || isxletter(ft_toupper(c)))
		return (1);
	return (0);
}
