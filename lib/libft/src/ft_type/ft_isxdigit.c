#include <ft.h>

static int	isxletter(int c)
{
	if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

int	ft_isxdigit(int c)
{
	if (ft_isdigit(c) || isxletter(ft_toupper(c)))
		return (1);
	return (0);
}
