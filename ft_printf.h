#ifndef HEADER_H
#define HEADER_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#define F_COUNT 25
typedef struct s_t_format {
	char* positive;
	int len;
	int precicion;
	char left;
	char hash;
	char zero;
	void (*func)(struct s_t_format, va_list, size_t*);
}format_t;
typedef void (*funcptr)(format_t, va_list, size_t*);

void		ft_putchar(char c, size_t *len);
void		ft_putstr(const char* str, size_t *len);
char*		ft_strdup(const char* s);
size_t		ft_strlen(const char* s);
char*		ft_strcpy(char * dst, const char * src);
char*		ft_strncpy(char* dst, const char* src, size_t n);
void*		ft_memmove(void* dst, const void* src, size_t len);
int			ft_isdigit(int c);

void 		print_double(format_t format, va_list argv, size_t* len);
void 		print_long_double(format_t format, va_list argv, size_t* len);
void		print_char(format_t format, va_list argv, size_t* len);
void		print_str(format_t format, va_list argv, size_t* len);
void		print_int(format_t format, va_list argv, size_t* len);
void		print_long_int(format_t format, va_list argv, size_t* len);
void		print_long_long_int(format_t format, va_list argv, size_t* len);
void		print_unsigned(format_t format, va_list argv, size_t* len);
void		print_pointer(format_t format, va_list argv, size_t* len);
void		print_hex_upper(format_t format, va_list argv, size_t* len);
void		print_hex_lower(format_t format, va_list argv, size_t* len);
void		print_binary(format_t format, va_list argv, size_t* len);
void		print_percent(format_t format, va_list argv, size_t* len);

size_t		get_int(format_t format, long long int nbr, char* buf);
size_t		get_double(format_t format, long double val, char* buf);
size_t		get_unsigned(format_t format, long long unsigned int nbr, char* buf);
size_t		get_unsigned_nbr_base(format_t format, long long unsigned int val, char* buf, const char* base);
void		format_zero(format_t* format, long long int val);

size_t		ft_printf(const char *str, ...);
format_t	read_format(const char* format_str, size_t*idx);
funcptr		match_function(const char* format_str, size_t* idx);

#endif