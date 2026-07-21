#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
static const long long MAX = pow(10, 9);
int main()
{
    int N;
    std::vector<long long> A;
    std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        long long element;
        std::cin >> element;
        A.push_back(element);
    }

    long long  sumA = 0;
    int count = 0;
    long long add = 0;
    long long nearzero = MAX;
    for (int i = 0; i < N; ++i)
    {
        if (A[i] < 0)
        {
            ++count;
            sumA -= A[i];
            nearzero = std::min(nearzero, -A[i]);
        }
        else
        {
            sumA += A[i];
            nearzero = std::min(nearzero, A[i]);
        }
    }

    if (count % 2 != 0)
    {
        sumA -= 2 * nearzero;
    }
    std::cout << sumA << std::endl;
    return 0;
}
