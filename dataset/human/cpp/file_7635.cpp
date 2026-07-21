#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long a[n];
    long long count=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        count+=a[i];
    }
    count-=a[n-1];
    long long com=a[n-1];
    long long ans=abs(count-com);
    for(int i=n-2;i>=1;i--){
        count-=a[i];
        com+=a[i];
        ans=min(ans,abs(count-com));
    }
    cout << ans << endl;
}
