#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    long long a[n], sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i != n-1) sum += a[i];
    }
    long long sunuke = sum, arai = a[n-1];
    long long mi = abs(sunuke - arai);
    for(int i = n-2; i > 0; i--){
        mi = min(mi,abs(sunuke - arai));
        sunuke -= a[i]; arai += a[i];
    }   
    cout << mi << endl;
}
