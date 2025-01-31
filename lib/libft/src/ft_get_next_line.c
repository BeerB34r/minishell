/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/13 22:06:02 by misiren       #+#    #+#                 */
/*   Updated: 2024/11/13 14:34:30 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef FILDES_NUM
# define FILDES_NUM 1024
#endif

static t_vector	*extend(
	t_vector *line, const char *buf, ssize_t start, ssize_t end)
{
	ssize_t	i;

	i = start;
	while (i < end)
	{
		if (!ft_append_vector(line, (void *)&buf[i]))
		{
			ft_delete_vector(line);
			return (NULL);
		}
		i++;
	}
	return (line);
}

static bool
	get_with_buffer(t_pos_buffer *pb, int fd, t_vector *line, const char n)
{
	ssize_t		start;
	ssize_t		end;

	start = pb->last;
	if (start == 0)
		pb->size = read(fd, pb->buf, 128);
	if (pb->size <= 0)
	{
		if (line->size > 0 && pb->size == 0)
			return (ft_append_vector(line, (void *)&n));
		ft_delete_vector(line);
		return (false);
	}
	end = start;
	while (end < pb->size && pb->buf[end] != '\n')
		end++;
	if (end < pb->size)
	{
		pb->last = (end + 1) % pb->size;
		return (ft_append_vector(extend(line, pb->buf, start, end + 1), &n));
	}
	pb->last = 0;
	if (extend(line, pb->buf, start, pb->size) == NULL)
		return (NULL);
	return (get_with_buffer(pb, fd, line, n));
}

char	*ft_get_next_line(int fd)
{
	static t_pos_buffer	bufs[FILDES_NUM] = {0};
	t_vector			line;

	if (fd < 0 || fd >= FILDES_NUM)
		return (NULL);
	if (ft_init_vector(&line, sizeof(char), NULL))
		return (NULL);
	if (!get_with_buffer(&bufs[fd], fd, &line, '\0'))
		return (NULL);
	return ((char *)line.contents);
}
