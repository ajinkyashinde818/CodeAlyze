#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long x=0;
    int m=1000000000,hu=0;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        x+=abs(a[i]);
        if(a[i]<0)hu++;
        m=min(m,abs(a[i]));
    }
    if(hu%2)cout<<x-m*2<<endl;
    else cout<<x<<endl;
    return 0;
}
