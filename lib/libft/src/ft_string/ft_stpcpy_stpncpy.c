#include <ft.h>

char	*ft_stpcpy(char *dst, const char *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (dst);
}

char	*ft_stpncpy(char *dst, const char *src, size_t dsize)
{
	while (dsize > 0)
	{
		if (*src)
			*dst++ = *src++;
		else
			*dst++ = '\0';
		dsize--;
	}
	return (dst);
}
