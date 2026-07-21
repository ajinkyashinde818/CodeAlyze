#include <bits/stdc++.h>
using namespace std;

void Main()
{
    int n, r;
    cin >> n >> r;
    if(n > 10)
        cout << r << endl;
    else
        cout << r + 100*(10-n) << endl;

    // R = Q - 100*(10-N)
    // Q = R + (100*(10-N))
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Main();
    return 0;
}
