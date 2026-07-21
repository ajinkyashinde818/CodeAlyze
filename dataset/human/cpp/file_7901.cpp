#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<ll> a(N), s1(N);
    ll s = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        s += a[i];
        s1[i] = s;
    }

    ll diff = 1e+10;
    for (int i = 0; i < N-1; i++) diff = min(diff, abs(s1[i] - (s-s1[i])));
    
    cout << diff << endl;
}
