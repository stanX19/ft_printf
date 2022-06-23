#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(){
    size_t len;
    long double x = 9007199254740992;
    char* str;

    len = 0;
    str = "|% -100.100Lf|\n";
    printf(str, x);
    ft_printf(str, x);
}