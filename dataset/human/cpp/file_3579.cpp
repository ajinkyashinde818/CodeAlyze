#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
const int MOD = 1000000007;
const int INF = 1e9;
typedef long long ll;

int main(){

    int n;
    cin >> n;
    vector<ll> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int count = 0;

    for(int i=0;i<n;i++){
        if(a[i]<0)count++;
    }

    for(int i=0;i<n;i++){
        a[i]=abs(a[i]);
    }

    sort(a.begin(),a.end());

    ll sum=0;
    for(int i=0;i<n;i++){
        if(count % 2 == 0){
            sum+=abs(a[i]);
        }
        else{
            if(i==0) sum-=a[i];
            else sum+=a[i];
        }
    }

    cout << sum << endl;
    
}
