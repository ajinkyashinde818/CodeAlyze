#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll a[100050];
    ll sum = 0,amin = 1e12;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += llabs(a[i]);
        amin = min(amin, llabs(a[i]));
    }
    for(int i = 0;i < n-1;i++)
        if(a[i] < 0)a[i] = -a[i],a[i+1] = -a[i+1];
    if(a[n-1] < 0)sum -= amin * 2;
    cout << sum << endl;
}
