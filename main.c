#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(){
    //char* s2 = 0;
    int x = 0;
    char* str;

    str = "|%#x|\n";
    printf(str, x);
    ft_printf(str, x);
}