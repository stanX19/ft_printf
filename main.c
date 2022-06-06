#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(){
    unsigned long int x = __LONG_MAX__;
    ft_printf("%p\n", x);
    printf("%p\n", x);
}