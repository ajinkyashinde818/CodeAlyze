#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long a[n+1];
    long long b[n+1];
    a[0]=0;b[0]=0;
    for (int i=1; i<n+1; i++){
        long long x;
        cin >> x;
        a[i]=x;
        b[i]=b[i-1]+x;
    }
    long long ans=1e10;
    for (int i=1; i<n; i++){
        long long cand=abs(b[n]-2*b[i]);
        ans=min(ans,cand);
    }
    cout << ans << endl;
}
