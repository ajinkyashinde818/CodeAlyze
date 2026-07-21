#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    long long  a[N],c=0,b=0;
    for(int i=0;i<N;i++){
        cin >> a[i];
        c+=a[i];
    }
    
    long long ans=1000000000000000;
    for(int i=0;i<N-1;i++){
        c=c-a[i];
        b=b+a[i];
        ans = min(abs(c-b),ans);
    }
    cout << ans << endl;
}
