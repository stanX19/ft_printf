#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(){
    size_t len;

    len = 0;
    print_double(" -50.2f", -23.436, &len);
    ft_printf("$\n%i\n", len);
}