#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(){
    size_t len;
    long double x = -24323.436;
    len = 0;
    printf("% -7.18Lf$\n", x);
    ft_printf("$\n|%2c|\n", 'F');
}