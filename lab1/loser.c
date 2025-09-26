#include <stdio.h>
#include <stdint.h>

int main() {
    int32_t base = -2313;

    // ~-2313 = 100100001000
    // L =   000000001001100
    // o =   000000001101111
    // s =   000000001110011
    // e =   000000001100101
    // r =   000000001110010
    // SPC = 000000000100000
    // u =   000000001110101
    // s =   000000001110011
    // e =   000000001100101
    // SPC = 000000000100000
    // L =   000000001001100
    // L =   000000001001100
    // M =   000000001001101
    
    putchar((~base >> 5) | 4);  // L
    putchar((~base >> 5) | 39); // o
    putchar((~base >> 7) | 97); // s 
    putchar((~base >> 6) | 65); // e
    putchar((~base >> 7) | 96); // r
    putchar((~base >> 7) | 97); // s 
    putchar((~base >> 6) & 32); // SPC
    putchar((~base >> 6) | 81); // u
    putchar((~base >> 7) | 97); // s 
    putchar((~base >> 6) | 65); // e
    putchar((~base >> 6) & 32); // SPC
    putchar((~base >> 5) | 4);  // L
    putchar((~base >> 5) | 4);  // L
    putchar((~base >> 5) | 5);  // M

    return 0;
}
