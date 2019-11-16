#include <inttypes.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
    for (unsigned i = 1; i <= 100; ++i) {
        unsigned fizz = ~(unsigned)!(i % 3) + 1;
        unsigned buzz = ~(unsigned)!(i % 5) + 1;

        unsigned fizzbuzz = fizz & buzz;

        printf((uintptr_t)"%s\n" & (fizz | buzz) | (uintptr_t)"%"PRIuPTR"\n" & ~(fizz | buzz),
            (uintptr_t)"fizz" & (fizz & ~buzz) |
            (uintptr_t)"buzz" & (buzz & ~fizz) |
            (uintptr_t)"fizzbuzz" & fizzbuzz |
            i & ~(fizz | buzz));
    }

    return 0;
}
