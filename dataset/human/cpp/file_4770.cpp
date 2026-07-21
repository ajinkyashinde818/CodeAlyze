#include <iostream>

int GetRateModifier(int joinCount)
{
    if (joinCount >= 10)
    {
        return 0;
    }

    return 100 * (10 - joinCount);
}

int main()
{
    int joinCount = 0;
    std::cin >> joinCount;

    int dispRate = 0;
    std::cin >> dispRate;

    std::cout << dispRate + GetRateModifier(joinCount);
    return 0;
}
