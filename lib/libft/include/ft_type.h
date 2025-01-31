/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_type.h                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:23:32 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:23:34 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_H
# define FT_TYPE_H

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_iscntrl(int c);
int		ft_isdigit(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_isxdigit(int c);

int		ft_isascii(int c);
int		ft_isblank(int c);

int		ft_toupper(int c);
int		ft_tolower(int c);

#endif
