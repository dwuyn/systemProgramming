#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

static int32_t rnd_range(int32_t lo, int32_t hi) {
    uint32_t r = ((uint32_t)rand() << 31) ^ (uint32_t)rand();
    uint32_t span = (uint32_t)(hi - lo) + 1ULL;
    r %= span;
    return (int32_t)lo + (int32_t)r;
}

static int32_t _k(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        exit(2);
    }
    char *end = NULL;
    int32_t u = strtoll(argv[1], &end, 10);
    if (*end != '\0') {
        fprintf(stderr, "Invalid input! \nUsage: %s <number>\n", argv[0]);
        exit(3);
    }
    return u;
}

int main(int argc, char **argv) {
    int32_t U = _k(argc, argv);
    srand((unsigned)time(NULL));
    int32_t R = rnd_range(-100000000L, 100000000L);
    if (U < -100000000L || U > 100000000L) exit(1);

    int32_t r1 = ((R ^ U) >> 22) & -1L;
    int32_t r2 = (((~R) ^ U) >> 22) & -1L;
    int32_t A = U | 260925L;
    if (A != ~(-9173822L)) exit(-1);
    int32_t B = A << 14;
    int32_t C = (r1 | r2) & B;

    if ((uint32_t)C == 0xFECF4000u) {
        fputs("You found your beloved pinanek\n", stdout);
    }
    return 0;
}
