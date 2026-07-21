#include <bits/stdc++.h>

using namespace std;

int n,x;
long long sum = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int mn = 1e9 + 233;
    int minus = 0;
    for (int i = 1 ; i <= n ; i++)
        {
            cin >> x;
            sum += (long long )abs(x);
            if (x < 0 ) minus++;
             if ( abs(x) < mn ) mn = abs(x);
        }

    if (minus & 1)
        cout << sum - 2 * mn << endl;
    else 
        cout << sum << endl;
    return 0;
}
