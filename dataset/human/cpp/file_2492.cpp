#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n;cin>>n;
    long long a[n];
    long long mini = 1e+9+9;
    long long res = 0;
    int minus = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0){
            a[i]*=(-1);
            minus++;
        }
        mini=min(mini,a[i]);
        res+=a[i];
        //cout<<a[i]<<endl;
    }
    if(minus%2==1)res-=mini*2;
    cout<<res<<endl;
}
