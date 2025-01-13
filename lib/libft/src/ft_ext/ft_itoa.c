/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 12:14:25 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/07 18:27:51 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

static size_t	count_digits(int nb)
{
	size_t	result;

	result = 0;
	while (nb != 0)
	{
		result++;
		nb /= 10;
	}
	if (result > 0)
		return (result);
	return (1);
}

static int	ten_to_power(size_t digits_count)
{
	int	result;

	result = 1;
	while (digits_count > 1)
	{
		result *= 10;
		digits_count--;
	}
	return (result);
}

static char	get_char_for_digit(int digit)
{
	if (digit < 0)
		digit = -digit;
	return (digit + '0');
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	digits_count;
	size_t	i;
	int		power;

	digits_count = count_digits(n);
	result = (char *)ft_malloc((digits_count + (n < 0) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
		result[i++] = '-';
	power = ten_to_power(digits_count);
	while (power >= 1)
	{
		result[i++] = get_char_for_digit(n / power);
		n %= power;
		power /= 10;
	}
	result[i] = '\0';
	return (result);
}
