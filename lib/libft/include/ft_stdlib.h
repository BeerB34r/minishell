/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_stdlib.h                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:23:07 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:23:08 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>
# include <inttypes.h>

typedef struct s_div
{
	int	quot;
	int	rem;
}	t_div;

typedef struct s_ldiv
{
	long	quot;
	long	rem;
}	t_ldiv;

typedef struct s_lldiv
{
	long long	quot;
	long long	rem;
}	t_lldiv;

typedef struct s_imaxdiv
{
	intmax_t	quot;
	intmax_t	rem;
}	t_imaxdiv;

double				ft_atof(const char *nptr);
int					ft_atoi(const char *nptr);
long				ft_atol(const char *nptr);
long long			ft_atoll(const char *nptr);

double				ft_strtod(const char *nptr, char **endptr);
float				ft_strtof(const char *nptr, char **endptr);
long double			ft_strtold(const char *nptr, char **endptr);

long				ft_strtol(const char *nptr, char **endptr, int base);
long long			ft_strtoll(const char *nptr, char **endptr, int base);
unsigned long		ft_strtoul(const char *nptr, char **endptr, int base);
unsigned long long	ft_strtoull(const char *nptr, char **endptr, int base);

void				*ft_malloc(size_t size);
void				ft_free(void *ptr);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_realloc(void *ptr, size_t size, size_t old_size);
void				*ft_reallocarray(void *ptr, size_t nmemb, size_t size,
						size_t old_nmemb);

int					ft_abs(int j);
long				ft_labs(long j);
long long			ft_llabs(long long j);
intmax_t			ft_imaxabs(intmax_t j);

t_div				ft_div(int numerator, int denominator);
t_ldiv				ft_ldiv(long numerator, long denominator);
t_lldiv				ft_lldiv(long long numerator, long long denominator);
t_imaxdiv			ft_imaxdiv(intmax_t numerator, intmax_t denominator);

#endif
