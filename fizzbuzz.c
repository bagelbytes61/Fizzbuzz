#include <limits.h>
#include <stdio.h>

int main(void) {
    for (unsigned i = 1; i <= 100; ++i) {
        unsigned fizz = ~!(i % 3) + 1;
        unsigned buzz = ~!(i % 5) + 1;

        unsigned fizzbuzz = fizz & buzz;

        printf((uintptr_t)"%s\n" & (fizz | buzz) | (uintptr_t)"%u\n" & ~(fizz | buzz),
            (uintptr_t)"fizz" & ((fizz ^ buzz) & ~buzz) |
            (uintptr_t)"buzz" & ((buzz ^ fizz) & ~fizz) |
            (uintptr_t)"fizzbuzz" & fizzbuzz |
            i & ~(fizz | buzz));
    }

    return 0;
}
