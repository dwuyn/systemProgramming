#include <stdio.h>
#include <stdint.h>

int main() {
	char s[] = {0x31, 0x32, 0x33, 0x34};
	int a = 12312312;

    char *p = (char *)(uintptr_t)a;
    printf("pointer to a: %p \n", (void *)p);

    char *ps = s;
    ps[4] = '\0';
    printf("s = %s \n", ps);

    unsigned char *p_bytes = (unsigned char *)&ps;
    for (int i = 0; i < 4; i++)
        s[i] = p_bytes[i];

    printf("pointer to s: %p \n", (void *)ps);
    printf("s after writing 4 first bytes of pointer s to s:\n");
    for (int i = 0; i < 4; i++)
        printf("0x%x ", (unsigned char)s[i]);
    

	return 0;
}
