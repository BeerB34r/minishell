/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 12:14:25 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/28 16:24:18 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

#include <unistd.h>

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

void	ft_putnbr_fd(int n, int fd)
{
	size_t	digits_count;
	int		power;

	digits_count = count_digits(n);
	if (n < 0)
		ft_putchar_fd('-', fd);
	power = ten_to_power(digits_count);
	while (power >= 1)
	{
		ft_putchar_fd(get_char_for_digit(n / power), fd);
		n %= power;
		power /= 10;
	}
}
