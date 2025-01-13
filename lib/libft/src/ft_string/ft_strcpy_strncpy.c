#include <ft.h>

char	*ft_strcpy(char *dst, const char *src)
{
	ft_stpcpy(dst, src);
	return (dst);
}

char	*ft_strncpy(char *dst, const char *src, size_t dsize)
{
	ft_stpncpy(dst, src, dsize);
	return (dst);
}
