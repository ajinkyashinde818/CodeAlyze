#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i;
    cin >> n;
    long long t, a[n], dif = 9999999999999;
    for(i=0; i<n; i++){
        cin >> t;
        if(i == 0){
            a[i] = t;
        }else{
            a[i] = a[i-1] + t;
        }
    }
    for(i=0; i<n-1; i++){
        dif = min(dif, abs(a[n-1]-2*a[i]));
    }
    cout << dif;
    return 0;
}
