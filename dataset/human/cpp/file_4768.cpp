#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

using ll = long long;

int main(void)
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
