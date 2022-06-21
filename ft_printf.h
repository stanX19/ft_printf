#ifndef HEADER_H
#define HEADER_H
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c, size_t *len);
void	ft_putstr(char* str, size_t *len);
void	ft_putnbr_base(long long int nbr, char* base, size_t *len);
void	ft_putnbr(long int nb, size_t *len);
void	print_double(char* format, long double val, size_t *len);
size_t	ft_printf(const char *str, ...);

typedef union {
	void (*call)(va_list, size_t*, char*, int);
	void (*single)(va_list, size_t*);
} funcptr;
struct s_format {
	char* key;
	funcptr func;
	struct s_format* next;
};
#endif