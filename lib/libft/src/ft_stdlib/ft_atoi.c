#include <ft.h>

static int	get_sign(const char **nptr)
{
	int	sign;

	while (ft_isspace(**nptr))
		(*nptr)++;
	sign = 1;
	if (**nptr == '-')
	{
		sign = -1;
		(*nptr)++;
	}
	else if (**nptr == '+')
		(*nptr)++;
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = get_sign(&nptr);
	result = 0;
	while (*nptr != '\0' && ft_isdigit(*nptr))
	{
		result = result * 10 + sign * (int)(*nptr - '0');
		nptr++;
	}
	return (result);
}
