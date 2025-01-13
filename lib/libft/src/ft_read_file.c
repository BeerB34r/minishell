#include <ft.h>

#include <sys/types.h>
#include <unistd.h>

static bool	append_next(
	t_vector *result, const char *buffer, ssize_t bytes_read)
{
	ssize_t	i;

	i = 0;
	while (i < bytes_read)
	{
		if (!ft_append_vector(result, &buffer[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_read_file(int fd, t_vector *result)
{
	char		buffer[4096];
	ssize_t		bytes_read;

	if (fd < 0 || !ft_init_vector(result, sizeof(char), NULL))
		return (false);
	bytes_read = read(fd, buffer, 4096);
	while (bytes_read > 0)
	{
		if (!append_next(result, buffer, bytes_read))
			return (false);
		bytes_read = read(fd, buffer, 4096);
	}
	if (bytes_read < 0)
	{
		ft_delete_vector(result);
		return (false);
	}
	return (true);
}
