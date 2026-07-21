#include <bits/stdc++.h>
typedef long long LL;
std::vector<int> vc;
int main()
{
    int N, R;
    std::cin >> N >> R;
    if (N >= 10)
    {
        std::cout<<R<<'\n';
    }else
    {
        int mu = 100 * (10 - N);
        std::cout<<(R + mu)<<'\n';
    }
    
}
