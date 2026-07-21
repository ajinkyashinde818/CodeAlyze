#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n;

    long long min = 1LL<<60;
    long long v[200010];
    v[0] = 0;
    for(int i = 1; i <= n; ++i){
        long long a;
        cin >> a;
        v[i] = v[i-1] + a;
    }


    for(int i = 1; i < n; ++i){
        if(abs((long long)(v[n] - 2*v[i])) < min) min = abs((long long)(2*v[i]-v[n]));
    }

    cout << min;
    return 0;
}
