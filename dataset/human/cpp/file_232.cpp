#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int R, G, B, N;
    std::cin >> R >> G >> B >> N;
    int a, b, c;
    std::vector<int> x;
    x.push_back(R);
    x.push_back(G);
    x.push_back(B);
    std::sort(x.begin(), x.end(), std::greater<int>());

    int Ri = 0, Gi = 0, Bi = 0;
    int sum = 0;

    for (int i = 0; i <= (N / x[0]); i++)
    {
        for (int j = 0; j <= (N - (i * x[0])) / x[1]; j++)
        {

            if ((N - (i * x[0] + j * x[1])) % x[2] == 0)
            {
                sum++;
            }
        }
    }
    std::cout << sum << std::endl;
}
