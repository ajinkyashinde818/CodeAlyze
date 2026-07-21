#include <iostream>

int main()
{
    int N;
    long long A[100000];
    std::cin >> N;

    bool zero = false;
    int minus = 0;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
        if (A[i] == 0)
        {
            zero = true;
        }
        else if (A[i] < 0)
        {
            minus++;
        }
    }

    long long ans = 0;
    if (zero || (minus % 2) == 0)
    {
        for (int i = 0; i < N; ++i)
        {
            if (A[i] < 0)
            {
                ans += A[i] * -1;
            }
            else
            {
                ans += A[i];
            }
        }
    }
    else
    {
        long long min = 1e9 + 1;
        for (int i = 0; i < N; ++i)
        {
            int a = A[i];
            if (a < 0)
            {
                a *= -1;
            }

            ans += a;
            if (a < min)
            {
                min = a;
            }
        }

        ans -= min * 2;
    }

    std::cout << ans << std::endl;

    return 0;
}
