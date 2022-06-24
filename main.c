#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(){
    char* x = 0;
    char* str;

    str = "|%100.4s|\n";
    printf(str, x);
    ft_printf(str, x);
}