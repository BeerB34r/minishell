/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_iscntrl.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:30:26 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:30:28 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int	ft_iscntrl(int c)
{
	if (ft_isascii(c) && !ft_isprint(c))
		return (1);
	return (0);
}
