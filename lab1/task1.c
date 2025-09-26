#include <stdio.h>

int main() {
    unsigned long long a = 0xC56A8FA37DD25LL;
    unsigned long long b = 0x146C522CB8051LL;
    unsigned long long res = a ^ b;
    
    printf("0x%llx ^ 0x%llx = 0x%llx \n", a, b, res);

    unsigned int c = 0x28378u;
    printf("-(~0x%x) = 0x%x", c, -(~c));

    return 0;
}


