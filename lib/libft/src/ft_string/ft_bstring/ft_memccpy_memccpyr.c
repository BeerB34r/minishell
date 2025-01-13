#include <ft.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void	*ptr;

	ptr = ft_memchr(src, c, n);
	if (ptr != NULL)
		return (ft_memcpy(dest, src, (size_t)((char *)ptr - (char *)src)));
	return (ft_memcpy(dest, src, n));
}

void	*ft_memccpyr(void *dest, const void *src, int c, size_t n)
{
	void	*ptr;

	ptr = ft_memchrr(src, c, n);
	if (ptr != NULL)
		return (ft_memcpy(dest, src, (size_t)((char *)ptr - (char *)src)));
	return (ft_memcpy(dest, src, n));
}
