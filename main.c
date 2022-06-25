#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(){
    char* s2 = 0;
    //unsigned long int x = 0;
    //char* str;

    //str = "|%s|%p|%p|\n";
    printf("| %s %s |\n", s2, s2);
    ft_printf("| %s %s |", s2, s2);
}