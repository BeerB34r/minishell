/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/13 22:06:05 by misiren       #+#    #+#                 */
/*   Updated: 2024/11/13 14:34:30 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <sys/types.h>

typedef struct s_pos_buffer
{
	ssize_t	last;
	ssize_t	size;
	char	buf[128];
}	t_pos_buffer;

char	*ft_get_next_line(int fd);

#endif
