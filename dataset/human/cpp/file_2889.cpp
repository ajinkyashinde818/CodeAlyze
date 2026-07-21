#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    bool f = false;
    ll sum = 0;
    ll minv = 10000000000000;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += abs(v[i]);
        minv = min(minv, abs(v[i]));
        if (v[i] < 0)
        {
            cnt++;
        }
        else if (v[i]==0)
        {
            f = true;
        }
    }
    if(f || cnt%2==0)
    {
        cout << sum << endl;
        return 0;
    }
    else
    {
        cout << sum - 2 * minv << endl;
        return 0;
    }
}
