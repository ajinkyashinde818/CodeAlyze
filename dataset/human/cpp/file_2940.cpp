#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long a[100010],m=1e9+7,sum=0,c=0,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0) c++;
        m=min(m,abs(a[i]));
        sum+=abs(a[i]);
    }
    if(c%2==0) cout<<sum;
    else cout<<sum-2*m;
}
