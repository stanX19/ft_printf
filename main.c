#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(){
    //char* s2 = 0;
    long double x = 12.345;
    char* str;

    str = "|%+020.1Lf|\n";
    printf(str, x);
    ft_printf(str, x);
}