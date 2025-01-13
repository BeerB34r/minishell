#include <ft.h>

size_t	ft_strlen(const char *str)
{
	size_t	result;

	result = 0;
	while (str[result] != '\0')
		result++;
	return (result);
}
