/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 12:14:25 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/28 16:21:45 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

#include <unistd.h>

void	ft_putstr_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s) * sizeof(char));
}
