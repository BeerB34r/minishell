#include <ft.h>

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(src) + 1;
	dest = (char *)ft_malloc(len * sizeof(char));
	if (dest == NULL)
		return (NULL);
	return (ft_memcpy(dest, src, len));
}
