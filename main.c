#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(){
    unsigned int x = 4294967295;
    char* str;

    str = "|%100.40u|\n";
    printf(str, x);
    ft_printf(str, x);
}