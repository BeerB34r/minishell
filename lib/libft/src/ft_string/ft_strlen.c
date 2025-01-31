/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_strlen.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:29:26 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:29:30 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

size_t	ft_strlen(const char *str)
{
	size_t	result;

	result = 0;
	while (str[result] != '\0')
		result++;
	return (result);
}
