/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:24:26 by shatan            #+#    #+#             */
/*   Updated: 2024/03/07 14:24:26 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H
# include "../libft/libft.h"
# include "ft_printf.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define F_COUNT 25

typedef struct s_format
{
	char	*positive;
	int		len;
	int		precicion;
	char	minus;
	char	hash;
	char	zero;
	char	star;
	void	(*func)(struct s_format, va_list *, size_t *);
}	t_format;

typedef void	(*t_fmt_func)(t_format, va_list *, size_t *);

typedef struct s_base
{
	size_t		nbr;
	const char	*str;
}	t_base;

typedef struct s_fdict
{
	char		*key;
	t_fmt_func	func;
}	t_fdict;

void		ft_printf_putchar(char c, size_t *len);
void		ft_printf_putnchar(char c, int n, size_t *len);
void		ft_printf_putstr(const char *str, size_t *len);
void		ft_printf_putnstr(const char *str, int n, size_t *len);
void		print_double(t_format format, va_list *argv, size_t *len);
void		print_long_double(t_format format, va_list *argv, size_t *len);
void		print_char(t_format format, va_list *argv, size_t *len);
void		print_str(t_format format, va_list *argv, size_t *len);
void		print_int(t_format format, va_list *argv, size_t *len);
void		print_long_int(t_format format, va_list *argv, size_t *len);
void		print_long_long_int(t_format format, va_list *argv, size_t *len);
void		print_unsigned(t_format format, va_list *argv, size_t *len);
void		print_long_unsigned(t_format format, va_list *argv, size_t *len);
void		print_long_long_unsigned(t_format format,
				va_list *argv, size_t *len);
void		print_pointer(t_format format, va_list *argv, size_t *len);
void		print_hex_upper(t_format format, va_list *argv, size_t *len);
void		print_hex_lower(t_format format, va_list *argv, size_t *len);
void		print_binary(t_format format, va_list *argv, size_t *len);
void		print_percent(t_format format, va_list *argv, size_t *len);

size_t		get_int(t_format *format, long long int nbr, char *buf);
size_t		get_double(t_format format, long double val, char *buf);
size_t		get_unsigned_nbr_base(long long unsigned int val,
				char *buf, const char *base);
void		format_zero(t_format *format, long long int val);
void		print_buf_with_middle_zeros(const char *prefix, int pad_len,
				const char *suffix, size_t *len);
void		print_buf_with_int_fmt(t_format fmt, const char *prefix,
				const char *buf, size_t *len);
void		print_buf_with_str_fmt(t_format fmt, const char *buf, size_t *len);
void		print_buf_with_pad_char(t_format fmt, const char *buf,
				char pad_char, size_t *len);
void		print_buf_with_pad(t_format fmt, const char *buf, size_t *len);

size_t		ft_printf(const char *str, ...);
t_format	read_format(const char *format_str, va_list *argv, size_t *idx);
t_fmt_func	match_function(const char *format_str, size_t *idx);

#endif