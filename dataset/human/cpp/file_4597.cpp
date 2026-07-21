// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int n, r;
    
    cin >> n >> r;
    
    if (n >= 10) {
        cout << r << endl;
    } else {
        cout << r + 100 * (10 - n) << endl;
    }
    return 0;
}

// GCC reference:
//   https://gcc.gnu.org/

// C++ language references:
//   https://cppreference.com/
//   https://isocpp.org/
//   http://www.open-std.org/jtc1/sc22/wg21/

// Boost libraries references:
//   https://www.boost.org/doc/
