#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,minus=0,minabs=1000000007; cin>>n;
    long long sum=0;
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0) minus++;
        minabs=min(minabs,abs(a[i]));
        sum+=abs(a[i]);
    }
    if(minus%2==0) cout<<sum<<endl;
    else cout<<sum-2*minabs<<endl;
}
