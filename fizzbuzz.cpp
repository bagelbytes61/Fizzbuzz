#include <cstdint>
#include <iostream>
#include <type_traits>

template<uint32_t n>
struct fizz {
    static constexpr bool enabled = !(n % 3);
};

template<uint32_t n>
struct buzz {
    static constexpr bool enabled = !(n % 5);
};

template<uint32_t n>
struct fizzbuzz {
    template <typename t = fizz<n>, typename u = buzz<n>, std::enable_if_t<t::enabled && !u::enabled, int> = 0>
    static void go() {
        std::cout << "fizz" << '\n';

        fizzbuzz<n + 1>::go();
    }

    template <typename t = fizz<n>, typename u = buzz<n>, std::enable_if_t<u::enabled && !t::enabled, int> = 0>
    static void go() {
        std::cout << "buzz" << '\n';

        fizzbuzz<n + 1>::go();
    }

    template <typename t = fizz<n>, typename u = buzz<n>, std::enable_if_t<t::enabled && u::enabled, int> = 0>
    static void go() {
        std::cout << "fizzbuzz" << '\n';

        fizzbuzz<n + 1>::go();
    }

    template <typename t = fizz<n>, typename u = buzz<n>, std::enable_if_t<(!(t::enabled || u::enabled)), int> = 0>
    static void go() {
        std::cout << n << '\n';

        fizzbuzz<n + 1>::go();
    }
};

template<>
struct fizzbuzz<101> {
    static void go() {}
};


int main() {
    fizzbuzz<1>::go();

    return 0;
}
