#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(){
    //char* s2 = 0;
    long long unsigned x = 0xFFFFFFFFFFFFFFFF;
    char* str;

    str = "|%#.64b|\n";
    //printf(str, x);
    ft_printf(str, x);
}