#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <random>
#include <string>

using namespace std;

int main()
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    long long sum = 0;
    for(int i = 0;i * R <= N;i++)
    {
        for(int j = 0;j * G <= N; j++)
        {
            int t = N - i * R - j * G;
            if(t < 0)
            {
                continue;
            }
            if(t % B == 0)
            {
                sum++;
            }
        }
    }
    cout << sum << endl;

    return 0;
}
