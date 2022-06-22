#ifndef HEADER_H
#define HEADER_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef union {
	void (*call)(va_list, size_t*, char*, int);
	void (*single)(va_list, size_t*);
	size_t(*get_double)(int, va_list, char*);
} funcptr;

typedef struct s_func_format {
	char* key;
	funcptr func;
	struct s_format* next;
} func_format;

typedef struct s_t_format {
	char* positive;
	int len;
	int precicion;
	short int left;
}format_t;

void		ft_putchar(char c, size_t *len);
void		ft_putstr(char* str, size_t *len);
void		ft_putnbr_base(long long int nbr, char* base, size_t *len);
void		ft_putnbr(long int nb, size_t *len);
size_t		get_double(format_t format, long double val, char*buf);
void		print_double(char* format_str, long double val, size_t* len);
char*		ft_strdup(const char* s);
size_t		ft_strlen(const char* s);
size_t		ft_printf(const char *str, ...);
format_t	read_format(char* format_str);
int			format_match(char* src, char* target);

#endif