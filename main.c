#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(){
    size_t len;
    int x = -24323;
    char* str;

    len = 0;
    str = "|% -100.66lli|\n";
    printf(str, x);
    ft_printf("|% -100.66lli|\n", x);
}