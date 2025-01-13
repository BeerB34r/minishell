/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 12:14:25 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/28 16:24:57 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

#include <unistd.h>

void	ft_putendl_fd(const char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
