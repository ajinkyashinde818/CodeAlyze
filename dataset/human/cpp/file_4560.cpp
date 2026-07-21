#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>



void a(std::istream& in)
{
    int N, R;

    in >> N;
    in >> R;

    if (N >= 10)
    {
        std::cout << R;
        return;
    }

    std::cout << R + 100 * (10 - N);
}

int main(int, char* [])
{
    a(std::cin);
    return 0;
}
