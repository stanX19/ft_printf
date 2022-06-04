#ifndef HEADER_H
#define HEADER_H
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c, size_t *len);
void	ft_putstr(char* str, size_t *len);
void	ft_putnbr_base(long int nbr, char* base, size_t *len);
void	ft_putnbr(long int nb, size_t *len);

#endif