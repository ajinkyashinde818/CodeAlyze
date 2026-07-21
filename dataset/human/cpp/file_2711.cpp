#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    vector <int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    long long sum = 0, mn = 1e9;
    int negative = 0, zero = 0;
    for(int i = 0; i < n; i++)
    {
        sum += abs(a[i]);
        if(mn > abs(a[i]) && a[i] != 0)
            mn = abs(a[i]);
        if(a[i] < 0)
            negative++;
        else if(a[i] == 0)
            zero++;
    }

    if(!zero && (negative & 1))
        sum -= (2 * mn);
    cout << sum << endl;
    return 0;
}
