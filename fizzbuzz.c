#include <inttypes.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
    for (size_t i = 1; i <= 100u; ++i) {
        const uintptr_t fizz = ~(uintptr_t)!(i % 3) + 1;
        const uintptr_t buzz = ~(uintptr_t)!(i % 5) + 1;

        const uintptr_t fizzbuzz = fizz & buzz;

        const char *fmt = (const char *)( ((uintptr_t)"%s\n" & (fizz | buzz)) | ((uintptr_t)"%"PRIuPTR"\n" & ~(fizz | buzz)));

        printf(fmt,
              ((uintptr_t)"fizz" & (fizz & ~buzz)) |
              ((uintptr_t)"buzz" & (buzz & ~fizz)) |
              ((uintptr_t)"fizzbuzz" & fizzbuzz)   |
              ((uintptr_t)i & ~(fizz | buzz)));
    }

    return 0;
}
